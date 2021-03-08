
#ifndef HGE_PROJECT_MANAGER_HEADER_INCLUDE
#define HGE_PROJECT_MANAGER_HEADER_INCLUDE

#include HGE_API

namespace HGE {

	class DLL_API ProjectManager {
	public:

		//comes with builtin project
		static void createMSVCSolution(const std::string& solutionName, const std::string& projectName, const std::string& outputPath);
		static void createMSVCProject(const std::string& projectName, const std::string& outputPath);

		static void createEngineProject(const std::string& solutionName, const std::string& projectName, const std::string& outputPath);

	};

}

#endif

