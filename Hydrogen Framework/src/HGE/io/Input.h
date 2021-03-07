

#ifndef HGE_INPUT_HEADER_INCLUDE
#define HGE_INPUT_HEADER_INCLUDE

#include HGE_API
#include HGE_WINDOW
#include HGE_VEC2

namespace HGE {

	class DLL_API Input {
	private:

		//arbitrary stuff
		static Window* window;

		static Vec2f mousePosition;
		static Vec2f oldMousePosition;
		static Vec2f mouseMovement;

		static Vec2f scrollMovement;

		//damn glfw mouse bug
		static bool mouseMoved;
		static int updatesSinceSwitch;

		//button and key vectors
		static std::vector<int> keys;
		static std::vector<int> oldkeys;
		static std::vector<int> buttons;
		static std::vector<int> oldbuttons;

		//glfw callbacks
		static void setCallbacks(GLFWwindow* Window);

		static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void buttonCallBack(GLFWwindow* window, int button, int action, int mods);
		static void cursorPositionCallBack(GLFWwindow* window, double x, double y);
		static void scrollMovementCallBack(GLFWwindow* window, double x, double y);
		static void windowSizeCallBack(GLFWwindow* window, int width, int height);
		static void windowPositionCallBack(GLFWwindow* window, int x, int y);
		static void windowFocusCallBack(GLFWwindow* window, int focused);
		//need to add scroll call backs n stuff

		static void createKeyVectors();

	public:
		static void update();
		static void setWindow(Window* Window);
		static Window* getCurrentWindow();
		static void setRawInput(const bool& in);

		//i love taking method names from unity :)
		static bool getKey(const int& key);
		static bool getKeyDown(const int& key);
		static bool getKeyUp(const int& key);
		static bool getMouseButton(const int& button);
		static bool getMouseButtonDown(const int& button);
		static bool getMouseButtonUp(const int& button);
		static void setClipboardText(const std::string& text);

		//mouse numbers n stuff
		static Vec2f getMousePosition();
		static Vec2f getMousePositionScreenSpace();
		static Vec2f getMouseMovement();
		static Vec2f getMouseMovementScreenSpace();
		static void setMousePosition(const Vec2f& position);

		//scroll n stuff
		static Vec2f getScrollMovement();
	};

}
#endif