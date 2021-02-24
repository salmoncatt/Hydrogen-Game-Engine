
#ifndef HGE_UTIL_INCLUDE
#define HGE_UTIL_INCLUDE

#include HGE_API

namespace HGE{

	class Pixel;
	class Mesh;
	class Pixel;
	class Mesh;
	class Texture;
	struct Material;

	class DLL_API Util {
	private:
		//for cpu usage calcs
		static ULARGE_INTEGER lastCPU;  
		static ULARGE_INTEGER lastSysCPU;
		static ULARGE_INTEGER lastUserCPU;

		static int numProcessors;
		static HANDLE self;
		static double lastPercent;

	public:

		static void init();

		//opengl stuff
		static std::vector<unsigned int> VBOs;
		static unsigned int generateVAO();
		static unsigned int generateVBO();
		static void pushDataToVBO(const int& index, const int& size, const std::vector<float>& data);
		static void pushDataToIBO(const std::vector<unsigned int>& data, const unsigned int& IBO);
		static void deleteVBOs();

		//opengl shader stuff
		static void compileShader(const int& shaderID, const std::string& shaderCode, const std::string& shaderName);
		static void linkAndValidateProgram(const int& programID);

		//serialization stuff
		static long getFileSize(const std::string& filepath);
		static std::string readAsString(const std::string& filepath, const int& readmode);
		static std::vector<unsigned char> readAsUnsignedChar(const std::string& filepath, const int& readmode);

		//static void test(const std::string& filepath, const std::string& filename);
		static std::vector<Mesh> loadMesh(const std::string& filepath, const std::string& objname);
		static std::vector<Material> loadMaterial(const std::string& filepath, const std::string& filename);

		//other
		static double random(const int& smallest, const int& largest);

		static std::string getCPU();
		static double getCPUusage();
		static double getRAMusage();

		template<typename Base, typename T>
		static inline bool instanceOf(const T) {
			return std::is_base_of<Base, T>::value;
		}

		//static void sendWindowsNotification();

		static std::vector<unsigned char> convertPixelsToRawData(const std::vector<std::vector<Pixel>>& pixeldata);/*
		static std::vector<unsigned char> flipRGBimageData(const std::vector<unsigned char>& data);
		static std::vector<unsigned char> flipRGBAimageData(const std::vector<unsigned char>& data);*/
	};

}

#endif
