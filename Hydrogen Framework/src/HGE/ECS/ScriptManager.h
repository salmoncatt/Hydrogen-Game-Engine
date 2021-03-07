
#ifndef HGE_SCRIPT_MANAGER_HEADER_INCLUDE
#define HGE_SCRIPT_MANAGER_HEADER_INCLUDE

#include HGE_API
#define HGE_SCRIPT_MANAGER_UPDATE_DELAY 2

namespace HGE {

	struct GameObject;

	class DLL_API ScriptManager {
	private:
		static size_t scriptAmount;
		static double timeElapsed;

		static bool loadDllFromFolder(const std::string& path, const bool& supressError);

	public:
		static std::unordered_map<size_t, std::string> numberToPath;
		static std::unordered_map<std::string, std::string> scriptPathToName;
		static std::unordered_map<std::string, GameObject* (__stdcall*)()> scriptNameToScript;
		static std::unordered_map<std::string, HINSTANCE> scriptNameToHandle;

		static void loadScriptFromDLL(const std::string& path, const std::string& name, const bool& supressError);
		static void init();
		static void close();
		static void update();
		static void checkForScripts(const bool& supressError);
		static size_t getAmountOfScripts();
		static GameObject* instantiateScript(const std::string& name);
		static bool checkScript(const std::string& name);

	};

}


#endif
