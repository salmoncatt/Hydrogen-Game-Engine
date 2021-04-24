#include "hfpch.h"
#include "HFR.h"

using namespace HFR;

class Main : public HFR::Program {
public:
	Scene* test;

	Main() {
		test = new Scene();
	}

	~Main() {
	}

	void create() override {

		Image icon = Image(HFR_RES + "textures/icon.png");

		window->setIcon(icon);

		window->setBackGroundColor(Vec4f(1, 0.7f, 0, 1));

		test->initialize();
	}

	void start() override {
		window->resize(Vec2i(1000, 600));
		window->setPosition(Vec2i(300, 100));

		Renderer::setCullingMode(true);
		Renderer::setLightMode(HFR_PER_PIXEL_LIGHT);
		//Engine::window->setVSync(true);

		test->editorCamera.transform.position = Vec3f(0, 0, 10);

		GameObject peter = test->createGameObject("peter");
		GameObject warehouse = test->createGameObject("warehouse");

		MeshComponent mesh = MeshComponent();
		mesh.meshes = Util::loadMesh(HFR_RES + "models/peter/peter.obj");
		peter.addComponent<MeshComponent>(mesh);
		peter.getComponent<Transform>().scale = 2;

		mesh = MeshComponent();

		mesh.meshes = Util::loadMesh(HFR_RES + "models/warehouse/warehouse.obj");

		warehouse.addComponent<MeshComponent>(mesh);

		warehouse.getComponent<Transform>().scale = (2);

		for (int i = 0; i < warehouse.getComponent<MeshComponent>().meshes.size(); i++) {
			auto& component = warehouse.getComponent<MeshComponent>().meshes[i];

			component.texturecoords.clear();
			//component.calculateNormals(1);
		}

		peter.addComponent<NativeScript>().addScript("testScript");


		Font oxygen = Font(HFR_RES + "fonts/oxygen/Oxygen-Regular.ttf");
		oxygen.create();

		while (shouldUpdate() && !Input::getKey(HFR_KEY_ESCAPE)) {
			ProfileMethod("Main loop");
			test->updateEditor();

			if (Input::getMouseButtonDown(HFR_MOUSE_BUTTON_2))
				Cursor::toggleMouseState();

			if (Input::getKeyDown(HFR_KEY_BACKSLASH))
				Renderer::toggleWireFrameMode();

			if (Input::getKeyDown(HFR_KEY_F))
				ProjectManager::createEngineProject("testProject", "testScript");
			else if(Input::getKeyDown(HFR_KEY_G))
				VisualStudio::openVisualStudio(HFR_PROJECTS_PATH + "testProject/Scripts/testProject.sln");

			Renderer::render(oxygen, "poop", Vec2i(100), Vec2i(1));

			window->limitFps(200);
		}

		delete test;
	}

};

HFR::Program* HFR::createProgram() {
	return new Main();
}