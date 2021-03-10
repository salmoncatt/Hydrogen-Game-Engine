#include "hpch.h"
#include "HGE.h"

using namespace HGE;

class Main : public HGE::Program {
public:
	Scene* test;

	Main() {
		test = new Scene();
	}

	~Main() {
	}

	void create() override {

		Image icon = Image(HGE_RES + "textures/icon.png");

		window->setIcon(icon);

		window->setBackGroundColor(Vec4f(1, 0.7f, 0, 1));

		test->initialize();
	}

	void start() override {
		window->resize(Vec2i(1000, 600));
		window->setPosition(Vec2i(300, 100));

		Renderer::setCullingMode(true);
		Renderer::setLightMode(HGE_PER_PIXEL_LIGHT);
		//Engine::window->setVSync(true);

		test->editorCamera.transform.position = Vec3f(0, 0, 10);

		GameObject peter = test->createGameObject("peter");
		GameObject warehouse = test->createGameObject("warehouse");

		MeshComponent mesh = MeshComponent();
		mesh.meshes = Util::loadMesh(HGE_RES + "models/zip gun/zip gun.obj");
		peter.addComponent<MeshComponent>(mesh);
		peter.getComponent<Transform>().scale = 2;

		mesh = MeshComponent();

		mesh.meshes = Util::loadMesh(HGE_RES + "models/warehouse/warehouse.obj");

		warehouse.addComponent<MeshComponent>(mesh);

		warehouse.getComponent<Transform>().scale = (2);

		//ProjectManager::createEngineProject("testProject", "testScript");

		for (int i = 0; i < warehouse.getComponent<MeshComponent>().meshes.size(); i++) {
			auto& component = warehouse.getComponent<MeshComponent>().meshes[i];

			component.texturecoords.clear();
			//component.calculateNormals(1);
		}

		peter.addComponent<NativeScript>().addScript("Scripts");

		while (shouldUpdate() && !Input::getKey(HGE_KEY_ESCAPE)) {
			ProfileMethod("Main loop");
			test->updateEditor();

			if (Input::getMouseButtonDown(HGE_MOUSE_BUTTON_2))
				Cursor::toggleMouseState();

			if (Input::getKeyDown(HGE_KEY_BACKSLASH))
				Renderer::toggleWireFrameMode();

			window->limitFps(200);
		}

		delete test;
	}

};

HGE::Program* HGE::createProgram() {
	return new Main();
}