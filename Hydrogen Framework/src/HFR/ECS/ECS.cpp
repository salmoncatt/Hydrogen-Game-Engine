#include "hfpch.h"

namespace HFR {

	EntityManager::EntityManager() {
		for (int i = 0; i < HFR_MAX_ENTITIES; i++) {
			entityQueue.push(i);
		}
	}

	EntityManager::~EntityManager() {

	}

	Entity EntityManager::createEntity() {
		if (entityAmount < HFR_MAX_ENTITIES) {
			
			unsigned int id = entityQueue.front();

			Entity out = Entity();
			out.id = id;

			entities[entityAmount] = out;
			entityQueue.pop();
			entityAmount += 1;

			return out;
		}
		else
			Debug::systemErr("Couldn't add new entity, max amount in use");
		return *static_cast<Entity*>(nullptr);
	}

	void EntityManager::destoryEntity(const Entity& entity) {
		if (entity.id < HFR_MAX_COMPONENTS) {
			entityQueue.push(entity.id);
			entityAmount -= 1;
		}
		else
			Debug::systemErr("Could not destroy entity because the id was out of range");
	}

	System::System() {

	}

	System::~System() {

	}

	Entity System::createEntity() {
		return entityManager.createEntity();
	}

	void System::destroyEntity(Entity& entity) {
		entityManager.destoryEntity(entity);
		componentManager.destroyEntity(entity);
	}

	ComponentManager* System::getComponentManager() {
		return &componentManager;
	}
	EntityManager* System::getEntityManager() {
		return &entityManager;
	}

	std::array<Entity, HFR_MAX_ENTITIES>* System::getEntities() {
		return &entityManager.entities;
	}

	unsigned int System::getEntityAmount() {
		return entityManager.entityAmount;
	}


}