#include "hpch.h"
#include "Util.h"
#include "Debug.h"
#include "HGE/math/vectors/Vec2.h"
#include "HGE/math/vectors/Vec3.h"
#include "HGE/graphics/image/Pixel.h"
#include "HGE/ECS/components/Mesh.h"
#include "HGE/ECS/components/Material.h"
#include "time/Profiler.h"

namespace HGE {

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


	void Util::test(const std::string& filepath, const std::string& filename) {
		std::ifstream file(filepath + filename, std::ios::in);

		//const unsigned int length = 8192;
		//char buffer[length];

		//file.rdbuf()->pubsetbuf(buffer, length);
		//file.open(filepath + filename, std::ios::binary);

		std::vector<Mesh> out;
		std::vector<Material> materials;

		std::vector<Vec2f> textureCoordBuffer;
		std::vector<Vec3f> vertexBuffer;
		std::vector<Vec3f> normalBuffer;

		std::string buffer;

		HGE::string line;

		unsigned int meshIndex = 0;

		long reserveSize = getFileSize(filepath + filename) / 100;

		//reserve size, makes loading a tiny bit faster
		vertexBuffer.reserve(reserveSize);
		textureCoordBuffer.reserve(reserveSize);
		normalBuffer.reserve(reserveSize);

		if (file.is_open()) {
			//file.read(buffer, length);
			while (std::getline(file, buffer)) {
				//line = buffer;
				//line = line.substr(0, line.find("\n"));
				HGE::string header = line.substr(0, 2);

				/*if (line.substr(0, 7) == "mtllib ") {
					std::vector<Material> loadedMaterials = loadMaterial(filepath, line.substr(7));

					materials.insert(materials.end(), loadedMaterials.begin(), loadedMaterials.end());

					out = std::vector<Mesh>(materials.size(), Mesh());
					out.reserve(materials.size());
				}
				else*/ if (header == "v ") {
					string vertex = line.substr(2);

					vector<string> vertices = vector<string>();

					vertices = vertex.split(' ');
					
					vertexBuffer.push_back(Vec3f(toFloat(vertices[0]), toFloat(vertices[1]), toFloat(vertices[2])));
				}
				else if (header == "vt") {
					string textureCoord = line.substr(3);

					vector<string> textureCoords = vector<string>();

					textureCoords = textureCoord.split(' ');

					textureCoordBuffer.push_back(Vec2f(toFloat(textureCoords[0]), toFloat(textureCoords[1])));
				}
				else if (header == "vn") {
					string normal = line.substr(2);

					vector<string> normals = vector<string>();

					normals = normal.split(' ');

					normalBuffer.push_back(Vec3f(toFloat(normals[0]), toFloat(normals[1]), toFloat(normals[2])));
				}
				else if (header == "f ") {
					//TODO: add more than just: f i/i/i i/i/i i/i/i
					unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

					//vertices, uvs, normals
					int matches = sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

					//in case of no mtl, i have to make the meshes as i go
					if (out.size() <= meshIndex)
						out.push_back(Mesh());

					if (matches == 9) {
						for (int i = 0; i < 3; i++) {
							//add data to current mesh

							//vertex data
							Vec3f vertex = vertexBuffer[0];
							out[meshIndex].vertices.push_back(vertex.x);
							out[meshIndex].vertices.push_back(vertex.y);
							out[meshIndex].vertices.push_back(vertex.z);

							//texture coords
							Vec2f uv = Vec2f();

							out[meshIndex].texturecoords.push_back(uv.x);
							out[meshIndex].texturecoords.push_back(1 - uv.y);

							//normals
							Vec3f normal = Vec3f();

							out[meshIndex].normals.push_back(normal.x);
							out[meshIndex].normals.push_back(normal.y);
							out[meshIndex].normals.push_back(normal.z);
						}

					}
					else {

						//vertices uvs
						matches = sscanf(line.c_str(), "f %d/%d %d/%d %d/%d", &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2]);

						if (matches == 6) {
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
						}
						else {

							//vertices normals
							matches = sscanf(line.c_str(), "f %d//%d %d//%d %d//%d", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);

							if (matches == 6) {
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
							}
							else {
								Debug::systemErr("Model: " + filepath + " has incorrect formatting, try different exporting options");
								//return std::vector<Mesh>();
							}
						}
					}

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
					if (!found)
						Debug::systemErr(("Couldn't find material: " + line.substr(7)).c_str());

				}
			}
			file.close();
		}
		else
			Debug::systemErr("Could not read file: " + filepath + filename);

		if (!(materials.size() > 0))
			Debug::systemErr("Warning object file: " + filename + ", has no materials. Meaning it will have null textures and stuff");

