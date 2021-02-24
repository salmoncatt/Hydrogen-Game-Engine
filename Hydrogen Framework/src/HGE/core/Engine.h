
#ifndef HGE_ENGINE_HEADER_INCLUDE
#define HGE_ENGINE_HEADER_INCLUDE

#include HGE_API
#include "HGE/io/Window.h"

namespace HGE {

	class DLL_API Engine {
	public:
		static Window* window;

		static void startEngine();
		static void updateEngine();
		static void stopEngine();

	};


}


#endif
