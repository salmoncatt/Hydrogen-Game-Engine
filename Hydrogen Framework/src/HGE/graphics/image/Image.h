

#ifndef HGE_IMAGE_HEADER_INCLUDE
#define HGE_IMAGE_HEADER_INCLUDE

#include HGE_API
#include "Pixel.h"

namespace HGE {

	class DLL_API Image {
	public:
		int width;
		int height;
		int rowLength;

		std::vector<std::vector<Pixel>> pixeldata;
		std::vector<unsigned char> data;
		
		Image();
		Image(const std::string& filepath);
		~Image();

		void generatePixelData();
		void flipHorizontally();
		void flipVertically();
	};

}

#endif