		Debug::systemSuccess("Loaded object: " + filename);
		Debug::newLine();

		
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
		HGE::Debug::systemSuccess("Successfully deleted " + std::to_string(vbos) + " VBOs");
	}

	std::string Util::readAsString(const std::string& filepath, const int& readmode) {
		std::ifstream file;

		if (readmode == HGE_NORMAL_READ)
			file = std::ifstream(filepath, std::ios_base::in);
		else if (readmode == HGE_BINARY_READ)
			file = std::ifstream(filepath, std::ios_base::in | std::ios_base::binary);
		else
			Debug::systemErr("Unkown read mode in file: " + filepath + ", HGE_NORMAL_READ or HGE_BINARY_READ");

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

	double Util::random(const int& smallest, const int& largest) {
		return ((rand() % largest) - (double)smallest);
	}

	std::vector<Material> Util::loadMaterial(const std::string& filepath, const std::string& filename) {
		std::ifstream file(filepath + filename, std::ios::in);

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
				else if (line.substr(0, 3) == "Kd ") {
					if (materialCount > 0) {
						int index = materialCount - 1;

						std::istringstream data(line.substr(3));

						Vec3f color;
						data >> color.x >> color.y >> color.z;

						out[index].albedoColor = color;
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

						out[index].albedoColor = color;
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 7) == "map_Kd ") {
					//sometimes map_Kd has indented commands and sometimes they dont, wait a pain
					if (materialCount > 0) {
						int index = materialCount - 1;

						out[index].albedoTexture = Texture(filepath + line.substr(7));
						out[index].albedoTexture.create();
					}
					else {
						Debug::systemErr("Loading material: " + filepath + ", has failed because trying to add material properties without having (newmtl) command found");
					}
				}
				else if (line.substr(0, 8) == "	map_Kd ") {
					//sometimes map_Kd has indented commands and sometimes they dont, wait a pain
					if (materialCount > 0) {
						int index = materialCount - 1;

						out[index].albedoTexture = Texture(filepath + line.substr(8));
						out[index].albedoTexture.create();
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

	std::vector<Mesh> Util::loadMesh(const std::string& filepath, const std::string& objname) {
		std::ifstream file(filepath + objname, std::ios::in);

		std::vector<Mesh> out;
		std::vector<Material> materials;

		std::vector<Vec2f> textureCoordBuffer;
		std::vector<Vec3f> vertexBuffer;
		std::vector<Vec3f> normalBuffer;

		std::string line;

		unsigned int meshIndex = 0;

		long reserveSize = getFileSize(filepath + objname) / 100;
		
		//reserve size, makes loading a tiny bit faster
		vertexBuffer.reserve(reserveSize);
		textureCoordBuffer.reserve(reserveSize);
		normalBuffer.reserve(reserveSize);
		
		if (file.is_open()) {
			while (std::getline(file, line)) {
				std::string header = line.substr(0, 2);

				if (line.substr(0, 7) == "mtllib ") {
					std::vector<Material> loadedMaterials = loadMaterial(filepath, line.substr(7));
					
					materials.insert(materials.end(), loadedMaterials.begin(), loadedMaterials.end());
					
					out = std::vector<Mesh>(materials.size(), Mesh());
					out.reserve(materials.size());
				}
				else if (header == "v ") {
					std::istringstream v(line.substr(2));

					float x, y, z;
					v >> x >> y >> z;
					vertexBuffer.push_back(Vec3f(x, y, z));
				}
				else if (header == "vt") {
					std::istringstream vt(line.substr(3));

					float x, y;
					vt >> x >> y;
					textureCoordBuffer.push_back(Vec2f(x, y));
				}
				else if (header == "vn") {
					std::istringstream vn(line.substr(3));

					float x, y, z;
					vn >> x >> y >> z;
					normalBuffer.push_back(Vec3f(x, y, z));
				}
				else if (header == "f ") {
					//TODO: add more than just: f i/i/i i/i/i i/i/i
					unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

					//vertices, uvs, normals
					int matches = sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

					//in case of no mtl, i have to make the meshes as i go
					if (out.size() <= meshIndex)
						out.push_back(Mesh());

					if (matches == 9) {
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

					}
					else {

						//vertices uvs
						matches = sscanf(line.c_str(), "f %d/%d %d/%d %d/%d", &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2]);

						if (matches == 6) {
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
						}
						else {

							//vertices normals
							matches = sscanf(line.c_str(), "f %d//%d %d//%d %d//%d", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);

							if (matches == 6) {
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
							}
							else {
								Debug::systemErr("Model: " + filepath + " has incorrect formatting, try different exporting options");
								return std::vector<Mesh>();
							}
						}
					}

				}
				else if (line.substr(0, 7) == "usemtl ") {
					bool found = false;
					for (int i = 0; i < materials.size(); i++) {
						if (line.substr(7) == materials[i].name) {
							meshIndex = i;
							out[meshIndex].material = materials[i];
							found = true;
							break;
						}
					}

					//just a little helper for materials
					if(!found)
					Debug::systemErr("Couldn't find material: " + line.substr(7));

				}
			}
			file.close();
		}
		else
			Debug::systemErr("Could not read file: " + filepath + objname);

		if (!(materials.size() > 0))
			Debug::systemErr("Warning object file: " + objname + ", has no materials. Meaning it will have null textures and stuff");

		Debug::systemSuccess("Loaded object: " + objname);
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
		DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;

		PROCESS_MEMORY_COUNTERS_EX pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
		SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;

		return (double)virtualMemUsedByMe / 1048576;
	}


}