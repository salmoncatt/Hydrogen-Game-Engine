
#ifndef HGE_NATIVE_SCRIPT_HEADER_INCLUDE
#define HGE_NATIVE_SCRIPT_HEADER_INCLUDE

#include HGE_API
#include "HGE/ECS/ECS.h"
#include "HGE/ECS/GameObject.h"

using Script = HGE::GameObject;

namespace HGE {

	struct DLL_API NativeScript {
		GameObject* gameObject = nullptr;

		GameObject* (*instantiateFunction)() = {};
		void(*destroyFunction)(NativeScript*) = {};

		template<typename T>
		void addScript() {

			instantiateFunction = []() {return static_cast<GameObject*>(new T()); };
			destroyFunction = [](NativeScript* nativeScript) {delete nativeScript->gameObject; nativeScript->gameObject = nullptr; };

		}

	};

}


#endif