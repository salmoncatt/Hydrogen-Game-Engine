#include "hpch.h"

namespace HGE {

	std::vector<int> Input::keys = std::vector<int>(GLFW_KEY_LAST);
	std::vector<int> Input::oldkeys = std::vector<int>(GLFW_KEY_LAST);
	std::vector<int> Input::buttons = std::vector<int>(GLFW_MOUSE_BUTTON_LAST);
	std::vector<int> Input::oldbuttons = std::vector<int>(GLFW_MOUSE_BUTTON_LAST);

	Vec2f Input::mousePosition = Vec2f();
	Vec2f Input::oldMousePosition = Vec2f();
	Vec2f Input::mouseMovement = Vec2f();

	Vec2f Input::scrollMovement = Vec2f();

	bool Input::mouseMoved = false;
	int Input::updatesSinceSwitch = 0;

	Window* Input::window = nullptr;

	void Input::setWindow(Window* _window) {
		window = _window;
		setCallbacks(window->window);
		createKeyVectors();
		Debug::systemSuccess("Bound new Window for input polling: " + _window->name);
	}

	Window* Input::getCurrentWindow() {
		return window;
	}

	void Input::setCallbacks(GLFWwindow* window) {
		glfwSetKeyCallback(window, keyCallBack);
		glfwSetMouseButtonCallback(window, buttonCallBack);
		glfwSetCursorPosCallback(window, cursorPositionCallBack);
		glfwSetWindowSizeCallback(window, windowSizeCallBack);
		glfwSetScrollCallback(window, scrollMovementCallBack);
		glfwSetWindowPosCallback(window, windowPositionCallBack);
	}

	void Input::createKeyVectors() {
		keys = std::vector<int>(GLFW_KEY_LAST);
		oldkeys = std::vector<int>(GLFW_KEY_LAST);
		buttons = std::vector<int>(GLFW_MOUSE_BUTTON_LAST);
		oldbuttons = std::vector<int>(GLFW_MOUSE_BUTTON_LAST);
	}

	void Input::setRawInput(const bool& in) {
		if (glfwRawMouseMotionSupported())
			glfwSetInputMode(window->window, GLFW_RAW_MOUSE_MOTION, in ? GLFW_TRUE : GLFW_FALSE);
	}

	void Input::update() {
		ProfileMethod("Input update");
		mouseMovement = mousePosition - oldMousePosition;

		if (!Cursor::oldState&& Cursor::state) {
			mouseMovement = Vec2f();

			Vec2i size = window->size;
			size.x /= 2;
			size.y /= 2;
			setMousePosition(Vec2f((float)size.x, (float)size.y));
			updatesSinceSwitch = 1;
		}

		//glfw cringe and i have to stop its updates up to 3 frames after i reset the mouse
		if (updatesSinceSwitch < 4 && updatesSinceSwitch > 0 && mouseMoved) {
			mouseMovement = Vec2f();
			updatesSinceSwitch += 1;
		}
		else if (mouseMoved)
			updatesSinceSwitch = 0;
	


		oldMousePosition = mousePosition;

		//update keys
		oldkeys = std::vector<int>(keys.begin(), keys.end());
		oldbuttons = std::vector<int>(buttons.begin(), buttons.end());

		Cursor::update();

		mouseMoved = false;
		scrollMovement = Vec2f();
	}

	//glfw callbacks
	void Input::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key >= 0) {
			keys[key] = action;
		}
	}

	void Input::buttonCallBack(GLFWwindow* window, int button, int action, int mods) {
		if (button >= 0) {
			buttons[button] = action;
		}
	}

	void Input::cursorPositionCallBack(GLFWwindow* window, double x, double y) {
		mousePosition.x = (float)x;
		mousePosition.y = (float)y;
		mouseMoved = true;
	}

	void Input::scrollMovementCallBack(GLFWwindow* window, double x, double y) {
		scrollMovement.x = (float)x;
		scrollMovement.y = (float)y;
	}

	void Input::windowSizeCallBack(GLFWwindow* _window, int width, int height) {
		window->size = Vec2i(width, height);
		Renderer::createProjectionMatrix((float)width, (float)height);
	}

	void Input::windowFocusCallBack(GLFWwindow* _window, int focused) {
		window->focused = (focused == 1) ? true : false;
	}

	void Input::windowPositionCallBack(GLFWwindow* _window, int x, int y) {
		window->position = Vec2i(x, y);
	}

	//keyboard input
	bool Input::getKey(const int& key) {
		return keys[key] != GLFW_RELEASE;
	}

	bool Input::getKeyDown(const int& key) {
		return (keys[key] != GLFW_RELEASE && oldkeys[key] == GLFW_RELEASE);
	}

	bool Input::getKeyUp(const int& key) {
		return (keys[key] == GLFW_RELEASE && oldkeys[key] != GLFW_RELEASE);
	}

	void Input::setClipboardText(const std::string& text) {
		OpenClipboard(0);
		EmptyClipboard();
		
		HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, text.size() + 1);

		if (!hGlobal) {
			CloseClipboard();
			Debug::systemErr("Could not set the clipboard to: " + text + ", for unknown reasons");
			return;
		}

		LPVOID temp = GlobalLock(hGlobal);
		
		if(temp != NULL)
			std::memcpy(temp, text.c_str(), text.size() + 1);

		GlobalUnlock(hGlobal);
		SetClipboardData(CF_TEXT, hGlobal);
		CloseClipboard();
		GlobalFree(hGlobal);
	}


	//mouse button input
	bool Input::getMouseButton(const int& button) {
		return buttons[button] != GLFW_RELEASE;
	}

	bool Input::getMouseButtonDown(const int& button) {
		return (buttons[button] != GLFW_RELEASE && oldbuttons[button] == GLFW_RELEASE);
	}

	bool Input::getMouseButtonUp(const int& button) {
		return (buttons[button] == GLFW_RELEASE && oldbuttons[button] != GLFW_RELEASE);
	}



	//mouse position stuff
	Vec2f Input::getMousePosition() {
		return mousePosition;
	}

	Vec2f Input::getMousePositionScreenSpace() {
		return Vec2f(mousePosition.x / Renderer::getCurrentWindowSize().x, mousePosition.y / Renderer::getCurrentWindowSize().y);
	}

	Vec2f Input::getMouseMovement() {
		return mouseMovement;
	}

	Vec2f Input::getMouseMovementScreenSpace() {
		return Vec2f(mouseMovement.x / Renderer::getCurrentWindowSize().x, mouseMovement.y / Renderer::getCurrentWindowSize().y);
	}

	void Input::setMousePosition(const Vec2f& position) {
		glfwSetCursorPos(window->window, position.x, position.y);
		mousePosition = position;
	}

	//scroll stuff
	Vec2f Input::getScrollMovement() {
		return scrollMovement;
	}

}