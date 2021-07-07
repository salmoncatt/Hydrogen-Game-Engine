#include "hfpch.h"

namespace HFR {

	std::vector<unsigned int> Util::VBOs = std::vector<unsigned int>();

	ULARGE_INTEGER Util::lastCPU = { 0 };
	ULARGE_INTEGER Util::lastSysCPU = { 0 };
	ULARGE_INTEGER Util::lastUserCPU = { 0 };
	HANDLE Util::self = nullptr;
	int Util::numProcessors = 0;
	double Util::lastPercent = 0;

	void Util::init() {
		SYSTEM_INFO sysInfo;
		FILETIME ftime, fsys, fuser;

		GetSystemInfo(&sysInfo);
		numProcessors = sysInfo.dwNumberOfProcessors;

		GetSystemTimeAsFileTime(&ftime);
		std::memcpy(&lastCPU, &ftime, sizeof(FILETIME));

		self = GetCurrentProcess();
		GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
		std::memcpy(&lastSysCPU, &fsys, sizeof(FILETIME));
		std::memcpy(&lastUserCPU, &fuser, sizeof(FILETIME));
	}

	unsigned int Util::generateVAO() {
		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		return VAO;
	}

	unsigned int Util::generateVBO() {
		unsigned int VBO;
		glGenBuffers(1, &VBO);
		VBOs.push_back(VBO);
		return VBO;
	}

	void Util::pushDataToVBO(const int& index, const int& size, const std::vector<float>& data) {
		unsigned int VBO = Util::generateVBO();
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(float) * size, 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Util::pushDataToIBO(const std::vector<unsigned int>& data, const unsigned int& IBO) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), &data[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void Util::deleteVBOs() {
		int vbos = 0;
		for (int i = 0; i < VBOs.size(); i++) {
			glDeleteBuffers(1, &VBOs[i]);
			vbos += 1;
		}
		HFR::Debug::systemSuccess("Successfully deleted " + std::to_string(vbos) + " VBOs");
	}

	std::string Util::readAsString(const std::string& filepath, const int& readmode) {
		std::ifstream file;

		if (readmode == HFR_NORMAL_READ)
			file = std::ifstream(filepath, std::ios_base::in);
		else if (readmode == HFR_BINARY_READ)
			file = std::ifstream(filepath, std::ios_base::in | std::ios_base::binary);
		else
			Debug::systemErr("Unkown read mode in file: " + filepath + ", HFR_NORMAL_READ or HFR_BINARY_READ");

		std::string line;
		std::string out = "";

		if (file.is_open()) {
			while (std::getline(file, line)) {
				out += line + "\n";
			}
			file.close();
		}
		else
			Debug::systemErr("Could not read file: " + filepath);

		return out;

	}

	bool Util::doesDirectoryExist(const std::string& directory) {
		struct stat result;

		if (stat(directory.c_str(), &result) != 0)
			return 0;
		else if (result.st_mode & S_IFDIR)
			return 1;
		else
			return 0;
	}

	bool Util::createDirectory(std::string path) {
		if (!doesDirectoryExist(path)) {
			//we need to do this folder by folder
			int success = 0;

			size_t index = path.find_first_of("/\\");
			while ((index = path.find_first_of("/\\", index + 1)) != std::string::npos) {
				//only doing this so no warnings
				success = _mkdir(path.substr(0, index).c_str());
			}

			//theres an extra one left behind
			if(path.substr(0, index).find_first_of("/\\") == std::string::npos)
				success = _mkdir(path.substr(0, index).c_str());

			if (success == 0) {
				Debug::systemSuccess("Created directory: " + path);
				return true;
			} else if (success == -1){
				Debug::systemErr("Couldn't create directory: " + path);
				return false;
			}
		}
		return false;
	}

	std::string Util::getDirectory(const int& mode) {
		std::string out;

		CHAR documentRawPath[MAX_PATH];
		HRESULT result = SHGetFolderPath(NULL, mode, NULL, SHGFP_TYPE_CURRENT, documentRawPath);

		if (result == S_OK)
			out = documentRawPath;
		else
			Debug::systemErr("Couldn't find directory: " + std::to_string(mode));

		return out;
	}

	std::string Util::getWorkingDirectory() {
		std::string out;
		TCHAR buffer[MAX_PATH];

		GetModuleFileName(NULL, buffer, MAX_PATH);

		return std::string(buffer).substr(0, std::string(buffer).find_last_of("\\/"));
	}

	void Util::writeAsString(const std::string& fileData, const std::string& filepath, const int& writemode) {
		std::ofstream file;

		createDirectory(removeNameFromFilePathAndName(filepath));

		if (writemode == HFR_NORMAL_WRITE)
			file = std::ofstream(filepath, std::ios_base::out);
		else if (writemode == HFR_BINARY_WRITE)
			file = std::ofstream(filepath, std::ios_base::out | std::ios_base::binary);
		else
			Debug::systemErr("Unkown read mode in file: " + filepath + ", HFR_NORMAL_READ or HFR_BINARY_READ");

		file << fileData;

		file.close();

		std::string mode = (writemode == HFR_NORMAL_WRITE) ? "HFR_NORMAL_WRITE" : "HFR_BINARY_WRITE";
		Debug::systemSuccess("Wrote file to: " + filepath + ", with mode: " + mode);
	}

	std::string Util::removeNameFromFilePathAndName(const std::string& path) {
		std::string out;

		size_t index = 0;
		index = path.find_last_of("/\\");

		if (index != std::string::npos) {
			//+1 to add \ at the end
			return path.substr(0, index + 1);
		}
		else
			return path;
	}

	std::string Util::removePathFromFilePathAndName(const std::string& path) {
		std::string out;

		size_t index = 0;
		index = path.find_last_of("/\\");

		if (index != std::string::npos) {
			return path.substr(index + 1);
		}
		else
			return path;
	}

	std::vector<unsigned char> Util::readAsUnsignedChar(const std::string& filepath, const int& readmode) {
		std::string data = readAsString(filepath, readmode);
		std::vector<unsigned char> out(data.begin(), data.end());
		return out;
	}

	long Util::getFileSize(const std::string& filepath) {
		
		std::ifstream file(filepath, std::ios::in);
		std::streampos fileSize = 0;

		if (file.is_open()) {
			fileSize = file.tellg();
			file.seekg(0, std::ios::end);

			fileSize = file.tellg() - fileSize;
		}
		else
			Debug::systemErr("Could not read file: " + filepath);

		file.close();

		return (long)fileSize;
	}

	void Util::compileShader(const int& ShaderID, const std::string& ShaderCode, const std::string& ShaderName) {
		const char* ShaderSource = ShaderCode.c_str();
		glShaderSource(ShaderID, 1, &ShaderSource, NULL);
		glCompileShader(ShaderID);

		int CompileCode = 0;
		glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &CompileCode);
		if (CompileCode != GL_TRUE) {
			char Error[1024];
			glGetShaderInfoLog(ShaderID, 1024, NULL, Error);
			std::string StringError = Error;
			Debug::systemErr("Compiling shader: " + ShaderName + " has failed with error: " + StringError);
			return;
		}
		Debug::systemSuccess("Compiling shader: " + ShaderName + " has succeeded", DebugColor::Blue);
	}

