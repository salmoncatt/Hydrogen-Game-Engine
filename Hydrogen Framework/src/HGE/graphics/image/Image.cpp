#include "hpch.h"
#include "Image.h"
#include "Pixel.h"
#include "HGE/util/Util.h"
#include "HGE/util/Debug.h"
#include "HGE/util/time/Profiler.h"

namespace HGE {

	Image::Image() {
		width = 0;
		height = 0;
		rowLength = 0;
	}

	Image::Image(const std::string& filepath) {
		width = 0;
		height = 0;
		rowLength = 0;

		//get all of the data
		std::vector<unsigned char> filedata = Util::readAsUnsignedChar(filepath, HGE_BINARY_READ);

		if (!filedata.empty()) {
			//bmp file has BM as first two bytes
			if (filedata[0] == 'B' && filedata[1] == 'M') {
				//isolate header from pixel data
				std::vector<unsigned char> header(filedata.begin(), filedata.begin() + 54);

				width = *(int*)&header[18];
				height = *(int*)&header[22];

				//rows have byte padding
				rowLength = (width * 3 + 3) & (~3);

				//raw pixel data, isolate from header
				data = std::vector<unsigned char>(filedata.begin() + 54, filedata.end());

				//flip
				flipVertically();

			}
			else
				Debug::systemErr(filepath + ": cannot be read, Hydrogen Game Engine only supports: .bmp files");
		}

	}

	Image::~Image() {
	}

	void Image::generatePixelData() {
		//just in case you want to make pixel data
		//it takes a bit of processing power so that is why i made this function

		pixeldata = std::vector<std::vector<Pixel>>(width, std::vector<Pixel>(height, Pixel()));

		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {

				//stupid casting 4 byte value error
				int r = 3 * (x * height + y);
				int g = 3 * (x * height + y) + 1;
				int b = 3 * (x * height + y) + 2;

				pixeldata[x][y] = Pixel(data[r], data[g], data[b], (unsigned char)255);

			}
		}
	}

	void Image::flipVertically() {
		for (int y = 0; y < height / 2; y++) {

			int spot = (y * rowLength);

			std::vector<unsigned char> row(data.begin() + spot, data.begin() + spot + rowLength);

			//bmp stores in little endian, so i need to flip from BGR TO RGB
			//also i do the flip here because there was an issue with byte padding causing color to go haywire
			for (int i = 0; i < width * 3; i += 3) {
				//stupid warnings
				int r = i;
				int b = i + 2;

				unsigned char tmp = row[r];
				row[r] = row[b];
				row[b] = tmp;


			}

			for (int i = 0; i < rowLength; i++) {

				int current = i + (y * rowLength);
				int flipped = i + ((height - y - 1) * rowLength);

				//flip row with other
				data[current] = data[flipped];

				//set the row we flipped with with the other row
				data[flipped] = row[i];
			}

			//do the flip again because we flip half with the other half
			for (int i = 0; i < width * 3; i += 3) {
				//stupid warnings
				int r = i + spot;
				int b = i + 2 + spot;

				unsigned char tmp = data[r];
				data[r] = data[b];
				data[b] = tmp;

			}



		}

	}

}
