#include "hpch.h"
#include "Texture.h"
#include "HGE/util/Debug.h"

namespace HGE {

	Texture::Texture() {
		textureID = 0;
	}

	Texture::Texture(const Texture& texture) : image(texture.image){
		textureID = 0;
	}

	Texture::Texture(const std::string& path) : image(path) {
		textureID = 0;
	}

	Texture::~Texture() {
		destroy();
	}

	void Texture::destroy() {
		glDeleteTextures(1, &textureID);
	}

	void Texture::create() {
		if (!isCreated && !image.data.empty()) {

			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

			unsigned char* pixelbuffer = new unsigned char[image.data.size()];
			std::copy(image.data.begin(), image.data.end(), pixelbuffer);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelbuffer);
			glGenerateMipmap(GL_TEXTURE_2D);

			delete[] pixelbuffer;
			isCreated = true;
		}
	}

}