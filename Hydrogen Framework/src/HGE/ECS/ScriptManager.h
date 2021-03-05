
#ifndef HGE_SCRIPT_MANAGER_HEADER_INCLUDE
#define HGE_SCRIPT_MANAGER_HEADER_INCLUDE

#include HGE_API

namespace HGE {

	struct GameObject;

	class DLL_API ScriptManager {
	private:
		static size_t scriptAmount;
	public:
		static std::unordered_map<size_t, std::string> numberToPath;
		static std::unordered_map<std::string, std::string> scriptPathToName;
		static std::unordered_map<std::string, GameObject*> scriptNameToScript;

		static void loadScriptFromDLL(const std::string& path, const std::string& name, const bool& supressError);
		static void init();
		static void close();
		static void update();
		static void checkForScripts(const bool& supressError);
		static size_t getAmountOfScripts();
		static GameObject* getScript(const std::string& name);

	};

}


#endif
