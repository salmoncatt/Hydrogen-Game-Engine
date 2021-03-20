
#ifndef HFR_TIME_INCLUDE
#define HFR_TIME_INCLUDE

#include HFR_API

namespace HFR {

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