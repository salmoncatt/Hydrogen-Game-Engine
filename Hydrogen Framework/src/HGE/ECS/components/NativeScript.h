
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
		std::unordered_map<std::string, unsigned int> nameToScriptIndex{};
		size_t scriptIndex = 0;
		std::array<GameObject*, HGE_MAX_SCRIPTS> scripts{nullptr};

		GameObject* gameObject = nullptr;


		GameObject* (*instantiateFunction)() = {};
		void(*destroyFunction)(NativeScript*) = {};

		template<typename T>
		void addScript() {

			instantiateFunction = []() {return static_cast<GameObject*>(new T()); };
			destroyFunction = [](NativeScript* nativeScript) {delete nativeScript->gameObject; nativeScript->gameObject = nullptr; };
		}

		//name is the name of the dll file in which the script is in
		void addScript(const std::string& name) {
			scripts[scriptIndex] = new GameObject();
			scripts[scriptIndex] = static_cast<GameObject*>(ScriptManager::getScript(name));
			scriptIndex += 1;
		}

		void destroyScripts() {

		}

	};

}


#endif