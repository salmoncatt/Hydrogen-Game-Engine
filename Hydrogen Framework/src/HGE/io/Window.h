

#ifndef HGE_WINDOW_HEADER_INCLUDE
#define HGE_WINDOW_HEADER_INCLUDE

#include HGE_API

#include "HGE/math/vectors/Vec2.h"

namespace HGE {

	struct Vec4f;
	class Image;

	class DLL_API Window{
	private:
		bool focused = false;
		bool vsync = false;
		//int refreshRate = 60;

	public:
		GLFWwindow* window;
		Vec2i size, position;
		std::string name;

		Window(const Vec2i& _size, const std::string& _Name);
		~Window();

		void create();
		void update();
		void setBackGroundColor(const Vec4f& color);
		void limitFps(const int& fps);
		void setVSync(const bool& sync);
		bool isVSync();
		//void setRefreshRate(const int& rate);
		//int getRefreshRate();
		void resize(const Vec2i& size);
		void setPosition(const Vec2i& position);
		void setIcon(Image& image);
		bool isFocused();

		bool shouldClose();

		friend class Input;
	};

}

#endif