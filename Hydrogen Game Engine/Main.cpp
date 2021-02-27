#include "hpch.h"
#include "HGE.h"

using namespace HGE;

class Main : public HGE::Program {

	//test script
	class TestScript : public Script {
	public:

		void start() {
			//Debug::log("I started lets fucking gooooo");

		}

		void update() {
			//getComponent<Transform>().rotation += Vec3f(100 * Time::getDeltaTime());
			//getComponent<Transform>().position.y += Input::getScrollMovement().y;
			//Debug::log("I updated lets fucking gooooo");
		}

		void fixedUpdate() {

		}

		void stop() {

		}

	};







public:
	Scene* test;

	Main() {
		test = new Scene();
	}

	~Main() {
	}

	void create() override {

		Image icon = Image(HGE_RES + "textures/icon.bmp");

		window->setIcon(icon);

		window->setBackGroundColor(Vec4f(1, 0.7f, 0, 1));

		test->initialize();
	}

	void start() override {
		window->resize(Vec2i(1000, 600));
		window->setPosition(Vec2i(300, 100));

		Renderer::setCullingMode(true);
		Renderer::setLightMode(HGE_PER_PIXEL_LIGHT);

		test->editorCamera.transform.position = Vec3f(0, 0, 10);

		GameObject peter = test->createGameObject("peter");
		GameObject warehouse = test->createGameObject("warehouse");

		MeshComponent mesh = MeshComponent();
		mesh.meshes = Util::loadMesh(HGE_RES + "models/peter/", "peter.obj");
		peter.addComponent<MeshComponent>(mesh);
		peter.getComponent<Transform>().scale = 2;

		mesh = MeshComponent();

		mesh.meshes = Util::loadMesh(HGE_RES + "models/warehouse/", "warehouse.obj");

		warehouse.addComponent<MeshComponent>(mesh);

		warehouse.getComponent<Transform>().scale = (2);

		for (int i = 0; i < warehouse.getComponent<MeshComponent>().meshes.size(); i++) {
			auto& component = warehouse.getComponent<MeshComponent>().meshes[i];

			component.texturecoords.clear();
			//component.calculateNormals(1);
		}

		peter.addComponent<NativeScript>().addScript<TestScript>();

		float angle = 0;

		while (shouldUpdate() && !Input::getKey(HGE_KEY_ESCAPE)) {
			test->updateEditor();

			if (Input::getMouseButtonDown(HGE_MOUSE_BUTTON_2))
				Cursor::toggleMouseState();

			if (Input::getKeyDown(HGE_KEY_BACKSLASH))
				Renderer::toggleWireFrameMode();

			angle += Input::getScrollMovement().y * 2;

			//Vec2f(-1 * Renderer::getAspectRatio() + 0.5f, 1 - 0.5f)
			Renderer::renderRectangle(Vec2f(), Vec2f(0.5f, 1), angle, Vec3f(0.4f, 0.2f, 0.8f));

			window->limitFps(200);
		}

		delete test;
	}

};

HGE::Program* HGE::createProgram() {
	return new Main();
}