#include "hfpch.h"

namespace HFR {

	std::unordered_map<std::string, std::string> ScriptManager::scriptPathToName{};
	std::unordered_map<std::string, GameObject* (__stdcall*)()> ScriptManager::scriptNameToScript{};
	std::unordered_map<size_t, std::string> ScriptManager::numberToPath{0};
	std::unordered_map<std::string, HINSTANCE> ScriptManager::scriptNameToHandle{};

	size_t ScriptManager::scriptAmount = 1;
	double ScriptManager::timeElapsed = 0;


	void ScriptManager::loadScriptFromDLL(const std::string& path, const std::string& name, const bool& supressError) {
		//credits to https://www.gamasutra.com/blogs/ZacHills/20170406/295378/Scripting_with_C.php bc idk how tf to do this

		HINSTANCE dllHandle = LoadLibraryA(path.c_str());

		if (!dllHandle) {
			Debug::systemErr("Couldn't load dll file containing scripts at: " + path);
		}

		typedef GameObject* (__stdcall* scriptPointer)();

		scriptPointer createScript = (scriptPointer)GetProcAddress(dllHandle, "CreateScript");

		if (!createScript) {
			Debug::systemErr("Couldn't find the create function of a script in the dll file containing scripts at: " + path + "(Check if there is an export function for the script)");
		}

		if (scriptPathToName.find(path) == scriptPathToName.end() && scriptNameToScript.find(name) == scriptNameToScript.end()) {
			scriptPathToName[path] = name;
			numberToPath[scriptAmount] = path;
			scriptNameToScript[name] = createScript;
			scriptNameToHandle[name] = dllHandle;

			Debug::systemSuccess("Loaded script: " + name, DebugColor::Blue);
			scriptAmount += 1;
		}
		else {
			if(!supressError)
			Debug::systemErr("Already loaded script file: " + path + ", or already loaded script with name: " + name);
		}
	}

	void ScriptManager::init() {
		checkForScripts(false);
	}

	void ScriptManager::update() {
		ProfileMethod("ScriptManager update");
		timeElapsed += Time::getDeltaTime();

		if (timeElapsed >= HFR_SCRIPT_MANAGER_UPDATE_DELAY) {
			timeElapsed = 0;
			checkForScripts(true);
		}
	}

	void ScriptManager::checkForScripts(const bool& supressError) {
		
		if(!loadDllFromFolder(HFR_SCRIPTS, supressError))
			Debug::systemErr("Couldn't load scripts folder wtf");
	}

	void ScriptManager::close() {
		for (size_t i = 1; i < scriptAmount; i++) {
			FreeLibrary(scriptNameToHandle[scriptPathToName[numberToPath[i]]]);
			Debug::systemSuccess("Deleted script: " + scriptPathToName[numberToPath[i]], DebugColor::Blue);
		}
	}

	GameObject* ScriptManager::instantiateScript(const std::string& name) {
		if (scriptNameToScript.find(name) != scriptNameToScript.end()) {
			return scriptNameToScript[name]();
		}
		else {
			Debug::systemErr("No script found of name: " + name);
			return nullptr;
		}
	}

	bool ScriptManager::checkScript(const std::string& name) {
		return (scriptNameToScript.find(name) != scriptNameToScript.end());
	}

	bool ScriptManager::loadDllFromFolder(const std::string& path, const bool& supressError) {
		DIR* dir;

		struct dirent* ent;

		if ((dir = opendir(path.c_str())) != NULL) {

			while ((ent = readdir(dir)) != NULL) {
				std::string file = ent->d_name;

				if (file.find(".") != std::string::npos) {
					if (file.find(".dll") != std::string::npos) {
						//shows whether in _D debug mode or _R release mode (they cant work in opposite modes)
						std::string modeIdentification = file.substr(file.find(".dll") - 2, 2);

						//get rid of .dll and _R or _D at end of name
						std::string name = file.substr(0, file.find(".dll") - 2);
#ifdef _DEBUG
						if (modeIdentification == "_D")
							loadScriptFromDLL(path + file, name, supressError);
						else if (!supressError && modeIdentification != "_R")
							Debug::systemErr("Couldn't load script dll: " + file + ", because it doesn't have debug identification, it should be: scriptname_D.dll. At path: " + path);
#else
						if (modeIdentification == "_R")
							loadScriptFromDLL(path + file, name, supressError);
						else if (!supressError && modeIdentification != "_D")
							Debug::systemErr("Couldn't load script dll: " + file + ", because it doesn't have release identification, it should be: scriptname_R.dll. At path: " + path);
#endif
					}
				}
				else {
					//we have found a folder or a blank file
					loadDllFromFolder(path + file + "/", supressError);
				}

			}

			closedir(dir);
			return true;
		}
		else
			return false;
	}

}