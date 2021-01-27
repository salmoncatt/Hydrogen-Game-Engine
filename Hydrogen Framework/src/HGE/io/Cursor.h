
#ifndef HGE_CURSOR_HEADER_INCLUDE
#define HGE_CURSOR_HEADER_INCLUDE

#include HGE_API

namespace HGE {

	class DLL_API Cursor {
	private:
		static bool state;
		static bool oldState;

		static void update();
	public:
		static void setMouseState(const bool& state);
		static void toggleMouseState();
		static bool getMouseState();

		friend class Input;
	};

}


#endif
