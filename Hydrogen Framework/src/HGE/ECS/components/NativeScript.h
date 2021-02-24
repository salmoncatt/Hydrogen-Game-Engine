
#ifndef HGE_NATIVE_SCRIPT_HEADER_INCLUDE
#define HGE_NATIVE_SCRIPT_HEADER_INCLUDE

#include HGE_API
#include "HGE/ECS/ECS.h"
#include "HGE/ECS/GameObject.h"

using Script = HGE::GameObject;

namespace HGE {

	struct DLL_API NativeScript {
		GameObject* gameObject = nullptr;

		std::function<void()> instantiateFunction;
		std::function<void()> destroyFunction;

		std::function<void(GameObject*)> startFunction;
		std::function<void(GameObject*)> stopFunction;
		std::function<void(GameObject*)> updateFunction;
		std::function<void(GameObject*)> fixedUpdateFunction;

		template<typename T>
		void addScript() {

			//i could leave it as [&] but i prefer the look of [&this] (nvm it just doesnt compile... whatever)
			instantiateFunction = [&]() {gameObject = new T(); };
			destroyFunction = [&]() {delete (T*)gameObject; };

			startFunction = [](GameObject* instance) {	((T*)instance)->start(); };
			stopFunction = [](GameObject* instance) {	((T*)instance)->stop(); };
			updateFunction = [](GameObject* instance) {	((T*)instance)->update(); };
			fixedUpdateFunction = [](GameObject* instance) {	((T*)instance)->fixedUpdate(); };

		}

	};

}


#endif