	void Util::linkAndValidateProgram(const int& ProgramID) {
		glLinkProgram(ProgramID);
		int CompileCode = 0;

		glGetProgramiv(ProgramID, GL_LINK_STATUS, &CompileCode);
		if (CompileCode != GL_TRUE) {
			char Error[1024];
			glGetProgramInfoLog(ProgramID, 1024, NULL, Error);
			std::string StringError = Error;
			Debug::systemErr("Linking Shader Program has failed with code: " + StringError);
			return;
		}

		glValidateProgram(ProgramID);

		glGetProgramiv(ProgramID, GL_VALIDATE_STATUS, &CompileCode);
		if (CompileCode != GL_TRUE) {
			char Error[1024];
			glGetProgramInfoLog(ProgramID, 1024, NULL, Error);
			std::string StringError = Error;
			Debug::systemErr("Validating Shader Program has failed with code: " + StringError);
			return;
		}
	}

	std::vector<Material> Util::loadMaterial(const std::string& filepath) {
		std::string filename = removePathFromFilePathAndName(filepath);
		std::ifstream file(filepath, std::ios::in);

		std::vector<Material> out;

		std::string line;

		int materialCount = 0;

		if (file.is_open()) {
			while (std::getline(file, line)) {
				if (line.substr(0, 7) == "newmtl ") {
					Material mat = Material();

					mat.name = line.substr(7);

					out.push_back(mat);

					materialCount += 1;
				}
				else if (line.substr(0, 3) == "Ka ") {
					if (materialCount > 0) {
						int index = materialCount - 1;

						std::istringstream data(line.substr(3));

						Vec3f color;
						data >> color.x >> color.y >> color.z;

						out[index].ambientColor = color;
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 4) == "	Ka ") {
					if (materialCount > 0) {
						int index = materialCount - 1;

						std::istringstream data(line.substr(4));

						Vec3f color;
						data >> color.x >> color.y >> color.z;

						out[index].ambientColor = color;
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 3) == "Kd ") {
					if (materialCount > 0) {
						int index = materialCount - 1;

						std::istringstream data(line.substr(3));

						Vec3f color;
						data >> color.x >> color.y >> color.z;

						out[index].diffuseColor = color;
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 4) == "	Kd ") {
					if (materialCount > 0) {
						int index = materialCount - 1;

						std::istringstream data(line.substr(4));

						Vec3f color;
						data >> color.x >> color.y >> color.z;

						out[index].diffuseColor = color;
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 3) == "Ks ") {
					if (materialCount > 0) {
						int index = materialCount - 1;

						std::istringstream data(line.substr(3));

						Vec3f color;
						data >> color.x >> color.y >> color.z;

						out[index].specularColor = color;
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 4) == "	Ks ") {
					if (materialCount > 0) {
						int index = materialCount - 1;

						std::istringstream data(line.substr(4));

						Vec3f color;
						data >> color.x >> color.y >> color.z;

						out[index].specularColor = color;
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 3) == "Ns ") {
					if (materialCount > 0) {
						int index = materialCount - 1;

						std::istringstream data(line.substr(3));

						float amount;
						data >> amount;

						out[index].specularExponent = amount;
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 4) == "	Ns ") {
					if (materialCount > 0) {
						int index = materialCount - 1;

						std::istringstream data(line.substr(4));

						float amount;
						data >> amount;

						out[index].specularExponent = amount;
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 7) == "map_Kd ") {
					//sometimes map_Kd has indented commands and sometimes they dont, wait a pain
					if (materialCount > 0) {
						int index = materialCount - 1;

 						out[index].diffuseMap = Texture(removeNameFromFilePathAndName(filepath) + line.substr(7));
						out[index].diffuseMap.create();
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 8) == "	map_Kd ") {
					//sometimes map_Kd has indented commands and sometimes they dont, wait a pain
					if (materialCount > 0) {
						int index = materialCount - 1;

						out[index].diffuseMap = Texture(removeNameFromFilePathAndName(filepath) + line.substr(8));
						out[index].diffuseMap.create();
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
			}
		}
		else {
			Debug::systemErr("Could not read material file: " + filename + ", at: " + filepath);
			return out;
		}

		Debug::systemSuccess("Loaded material: " + filename);

		return out;

	}

	std::vector<Mesh> Util::loadMesh(const std::string& filepath) {
		std::string filename = removePathFromFilePathAndName(filepath);
		FILE* file;
		errno_t result = fopen_s(&file, filepath.c_str(), "r");

		std::vector<Mesh> out;
		if (!file || result != 0) {
			Debug::systemErr("Could not read file: " + filepath);
			return out;
		}

		std::vector<Material> materials;

		std::vector<Vec2f> textureCoordBuffer;
		std::vector<Vec3f> vertexBuffer;
		std::vector<Vec3f> normalBuffer;

		//std::string buffer;

		char buffer[512];

		std::string line;

		unsigned int meshIndex = 0;

		long reserveSize = getFileSize(filepath) / 100;

		//0 = i/i/i, 1 = i/i 2 = i//i
		unsigned short faceIndexType = 0;

		//reserve size, makes loading a tiny bit faster
		vertexBuffer.reserve(reserveSize);
		textureCoordBuffer.reserve(reserveSize);
		normalBuffer.reserve(reserveSize);

		//file.read(buffer, length);
		while (fgets(buffer, 512, file) != NULL) {
			line = buffer;
			line.erase(line.end() - 1, line.end());
			std::string header = line.substr(0, 2);

			float data[3];

			if (line[0] != '#' && line[0] != 'o' && header != "f ") {
				char* currentPointer = strchr(_strdup(line.substr(line.find(' ')).data()), ' ');

				data[0] = strtof(++currentPointer, &currentPointer);
				data[1] = strtof(++currentPointer, &currentPointer);
				data[2] = strtof(++currentPointer, &currentPointer);
			}

			if (header == "v ") {
				vertexBuffer.push_back(Vec3f(data[0], data[1], data[2]));
			}
			else if (header == "vt") {
				textureCoordBuffer.push_back(Vec2f(data[0], data[1]));
			}
			else if (header == "vn") {
				normalBuffer.push_back(Vec3f(data[0], data[1], data[2]));
			}
			else if (header == "f ") {
				unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

				int matches = 0;

				switch (faceIndexType) {

				case(0):
					//vertices, uvs, normals
					matches = sscanf_s(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

					if (matches != 9) {
						//vertices uvs
						matches = sscanf_s(line.c_str(), "f %d/%d %d/%d %d/%d", &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2]);

						if (matches != 6) {
							//vertices normals
							matches = sscanf_s(line.c_str(), "f %d//%d %d//%d %d//%d", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);

							if (matches != 6) {
								Debug::systemErr("Model: " + filepath + " has incorrect formatting, try different exporting options");
								return out;
							}
							else
								faceIndexType = 2;
						}
						else
							faceIndexType = 1;
					}

					break;

				case(1):
					//vertices uvs
					matches = sscanf_s(line.c_str(), "f %d/%d %d/%d %d/%d", &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2]);

					if (matches != 6) {
						//vertices, uvs, normals
						matches = sscanf_s(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

						if (matches != 9) {
							//vertices normals
							matches = sscanf_s(line.c_str(), "f %d//%d %d//%d %d//%d", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);

							if (matches != 6) {
								Debug::systemErr("Model: " + filepath + " has incorrect formatting, try different exporting options");
								return out;
							}
							else
								faceIndexType = 2;
						}
						else
							faceIndexType = 0;
					}

					break;

				case(2):
					//vertices normals
					matches = sscanf_s(line.c_str(), "f %d//%d %d//%d %d//%d", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);

					if (matches != 6) {
						//vertices, uvs, normals
						matches = sscanf_s(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

						if (matches != 9) {
							//vertices uvs
							matches = sscanf_s(line.c_str(), "f %d/%d %d/%d %d/%d", &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2]);

							if (matches != 6) {
								Debug::systemErr("Model: " + filepath + " has incorrect formatting, try different exporting options");
								return out;
							}
							else
								faceIndexType = 1;
						}
						else
							faceIndexType = 0;
					}

					break;
				}

				//in case of no mtl, i have to make the meshes as i go
				if (out.size() <= meshIndex)
					out.push_back(Mesh());

				switch (faceIndexType) {

				case(0):
					for (int i = 0; i < 3; i++) {
						//add data to current mesh

						//vertex data
						Vec3f vertex = vertexBuffer[vertexIndex[i] - 1];
						out[meshIndex].vertices.push_back(vertex.x);
						out[meshIndex].vertices.push_back(vertex.y);
						out[meshIndex].vertices.push_back(vertex.z);

						//texture coords
						Vec2f uv = textureCoordBuffer[uvIndex[i] - 1];

						out[meshIndex].texturecoords.push_back(uv.x);
						out[meshIndex].texturecoords.push_back(1 - uv.y);

						//normals
						Vec3f normal = normalBuffer[normalIndex[i] - 1];

						out[meshIndex].normals.push_back(normal.x);
						out[meshIndex].normals.push_back(normal.y);
						out[meshIndex].normals.push_back(normal.z);
					}

					break;

				case(1):

					for (int i = 0; i < 3; i++) {
						//add data to current mesh

						//vertex data
						Vec3f vertex = vertexBuffer[vertexIndex[i] - 1];
						out[meshIndex].vertices.push_back(vertex.x);
						out[meshIndex].vertices.push_back(vertex.y);
						out[meshIndex].vertices.push_back(vertex.z);

						//texture coords
						Vec2f uv = textureCoordBuffer[uvIndex[i] - 1];

						out[meshIndex].texturecoords.push_back(uv.x);
						out[meshIndex].texturecoords.push_back(1 - uv.y);
					}

					break;

				case(2):

					for (int i = 0; i < 3; i++) {
						//add data to current mesh

						//vertex data
						Vec3f vertex = vertexBuffer[vertexIndex[i] - 1];
						out[meshIndex].vertices.push_back(vertex.x);
						out[meshIndex].vertices.push_back(vertex.y);
						out[meshIndex].vertices.push_back(vertex.z);

						//normals
						Vec3f normal = normalBuffer[normalIndex[i] - 1];

						out[meshIndex].normals.push_back(normal.x);
						out[meshIndex].normals.push_back(normal.y);
						out[meshIndex].normals.push_back(normal.z);
					}

					break;


				}



			}
			else if (header == "s ") {
				//smooth shading or something here
				//bool smoothshading = true;
			}
			else if (line.substr(0, 7) == "usemtl ") {
				bool found = false;
				for (int i = 0; i < materials.size(); i++) {
					if (line.substr(7) == materials[i].name.c_str()) {
						meshIndex = i;
						out[meshIndex].material = materials[i];
						found = true;
						break;
					}
				}

				//just a little helper for materials
				if (!found) {
					Debug::systemErr("Couldn't find material: " + line.substr(7));
				}

			}
			else if (line.substr(0, 7) == "mtllib ") {
				std::string materialPath = removeNameFromFilePathAndName(filepath) + line.substr(7);
				std::vector<Material> loadedMaterials = loadMaterial(materialPath);

				materials.insert(materials.end(), loadedMaterials.begin(), loadedMaterials.end());

				out = std::vector<Mesh>(materials.size(), Mesh());
				out.reserve(materials.size());
			}
		}

		fclose(file);

		if (!(materials.size() > 0))
			Debug::systemErr("Warning object file: " + filename + ", has no materials. Meaning it will have null textures and stuff");

		Debug::systemSuccess("Loaded object: " + filename);
		Debug::newLine();

		return out;
	}



	std::vector<unsigned char> Util::convertPixelsToRawData(const std::vector<std::vector<Pixel>>& pixeldata) {
		std::vector<unsigned char> out;

		for (int x = 0; x < pixeldata.size(); x++) {
			for (int y = 0; y < pixeldata[x].size(); y++) {
				Pixel pixel = pixeldata[x][y];

				out.push_back(pixel.r);
				out.push_back(pixel.g);
				out.push_back(pixel.b);
				out.push_back(pixel.a);
			}
		}

		return out;
	}

	std::string Util::getCPU() {
		std::string out;
		int CPUInfo[4] = { -1 };
		char CPUBrandString[65];
		__cpuid(CPUInfo, 0x80000000);
		unsigned int nExIds = CPUInfo[0];

		memset(CPUBrandString, 0, sizeof(CPUBrandString));

		// Get the information associated with each extended ID.
		for (unsigned int i = 0x80000000; i <= nExIds; ++i)
		{
			__cpuid(CPUInfo, i);
			// Interpret CPU brand string.
			if (i == 0x80000002)
				std::memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
			else if (i == 0x80000003)
				std::memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
			else if (i == 0x80000004)
				std::memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
		}

		CPUBrandString[64] = '\0';

		out = std::string(CPUBrandString);

		return out;
	}

	double Util::getCPUusage() {
		FILETIME ftime, fsys, fuser;
		ULARGE_INTEGER now, sys, user;
		double percent;

		GetSystemTimeAsFileTime(&ftime);
		std::memcpy(&now, &ftime, sizeof(FILETIME));

		GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
		std::memcpy(&sys, &fsys, sizeof(FILETIME));
		std::memcpy(&user, &fuser, sizeof(FILETIME));
		percent = (double)(sys.QuadPart - lastSysCPU.QuadPart) +
			(user.QuadPart - lastUserCPU.QuadPart);
		percent /= (now.QuadPart - lastCPU.QuadPart);
		percent /= numProcessors;
		lastCPU = now;
		lastUserCPU = user;
		lastSysCPU = sys;

		if (percent > 0 && percent < 900) {
			lastPercent = percent / 15;
			return percent / 15;
		}
		else if (percent > 900)
			return 1;
		else
			return lastPercent;
	}

	//in megabytes
	double Util::getRAMusage() {
		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);
		//DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;

		PROCESS_MEMORY_COUNTERS_EX pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
		SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;

		return (double)virtualMemUsedByMe / 1048576;
	}

	void Util::listFilesInFolder(const std::string& path) {
		DIR* dir;

		struct dirent* ent;

		if ((dir = opendir(HFR_SCRIPTS.c_str())) != NULL) {

			Debug::systemLog("Printing files at path: " + path);
			Debug::newLine();

			while ((ent = readdir(dir)) != NULL) {
				std::string file = ent->d_name;

				Debug::log(file);
			}

			closedir(dir);
		}
		else
			Debug::systemErr("Couldn't load folder: " + path);

	}

	void Util::toUpper(std::string& string) {
		int i = 0;
		while (string[i]) {
			string[i] = (char)toupper(string[i]);
			i += 1;
		}
	}

}