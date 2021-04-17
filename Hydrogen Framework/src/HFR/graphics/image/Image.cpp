#include "hfpch.h"

namespace HFR {

	Image::Image() {
		width = 0;
		height = 0;
		channels = 0;
		data = NULL;
	}

	Image::Image(const int& _width, const int& _height, const int& _channels, unsigned char* _data) {
		width = _width;
		height = _height;
		channels = _channels;

		int allocation = width * height * channels;
		data = new unsigned char[allocation];
		std::memcpy(data, _data, allocation);
	}

	Image::Image(const Image& image) {
		width = image.width;
		height = image.height;
		channels = image.channels;

		int allocation = image.width * image.height * image.channels;
		data = new unsigned char[allocation];
		std::memcpy(data, image.data, allocation);
	}

	Image& Image::operator=(const Image& image) {
		if (this != &image && image.data != nullptr) {
			if(data != NULL)
				delete[] data;
			data = NULL;

			int allocation = image.width * image.height * image.channels;
			data = new unsigned char[allocation];
			std::memcpy(data, image.data, allocation);

			width = image.width;
			height = image.height;
			channels = image.channels;
			filepath = image.filepath;
		}

		return *this;
	}

	Image::Image(const std::string& _filepath) {
		width = 0;
		height = 0;
		channels = 0;
		data = NULL;
		filepath = _filepath;

		data = stbi_load(filepath.c_str(), &width, &height, &channels, STBI_rgb_alpha);
		channels = STBI_rgb_alpha;
		
		if (data == NULL) {
			Debug::systemErr("Couldn't load image: " + filepath);
		}
	}

	Image::~Image() {
		if (data != NULL) {
			delete[] data;
		}

		data = NULL;
	}

	void Image::generatePixelData() {
		//just in case you want to make pixel data
		//it takes a bit of processing power so that is why i made this function

		//pixeldata = std::vector<std::vector<Pixel>>(width, std::vector<Pixel>(height, Pixel()));

		//for (int x = 0; x < width; x++) {
		//	for (int y = 0; y < height; y++) {

		//		//stupid casting 4 byte value error
		//		int r = 3 * (x * height + y);
		//		int g = 3 * (x * height + y) + 1;
		//		int b = 3 * (x * height + y) + 2;

		//		pixeldata[x][y] = Pixel(data[r], data[g], data[b], (unsigned char)255);

		//	}
		//}
	}

	bool Image::hasData() const{
		return (data != NULL);
	}

}
