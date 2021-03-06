
#ifndef HGE_NATIVE_SCRIPT_HEADER_INCLUDE
#define HGE_NATIVE_SCRIPT_HEADER_INCLUDE

#include HGE_API
#include "HGE/ECS/ECS.h"
#include "HGE/ECS/GameObject.h"
#include "HGE/ECS/ScriptManager.h"

#define HGE_MAX_SCRIPTS 100

using Script = HGE::GameObject;

namespace HGE {

	struct DLL_API NativeScript {
		std::unordered_map<unsigned int, std::string> nameToScriptIndex{};
		unsigned int scriptIndex = 0;
		std::array<GameObject*, HGE_MAX_SCRIPTS> scripts{nullptr};

		GameObject* gameObject = nullptr;

		void (*instantiateScript)(NativeScript*, const unsigned int&) = {};

		GameObject* (*instantiateFunction)() = {};
		void(*destroyFunction)(NativeScript*) = {};

		template<typename T>
		void addScript() {
			instantiateFunction = []() {return static_cast<GameObject*>(new T()); };
			destroyFunction = [](NativeScript* nativeScript) {delete nativeScript->gameObject; nativeScript->gameObject = nullptr; };
		}

		//name is the name of the dll file in which the script is in
		void addScript(const std::string& name) {
			nameToScriptIndex[scriptIndex] = name;
			scriptIndex += 1;
			
			instantiateScript = [](NativeScript* nativeScript, const unsigned int& index) {

				if (ScriptManager::getScript(nativeScript->nameToScriptIndex[index]) != nullptr)
					nativeScript->scripts[index] = ScriptManager::createScript(nativeScript->nameToScriptIndex[index]);
				else
					Debug::systemErr("Couldn't find script: " + nativeScript->nameToScriptIndex[index]);
			};
		}

		void destroyScripts() {

		}

	};

}


#endif