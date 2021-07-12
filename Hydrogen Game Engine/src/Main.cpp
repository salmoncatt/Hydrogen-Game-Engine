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
		//Engine::window->setVSync(true);

		test->editorCamera.transform.position = Vec3f(0, 0, 10);

		GameObject peter = test->createGameObject("peter");
		GameObject warehouse = test->createGameObject("warehouse");

		MeshComponent mesh = MeshComponent();
		mesh.meshes = Util::loadMesh(HFR_RES + "models/peter/peter.obj");
		peter.addComponent<MeshComponent>(mesh);
		peter.getComponent<Transform>().scale = 2;

		mesh = MeshComponent();

		//mesh.meshes = Util::loadMesh(HFR_RES + "models/warehouse/warehouse.obj");
		mesh.meshes = Util::loadMesh(HFR_RES + "models/crate/crate.obj");

		warehouse.addComponent<MeshComponent>(mesh);

		warehouse.getComponent<Transform>().scale = (2);
		//warehouse.getComponent<Transform>().scale = (0.03f);
		//warehouse.getComponent<MeshComponent>().clearAllTextureCoordinates();


		Font oxygen = Font(HFR_RES + "fonts/oxygen/Oxygen-Regular.ttf");
		oxygen.size = Vec2f(0, 48);
		oxygen.create();

		GuiText text = GuiText("haha poop", oxygen, Transform2D(Vec2f(-0.7f, -0.3f), Vec2f(0), Vec2f(0.001f)));
		text.create();


		peter.addComponent<NativeScript>().addScript("testScript");

		Renderer::light.diffuseColor = Vec3f(1);

		/*GuiFrame* frame = new GuiFrame();
		frame->draggable = true;
		frame->active = true;
		frame->selectable = true;*/

		GuiImage goob = GuiImage();
		goob.texture = Texture(HFR_RES + "textures/radial bar full.png");
		goob.texture.create();
		goob.radialFill = 270;
		//goob.radialFillInverse = true;
		goob.radialFillAngleOffset = 90;

		while (shouldUpdate() && !Input::getKey(HFR_KEY_ESCAPE)) {
			ProfileMethod("Main loop");
			test->updateEditor();

			if (Input::getMouseButtonDown(HFR_MOUSE_BUTTON_2))
				Cursor::toggleMouseState();

			if (Input::getKeyDown(HFR_KEY_BACKSLASH))
				Renderer::toggleWireFrameMode();

			//Renderer::light.position.x = 50 * sin(Time::getTime() / 400);
			//Renderer::light.position.z = 50 * cos(Time::getTime() / 400);

			//move light
			if (Input::getKey(HFR_KEY_UP))
				Renderer::light.position.x += 3 * Time::getDeltaTime();
			if (Input::getKey(HFR_KEY_DOWN))
				Renderer::light.position.x -= 3 * Time::getDeltaTime();
			if (Input::getKey(HFR_KEY_LEFT))
				Renderer::light.position.z -= 3 * Time::getDeltaTime();
			if (Input::getKey(HFR_KEY_RIGHT))
				Renderer::light.position.z += 3 * Time::getDeltaTime();
			Renderer::light.position.y += Input::getScrollMovement().y;

			//if (Input::getKeyDown(HFR_KEY_F))
				//ProjectManager::createEngineProject("testProject", "testScript");
			if(Input::getKeyDown(HFR_KEY_G))
				VisualStudio::openVisualStudio(HFR_PROJECTS_PATH + "testProject/Scripts/testProject.sln");

			window->limitFps(200);
			Renderer2D::render(text);
		}

		delete test;
	}

};

HFR::Program* HFR::createProgram() {
	return new Main();
}