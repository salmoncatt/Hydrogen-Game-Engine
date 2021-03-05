#include "hpch.h"
#include "ScriptManager.h"
#include "HGE/ECS/components/NativeScript.h"
#include "HGE/util/Debug.h"


namespace HGE {

	std::unordered_map<std::string, std::string> ScriptManager::scriptPathToName{};
	std::unordered_map<std::string, GameObject*> ScriptManager::scriptNameToScript {};
	std::unordered_map<size_t, std::string> ScriptManager::numberToPath{0};
	size_t ScriptManager::scriptAmount = 1;


	void ScriptManager::loadScriptFromDLL(const std::string& path, const std::string& _name, const bool& supressError) {
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

		GameObject* out = createScript();

		std::string name = _name.substr(0, _name.length() - 4);

		if (scriptPathToName.find(path) == scriptPathToName.end() && scriptNameToScript.find(name) == scriptNameToScript.end()) {
			scriptPathToName[path] = name;
			numberToPath[scriptAmount] = path;
			scriptNameToScript[name] = out;

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
		checkForScripts(true);
	}

	void ScriptManager::checkForScripts(const bool& supressError) {
		DIR* dir;

		struct dirent* ent;

		if ((dir = opendir(HGE_SCRIPTS.c_str())) != NULL) {
			
			while ((ent = readdir(dir)) != NULL) {
				std::string file = ent->d_name;

				if (file.find(".dll") != std::string::npos)
					loadScriptFromDLL(HGE_SCRIPTS + file, file, supressError);
			}

			closedir(dir);
		}
		else
			Debug::systemErr("Couldn't load scripts folder wtf");
	}

	void ScriptManager::close() {
		for (size_t i = 1; i < scriptAmount; i++) {
			delete scriptNameToScript[scriptPathToName[numberToPath[i]]];
			Debug::systemSuccess("Deleted script: " + scriptPathToName[numberToPath[i]], DebugColor::Blue);
		}
	}

	GameObject* ScriptManager::getScript(const std::string& name) {
		return scriptNameToScript[scriptPathToName[name]];
	}

}