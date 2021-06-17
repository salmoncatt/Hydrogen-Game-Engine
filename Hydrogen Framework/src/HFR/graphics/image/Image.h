

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

		//std::vector<std::vector<Pixel>> pixeldata;
		unsigned char* data;
		
		Image();
		Image(const std::string& filepath);
		Image& operator=(const Image& image);
		Image(const Image& image);
		Image(const int& width, const int& height, const int& channels, unsigned char* data);
		~Image();

		unsigned char* getPixel(const size_t& x, const size_t& y);

		//TODO
		void replacePixels(const size_t& x, const size_t& y, const size_t& width, const size_t& height, const unsigned char* data);

		//void generatePixelData();
		bool hasData() const;
	};

}

#endif