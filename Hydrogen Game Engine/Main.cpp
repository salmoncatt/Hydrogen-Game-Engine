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

		Image icon = Image(HGE_RES + "textures/icon.bmp");

		window->setIcon(icon);

		window->setBackGroundColor(Vec4f(1, 0.7f, 0, 1));
	}

	void start() override {
		window->resize(Vec2i(1000, 600));
		window->setPosition(Vec2i(300, 100));


		Renderer::setCullingMode(true);
		Renderer::setLightMode(HGE_PER_PIXEL_LIGHT);

		Vec2f position = Vec2f(0, 0);
		Vec2f size = Vec2f(100, 100);
		Vec3f color = Vec3f(0.2f);

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

		for (int i = 0; i < warehouse.getComponent<MeshComponent>().meshes.size(); i++) {
			warehouse.getComponent<MeshComponent>().meshes[i].texturecoords.clear();
		}

		Texture text = Texture(HGE_RES + "textures/radial bar half.bmp");

		text.create();

		float angle = 0.001f;

		float cpuUsage = 0;
		float ramUsage = 0;

		while (shouldUpdate() && !Input::getKey(HGE_KEY_ESCAPE)) {
			
			if (Input::getMouseButtonDown(HGE_MOUSE_BUTTON_2))
				Cursor::toggleMouseState();

			if (Input::getKeyDown(HGE_KEY_BACKSLASH))
				Renderer::toggleWireFrameMode();

			peter.getComponent<Transform>().rotation += Vec3f(100 * Time::getDeltaTime());

			test->updateEditor();

			if (Input::getMouseButton(HGE_MOUSE_BUTTON_0))
			angle += Time::getDeltaTime() * 20;

			cpuUsage = HMath::lerp(cpuUsage, (float)Util::getCPUusage(), 0.01f);
			ramUsage = HMath::lerp(ramUsage, (float)Util::getRAMusage(), 0.01f);
			
			//background
			Renderer::renderRoundedRectangle(Vec2f(0, (float)window->size.y - 256), Vec2f(600, 256), 10, color);
			//starting left first cpu usage
			Renderer::radialRevealRectangle(Vec2f(10, (float)window->size.y - 70), Vec2f(122, 122), cpuUsage * 180, 10, false, text);
			//second ram usage
			Renderer::radialRevealRectangle(Vec2f(142, (float)window->size.y - 70), Vec2f(122, 122), (float)(ramUsage / 2000) * 180, 0, false, text);
			//third is gpu usage (usage as in how much of the 60 fps frame budget are we using)
			Renderer::radialRevealRectangle(Vec2f(274, (float)window->size.y - 70), Vec2f(122, 122), (1 / (Time::getFPS() / 60)) * 180, 0, false, text);

			Renderer::renderRoundedRectangle(Vec2f(100, 100), Vec2f(100, 100), 10, Vec3f(1));

			window->limitFps(200);
		}

		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		delete test;
	}

};

HGE::Program* HGE::createProgram() {
	return new Main();
}