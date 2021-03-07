
#ifndef HGE_ECS_HEADER_INCLUDE
#define HGE_ECS_HEADER_INCLUDE

#include HGE_API

#define HGE_MAX_ENTITIES 5000
#define HGE_MAX_COMPONENTS 50

#include HGE_DEBUG

namespace HGE {

	struct DLL_API Entity {
		unsigned int id = 0;
	};

}

namespace HGE {

	class DLL_API ComponentArrayBase {
	public:
		ComponentArrayBase() = default;
		~ComponentArrayBase() = default;
		virtual void destroyEntity(Entity& entity) = 0;
	};

	template<typename T>
	class DLL_API ComponentArray : public ComponentArrayBase {
	private:
		std::array<unsigned int, HGE_MAX_ENTITIES> componentIndex{0};
		std::array<T, HGE_MAX_ENTITIES> components;

		unsigned int currentSize = 1;

	public:

		using type = T;

		T& addComponent(const Entity& entity, T& component) {
			if (entity.id < HGE_MAX_ENTITIES) {
				if (componentIndex[entity.id] == 0) {
					componentIndex[entity.id] = currentSize;
					components[currentSize] = component;
					currentSize += 1;

					return components[componentIndex[entity.id]];
				}
				else {
					Debug::systemErr("Couldn't add component of type: " + std::string(typeid(T).name()) + ", because the entity has that component");
					return components[componentIndex[entity.id]];
				}
			}
			else {
				Debug::systemErr("Couldn't add component of type: " + std::string(typeid(T).name()) + ", because the entity id was out of range");
				return *static_cast<T*>(nullptr);
			}
		}

		T& getComponent(const Entity& entity) {

			if (entity.id >= HGE_MAX_ENTITIES) {
				std::string name = typeid(T).name();

				Debug::systemErr("Couldn't get component of type: " + name + ", because the entity id was out of range");

				return *static_cast<T*>(nullptr);
			}
			else
				return components[componentIndex[entity.id]];
		}

		bool hasComponent(const Entity& entity) {
			if (entity.id >= HGE_MAX_ENTITIES) {
				return false;
			}
			else
				return componentIndex[entity.id] > 0;
		}

		void removeComponent(const Entity& entity) {
			if (entity.id < HGE_MAX_ENTITIES) {
				components[componentIndex[entity.id]] = components[componentIndex[currentSize]];
				components[componentIndex[currentSize]] = T();
				currentSize -= 1;
			}
			else
				Debug::systemErr("Couldn't remove component of type: " + std::string(typeid(T).name()) + ", because the entity id was out of range");
		}

		void destroyEntity(Entity& entity) override {

			std::array<unsigned int, HGE_MAX_ENTITIES>::iterator iterator = std::find(componentIndex.begin(), componentIndex.end(), entity.id);

			if (iterator != componentIndex.end()) {
				removeComponent(entity);
				return;
			}

			Debug::systemErr("Could not destroy entity because it was not created");
		}

	};

}

namespace HGE {

	class DLL_API ComponentManager {
	private:
		std::array<std::shared_ptr<ComponentArrayBase>, HGE_MAX_COMPONENTS> componentArrays;
		std::unordered_map<std::string, int> componentTypes{};
		unsigned int managerSize = 0;
		unsigned int typeSize = 0;

	public:

		ComponentManager() = default;
		~ComponentManager() = default;

		template<typename T>
		void registerComponent() {
			const char* type = typeid(T).name();

			if (componentTypes.find(type) == componentTypes.end()) {

				componentTypes[type] = managerSize;

				componentArrays[managerSize] = std::make_shared<ComponentArray<T>>();


				managerSize += 1;
				typeSize += 1;

				Debug::systemSuccess("Registered component type: " + std::string(type), DebugColor::Purple);
				Debug::newLine();
			}

		}

		template<typename T>
		std::shared_ptr<ComponentArray<T>> getArray(const int& code) {
			const char* type = typeid(T).name();

			if (componentTypes.find(type) == componentTypes.end()) {
				//just some code checks for me and my smol brain
				if (code == HGE_ECS_ADD_COMPONENT)
					Debug::systemErr("Uhhh no component was registed but is trying to be added of type: " + std::string(type));

				else if (code == HGE_ECS_GET_COMPONENT)
					Debug::systemErr("Uhhh no component was registed but is trying to be retrieved of type: " + std::string(type));

				else if (code == HGE_ECS_REMOVE_COMPONENT)
					Debug::systemErr("Uhhh no component was registed but is trying to be removed of type: " + std::string(type));

				Debug::systemLog("Creating component of type: " + std::string(type) + " so there wont be errors calling this one again");
				registerComponent<T>();

			}

			return std::static_pointer_cast<ComponentArray<T>>(componentArrays[componentTypes[std::string(type)]]);
		}

		template <typename T>
		T& addComponent(Entity& entity, T& component) {
			registerComponent<T>();
			return getArray<T>(HGE_ECS_ADD_COMPONENT)->addComponent(entity, component);
		}

		template <typename T>
		T& getComponent(Entity& entity) {
			return getArray<T>(HGE_ECS_GET_COMPONENT)->getComponent(entity);
		}

		template <typename T>
		bool hasComponent(Entity& entity) {
			return getArray<T>(HGE_ECS_GET_COMPONENT)->hasComponent(entity);
		}

		template <typename T>
		void removeComponent(Entity& entity) {
			getArray<T>(HGE_ECS_REMOVE_COMPONENT)->removeComponent(entity);
		}

		void destroyEntity(Entity& entity) {
			for (unsigned int i = 0; i < managerSize; i++) {
				auto const& componentArray = componentArrays[i];

				componentArray->destroyEntity(entity);
			}
		}

	};

}

namespace HGE {

	class DLL_API EntityManager {
	private:
		std::queue<unsigned int> entityQueue{};
		std::array<Entity, HGE_MAX_ENTITIES> entities;
		unsigned int entityAmount = 0;
	public:

		EntityManager();
		~EntityManager();

		Entity createEntity();

		void destoryEntity(const Entity& entity);

		friend class System;
	};

}

namespace HGE {

	class DLL_API System {
	private:
		ComponentManager componentManager;
		EntityManager entityManager;

	public:

		System();
		~System();

		Entity createEntity();
		void destroyEntity(Entity& entity);

		ComponentManager* getComponentManager();
		EntityManager* getEntityManager();

		std::array<Entity, HGE_MAX_ENTITIES>* getEntities();
		unsigned int getEntityAmount();

	};

}

#endif