
#ifndef HFR_GAME_OBJECT_HEADER_INCLUDE
#define HFR_GAME_OBJECT_HEADER_INCLUDE

#include HFR_API
#include "ECS.h"
#include "Scene.h"

namespace HFR {

	struct DLL_API GameObject {
	protected:
		virtual void start() {}
		virtual void update() {}
		virtual void fixedUpdate() {}
		virtual void lateUpdate() {}
		virtual void stop() {}

		friend class Scene;
		friend class Util;
		friend class ScriptManager;
		friend struct NativeScript;

		bool created = false;
	public:
		Entity entity;
		Scene* scene = nullptr;

		GameObject(const Entity& entity, Scene* scene);
		GameObject();
		virtual ~GameObject() {};

		template <typename T>
		T& addComponent() {
			T component = T();
			return scene->getSystem()->getComponentManager()->addComponent<T>(entity, component);
		};

		template <typename T>
		T& addComponent(T& component) {
			return scene->getSystem()->getComponentManager()->addComponent<T>(entity, component);
		};
			
		template <typename T>
		T& getComponent() {
			return scene->getSystem()->getComponentManager()->getComponent<T>(entity);
		}

		template <typename T>
		void removeComponent() {
			scene->getSystem()->getComponentManager()->removeComponent<T>(entity);
		}

		bool isCreated();
	};

}

#endif
