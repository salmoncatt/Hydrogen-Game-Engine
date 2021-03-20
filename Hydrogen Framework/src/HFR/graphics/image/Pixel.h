
#ifndef HFR_PIXEL_HEADER_INCLUDE
#define HFR_PIXEL_HEADER_INCLUDE

#include HFR_API

namespace HFR {

	class DLL_API Pixel {
	public:
		unsigned char r, g, b, a;

		Pixel() : r(0), g(0), b(0), a(0) {

		}

		Pixel(const unsigned char& red, const unsigned char& green, const unsigned char& blue, const unsigned char& alpha) : r(red), g(green), b(blue), a(alpha) {

		}

		~Pixel() {

		}



	};

}

#endif