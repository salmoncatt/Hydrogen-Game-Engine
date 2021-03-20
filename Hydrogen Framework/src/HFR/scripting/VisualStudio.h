
#ifndef HFR_VISUAL_STUDIO_HEADER_INCLUDE
#define HFR_VISUAL_STUDIO_HEADER_INCLUDE

#include HFR_API



namespace HFR {

	class DLL_API VisualStudio {
	private:

		static std::string hFile;
		static std::string cppFile;

	public:
		static void openVisualStudio(const std::string& solutionPath);
		static void addScriptToProject(const std::string& projectPath, const std::string& namespaceName, const std::string& scriptName);

	};


}


#endif