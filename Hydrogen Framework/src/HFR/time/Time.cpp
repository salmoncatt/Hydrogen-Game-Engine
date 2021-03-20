#include "hfpch.h"

namespace HFR {

	double Time::lastFrameTime = 0;
	float Time::frameTime = 0;
	float Time::lastFPS = 1;

	double Time::getTime() {
		return (glfwGetTime() * 1000);
	}

	void Time::update() {
		frameTime = (float)((getTime() - Time::lastFrameTime) / 1000);
		lastFrameTime = getTime();
	}

	float Time::getDeltaTime() {
		return frameTime;
	}

	float Time::getFPS() {
		lastFPS = HMath::lerp(lastFPS, 1 / getDeltaTime(), 0.05f);

		return lastFPS;
	}

}
