#include "hfpch.h"

namespace HFR {

	double Random::range(const int& smallest, const int& largest) {
		return ((rand() % largest) - (double)smallest);
	}

	Vec3f Random::rotation() {
		return Vec3f((float)range(-360, 360), (float)range(-360, 360), (float)range(-360, 360));
	}

	void Random::setSeed(const unsigned int& seed) {
		srand(seed);
	}

	void Random::randomSeed() {
		srand(rand());
	}

	void Random::init() {
		randomSeed();
		randomSeed();
		randomSeed();
	}

}