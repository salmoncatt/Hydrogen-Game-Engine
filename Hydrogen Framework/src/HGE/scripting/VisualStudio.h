
#ifndef HGE_VISUAL_STUDIO_HEADER_INCLUDE
#define HGE_VISUAL_STUDIO_HEADER_INCLUDE

#include HGE_API



namespace HGE {

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