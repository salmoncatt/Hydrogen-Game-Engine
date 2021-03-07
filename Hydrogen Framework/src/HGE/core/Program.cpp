#include "hpch.h"

namespace HGE {

	Program::Program() {
		window = new HGE::Window(Vec2i(1880, 1080), "Hydrogen Game Engine");
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