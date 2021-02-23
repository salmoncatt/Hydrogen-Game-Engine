#include "hpch.h"
#include "GameObject.h"
#include "components/Transform.h"
#include "components/Tag.h"
#include "components/Mesh.h"
#include "components/MeshComponent.h"
#include "components/Texture.h"
#include "components/NativeScript.h"

namespace HGE {

	GameObject::GameObject(const Entity& _entity, Scene* _scene) {
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
	template Transform& GameObject::addComponent<Transform>();
	template Transform& GameObject::addComponent<Transform>(Transform&);
	template Transform& GameObject::getComponent<Transform>();
	template void GameObject::removeComponent<Transform>();

	//templates for tag component
	template Tag& GameObject::addComponent<Tag>();
	template Tag& GameObject::addComponent<Tag>(Tag&);
	template Tag& GameObject::getComponent<Tag>();
	template void GameObject::removeComponent<Tag>();

	////templates for Mesh component (no longer in use because of meshComponent)
	//template void GameObject::addComponent<Mesh>();
	//template void GameObject::addComponent<Mesh>(Mesh&);
	//template Mesh& GameObject::getComponent<Mesh>();
	//template void GameObject::removeComponent<Mesh>();

	//templates for MeshComponent component
	template MeshComponent& GameObject::addComponent<MeshComponent>();
	template MeshComponent& GameObject::addComponent<MeshComponent>(MeshComponent&);
	template MeshComponent& GameObject::getComponent<MeshComponent>();
	template void GameObject::removeComponent<MeshComponent>();

	//templates for Texture component
	template Texture& GameObject::addComponent<Texture>();
	template Texture& GameObject::addComponent<Texture>(Texture&);
	template Texture& GameObject::getComponent<Texture>();
	template void GameObject::removeComponent<Texture>();

	//templates for NativeScript component
	template NativeScript& GameObject::addComponent<NativeScript>();
	template NativeScript& GameObject::addComponent<NativeScript>(NativeScript&);
	template NativeScript& GameObject::getComponent<NativeScript>();
	template void GameObject::removeComponent<NativeScript>();

}
