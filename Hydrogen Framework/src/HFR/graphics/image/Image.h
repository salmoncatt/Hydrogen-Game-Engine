

#ifndef HFR_IMAGE_HEADER_INCLUDE
#define HFR_IMAGE_HEADER_INCLUDE

#include HFR_API
#include "Pixel.h"

namespace HFR {

	class DLL_API Image {
	public:
		std::string filepath;

		int width;
		int height;
		int channels;

		std::vector<std::vector<Pixel>> pixeldata;
		unsigned char* data;
		
		Image();
		Image(const std::string& filepath);
		Image& operator=(const Image& image);
		Image(const Image& image);
		~Image();

		void generatePixelData();
		bool hasData() const;
	};

}

#endif