#include "hpch.h"
#include "Cursor.h"
#include "HGE/io/Input.h"
#include "HGE/io/Window.h"

namespace HGE {

	bool Cursor::state = true;
	bool Cursor::oldState = true;

	void Cursor::setMouseState(const bool& _state) {
		state = _state;
		glfwSetInputMode(Input::getCurrentWindow()->window, GLFW_CURSOR, (state == HGE_MOUSE_NORMAL) ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
	}

	void Cursor::toggleMouseState() {
		setMouseState(!state);
	}

	bool Cursor::getMouseState() {
		return state;
	}

	void Cursor::update() {
		oldState = state;
	}

}