
#ifndef HGE_PIXEL_HEADER_INCLUDE
#define HGE_PIXEL_HEADER_INCLUDE

#include HGE_API

namespace HGE {

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