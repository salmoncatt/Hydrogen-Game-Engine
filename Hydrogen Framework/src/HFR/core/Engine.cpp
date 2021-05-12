#include "hfpch.h"
#include "HFR/text/FreeType.h"
#include "HFR/gui/GuiText.h"
#include "HFR/text/Face.h"


namespace HFR {

	Window* Engine::window = nullptr;
	std::vector<GuiFrame*> Engine::guiFrames = std::vector<GuiFrame*>();
	std::vector<FT_Face*> Engine::faces = std::vector<FT_Face*>();
	std::vector<std::string> Engine::faceNames = std::vector<std::string>();

	void Engine::startEngine() {
		Debug::waterMark();
		Debug::newLine();

		Debug::systemLog("Starting up Hydrogen Framework (TM)");
		Debug::newLine();

		Debug::systemLog("Initializing GLFW");

		if (!glfwInit()) {
			Debug::systemErr("GLFW was not initialized");
			exit(1);
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

		Debug::systemLog("Initializing Freetype");
		FreeType::init();
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

		Debug::systemLog("Closing Freetype");
		FreeType::close();
		Debug::newLine();

		Debug::systemLog("Closing Utilities");
		Util::deleteVBOs();
		Debug::systemSuccess("Closed Utilities");
		Debug::newLine();

		Debug::systemLog("Deleting Gui Items");
		int amount = 0;
		for (int i = 0; i < guiFrames.size(); i++) {
			delete guiFrames[i];
			amount += 1;
		}
		Debug::systemSuccess("Deleted " + std::to_string(amount) + " Gui Items");
		Debug::newLine();

		Debug::systemLog("Deleting Fonts");
		amount = 0;
		for (int i = 0; i < faces.size(); i++) {
			if (faces[i] != nullptr) {
				FT_Done_Face(*faces[i]);
			}
			amount += 1;
		}
		Debug::systemSuccess("Deleted " + std::to_string(amount) + " Fonts");
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

	Face Engine::loadFace(const std::string& path) {
		std::string name = Util::removePathFromFilePathAndName(path);

		if (std::find(faceNames.begin(), faceNames.end(), name) == faceNames.end()) {
			Face face = Face();
			face.path = path;
			face.name = name;
			face.freeTypeFace = FreeType::loadFace(path);

			if (face.freeTypeFace != nullptr) {
				faceNames.push_back(name); 
				faces.push_back(&face.freeTypeFace);
				return face;
			}
			else {
				Debug::systemErr("Font: " + name + " has failed to load.");
				return Face();
			}
		}

		Debug::systemErr("Font: " + name + " has already been loaded, returning blank Face.");
		return Face();
	}

}