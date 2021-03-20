
#ifndef HFR_RANDOM_HEADER_INCLUDE
#define HFR_RANDOM_HEADER_INCLUDE

#include HFR_API

namespace HFR {

	struct Vec3f;

	class DLL_API Random {
	public:
		static double range(const int& smallest, const int& largest);

		static Vec3f rotation();
		static void setSeed(const unsigned int& seed);
		static void randomSeed();
		static void init();

	};


}

#endif

