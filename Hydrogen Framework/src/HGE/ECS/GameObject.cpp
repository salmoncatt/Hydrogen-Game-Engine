#include "hpch.h"
#include "GameObject.h"
#include "components/Transform.h"
#include "components/Tag.h"
#include "components/Mesh.h"
#include "components/MeshComponent.h"
#include "components/Texture.h"

namespace HGE {

	GameObject::GameObject(Entity _entity, Scene* _scene) {
		entity = _entity;
		scene = _scene;
	}

	GameObject::GameObject() {
		entity = Entity();
		scene = nullptr;
	}

	GameObject::~GameObject() {
		
	}

	//templates for transform component
	template void GameObject::addComponent<Transform>();
	template void GameObject::addComponent<Transform>(Transform&);
	template Transform& GameObject::getComponent<Transform>();
	template void GameObject::removeComponent<Transform>();

	//templates for tag component
	template void GameObject::addComponent<Tag>();
	template void GameObject::addComponent<Tag>(Tag&);
	template Tag& GameObject::getComponent<Tag>();
	template void GameObject::removeComponent<Tag>();

	////templates for Mesh component (no longer in use because of meshComponent)
	//template void GameObject::addComponent<Mesh>();
	//template void GameObject::addComponent<Mesh>(Mesh&);
	//template Mesh& GameObject::getComponent<Mesh>();
	//template void GameObject::removeComponent<Mesh>();

	//templates for MeshComponent component
	template void GameObject::addComponent<MeshComponent>();
	template void GameObject::addComponent<MeshComponent>(MeshComponent&);
	template MeshComponent& GameObject::getComponent<MeshComponent>();
	template void GameObject::removeComponent<MeshComponent>();

	//templates for Texture component
	template void GameObject::addComponent<Texture>();
	template void GameObject::addComponent<Texture>(Texture&);
	template Texture& GameObject::getComponent<Texture>();
	template void GameObject::removeComponent<Texture>();

}
