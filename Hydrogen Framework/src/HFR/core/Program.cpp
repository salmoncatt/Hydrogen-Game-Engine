#include "hfpch.h"

namespace HFR {

	Program::Program() {
		window = new HFR::Window(Vec2i(1880, 1080), "Hydrogen Game Engine");
		Engine::window = window;
	}

	Program::~Program() {
	}

	void Program::create() {
	}

	void Program::start() {
	
	}

	bool Program::shouldUpdate() {
		Engine::updateEngine();
		return !window->shouldClose();
	}

}