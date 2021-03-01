#include "hpch.h"
#include "Scene.h"
#include "GameObject.h"

#include "components/Transform.h"
#include "components/Tag.h"
#include "HGE/ECS/components/Mesh.h"
#include "HGE/ECS/components/MeshComponent.h"
#include "HGE/ECS/components/NativeScript.h"

#include "HGE/graphics/rendering/Renderer.h"
#include "HGE/util/Debug.h"
#include "HGE/util/time/Time.h"
#include "HGE/io/Input.h"
#include "HGE/math/HMath.h"
#include "HGE/util/time/Profiler.h"
#include "HGE/util/Util.h"
#include "HGE/core/Program.h"
#include "HGE/core/Engine.h"

namespace HGE {

	Scene::Scene() {
		//editorCamera = EditorCamera();
		//performanceStats = GuiWindow();
		//gameObjectList = GuiWindow();
		//gameObjectComponentsList = GuiWindow();

		//performance status elements

		lerpedCpuUsage = 0;
		lerpedRamUsage = 0;
	}

	Scene::~Scene() {

	}

	void Scene::initialize() {
		radialBarTexture = Texture(HGE_RES + "textures/radial bar half.bmp");
		radialBarTexture.create();
	}

	GameObject Scene::createGameObject(const std::string& name) {
		GameObject out = { system.createEntity(), this };

		Transform transform = Transform();
		out.addComponent<Transform>(transform);

		Tag tag = Tag(name);
		out.addComponent<Tag>(tag);

		return out;
	}

	void Scene::updateEditor() {
		editorCamera.update();

		Renderer::setCamera(editorCamera.camera);

		for (unsigned int i = 0; i < system.getEntityAmount(); i++) {
			Entity entity = (*system.getEntities())[i];

			//update scripts (NEED TO PUSH TO UPDATE GAME NOT EDITOR)
			if (system.getComponentManager()->hasComponent<NativeScript>(entity)) {
				auto& script = system.getComponentManager()->getComponent<NativeScript>(entity);

				if (!script.gameObject) {
					//create the script
					script.instantiateFunction();

					//add the entity reference to the script (to call things like getComponent<>())
					script.gameObject->entity = entity;
					script.gameObject->scene = this;

					//startup the script
					if(script.startFunction)
						script.startFunction(script.gameObject);
				}

				if(script.updateFunction)
					script.updateFunction(script.gameObject);

			}



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




		lerpedCpuUsage = HMath::lerp(lerpedCpuUsage, (float)Util::getCPUusage(), 0.01f);
		lerpedRamUsage = HMath::lerp(lerpedRamUsage, (float)Util::getRAMusage(), 0.01f);

		//background
		Renderer::renderRoundedRectangle(Vec2f(0, (float)Engine::window->size.y - 256), Vec2f(600, 256), 10, Vec3f(0.2f));
		//starting left first cpu usage
		Renderer::radialRevealRectangle(Vec2f(10, (float)Engine::window->size.y - 70), Vec2f(122, 122), lerpedCpuUsage * 180, 10, false, radialBarTexture);
		//second ram usage
		Renderer::radialRevealRectangle(Vec2f(142, (float)Engine::window->size.y - 70), Vec2f(122, 122), (float)(lerpedRamUsage / 2000) * 180, 0, false, radialBarTexture);
		//third is gpu usage (usage as in how much of the 60 fps frame budget are we using)
		Renderer::radialRevealRectangle(Vec2f(274, (float)Engine::window->size.y - 70), Vec2f(122, 122), (1 / (Time::getFPS() / 60)) * 180, 0, false, radialBarTexture);



	}

	System* Scene::getSystem() {
		return &system;
	}

}