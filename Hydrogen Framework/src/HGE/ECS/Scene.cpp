#include "hpch.h"
#include "Scene.h"
#include "GameObject.h"

#include "components/Transform.h"
#include "components/Tag.h"
#include "HGE/ECS/components/Mesh.h"
#include "HGE/ECS/components/MeshComponent.h"

#include "HGE/graphics/rendering/Renderer.h"
#include "HGE/util/Debug.h"
#include "HGE/util/time/Time.h"
#include "HGE/io/Input.h"
#include "HGE/math/HMath.h"
#include "HGE/util/time/Profiler.h"

namespace HGE {

	Scene::Scene() {
		editorCamera = EditorCamera();
		performanceStats = GuiWindow();
		gameObjectList = GuiWindow();
		gameObjectComponentsList = GuiWindow();

		//performance status elements





	}

	Scene::~Scene() {

	}

	GameObject Scene::createGameObject(const std::string& name) {
		GameObject out = { system.createEntity(), this };

		Transform transform = Transform();
		out.addComponent<Transform>(transform);

		Tag tag = Tag(name.c_str());
		out.addComponent<Tag>(tag);

		return out;
	}

	void Scene::updateEditor() {
		editorCamera.update();

		Renderer::setCamera(editorCamera.camera);

		for (unsigned int i = 0; i < system.getEntityAmount(); i++) {
			Entity entity = (*system.getEntities())[i];

			auto& meshcomponent = system.getComponentManager()->getComponent<MeshComponent>(entity);
			auto& transform = system.getComponentManager()->getComponent<Transform>(entity);

			HMath::keepRotationInTermsOf360(transform.rotation);

			//transform.rotation += Time::getDeltaTime() * 20;

			if (meshcomponent.meshes.size() > 0) {
				for (int i = 0; i < meshcomponent.meshes.size(); i++) {
					auto& mesh = meshcomponent.meshes[i];
					auto& texture = meshcomponent.meshes[i].material.albedoTexture;

					if (!mesh.vertices.empty()) {
						if (!mesh.created)
							mesh.create();

						if (!texture.isCreated)
							texture.create();

						Renderer::render(mesh, transform, texture);
					}
				}
			}
			/*else {
				auto& mesh = system.getComponentManager()->getComponent<Mesh>(entity);
				auto& texture = system.getComponentManager()->getComponent<Texture>(entity);

				if (!mesh.vertices.empty()) {
					if (!mesh.created)
						mesh.create();

					if (!texture.isCreated)
						texture.create();

					Renderer::render(mesh, transform, texture);
				}
			}*/

		}
	}

	System* Scene::getSystem() {
		return &system;
	}

}