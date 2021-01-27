
#ifndef HGE_TIME_INCLUDE
#define HGE_TIME_INCLUDE

#include HGE_API

namespace HGE {

	class DLL_API Time {
	private:
		static double lastFrameTime;
		static float frameTime;

		static float lastFPS;
	public:
		static void update();

		static double getTime();

		static float getDeltaTime();

		static float getFPS();
	};

}

#endif