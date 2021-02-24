#include "hpch.h"

#include "Program.h"
#include "HGE/util/Debug.h"
#include "HGE/util/Util.h"
#include "HGE/graphics/rendering/Renderer.h"
#include "HGE/io/Input.h"
#include "HGE/util/time/Time.h"
#include "HGE/util/time/Profiler.h"
#include "Engine.h"

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