#include "hpch.h"

namespace HGE {

	Window* Engine::window = nullptr;
	std::vector<GuiFrame*> Engine::guiFrames = std::vector<GuiFrame*>();

	void Engine::startEngine() {
		Debug::waterMark();
		Debug::newLine();

		Debug::systemLog("Starting up Hydrogen Framework (TM)");
		Debug::newLine();

		Debug::systemLog("Initializing GLFW");

		if (!glfwInit()) {
			exit(1);
			Debug::systemErr("GLFW was not initialized");
		}
		else
			Debug::systemSuccess("GLFW was initialized");

		Debug::newLine();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //i want opengl 4 or someting
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		Debug::systemLog("Creating Main Window");
		window->create();
		Debug::systemSuccess("Main window was created");
		Debug::newLine();


		Debug::systemLog("Initializing Input");
		Input::setWindow(window);
		Debug::systemSuccess("Input was initialized");
		Debug::newLine();

		Debug::systemLog("Initializing GLEW");
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK) {
			Debug::systemErr("GLEW was not initialized");
		}
		else
			Debug::systemSuccess("GLEW was initialized");
		Debug::newLine();

		Debug::systemLog("Initialzing Renderer");
		Renderer::init((float)window->size.x, (float)window->size.y);
		Debug::systemSuccess("Renderer was initialized");
		Debug::newLine();

		Debug::systemLog("Initializing Utilities");
		Util::init();
		Random::init();
		Debug::systemSuccess("Utilities was initialized");
		Debug::newLine();

		Debug::systemLog("Loading Scripts");
		ScriptManager::init();
		Debug::systemSuccess("Scripts were loaded");
		Debug::newLine();

		Debug::systemLog("Attempting to start Hydrogen Game Engine (TM)");
		Debug::resetTextColor();
		Debug::newLine();
	}

	void Engine::updateEngine() {
		Time::update();
		Input::update();
		Debug::update();
		ScriptManager::update();
	}

	void Engine::stopEngine() {
		Debug::closingWaterMark();
		Debug::newLine();

		Debug::systemLog("Closing main window");
		glfwTerminate();
		delete window;
		Debug::systemSuccess("Closed main window");
		Debug::newLine();

		Debug::systemLog("Closing Renderer");
		Renderer::close();
		Debug::systemSuccess("Closed Renderer");
		Debug::newLine();

		Debug::systemLog("Closing Utilities");
		Util::deleteVBOs();
		Debug::systemSuccess("Closed Utilities");
		Debug::newLine();

		Debug::systemLog("Deleting Scripts");
		ScriptManager::close();
		Debug::systemSuccess("Scripts were deleted");
		Debug::newLine();
	}

	void Engine::registerGuiFrame(GuiFrame* frame) {
		if (std::find(guiFrames.begin(), guiFrames.end(), frame) == guiFrames.end()) {
			guiFrames.push_back(frame);
		}
	}

	void Engine::removeGuiFrame(GuiFrame* frame) {
		for (size_t i = 0; i < guiFrames.size(); ++i) {
			if (frame == guiFrames[i])
				guiFrames.erase(guiFrames.begin() + i, guiFrames.begin() + i + 1);
		}
	}

	void Engine::removeGuiFrame(const std::string& frame) {
		for (size_t i = 0; i < guiFrames.size(); ++i) {
			if (frame == guiFrames[i]->name)
				guiFrames.erase(guiFrames.begin() + i, guiFrames.begin() + i + 1);
		}
	}

}