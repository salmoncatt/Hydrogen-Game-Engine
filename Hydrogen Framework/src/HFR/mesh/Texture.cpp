#include "hfpch.h"

namespace HFR {

	Texture::Texture() {
		textureID = 0;
	}

	Texture::Texture(const Texture& texture) {
		image = Image(texture.image);
		textureID = 0;
	}

	Texture::Texture(const std::string& path) {
		image = Image(path);
		textureID = 0;
	}

	Texture& Texture::operator=(const Texture& texture) {
		textureID = texture.textureID;
		image = texture.image;

		return *this;
	}

	Texture::~Texture() {
		destroy();
	}

	void Texture::destroy() {
		glDeleteTextures(1, &textureID);
	}

	void Texture::create() {
		if (!isCreated && image.hasData()) {

			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);

			glPixelStorei(GL_UNPACK_ALIGNMENT, byteAlignment);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MipmapFilter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode.x);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode.y);

			glTexImage2D(textureType, 0, internalFormat, image.width, image.height, 0, format, dataType, image.data);

			glGenerateMipmap(GL_TEXTURE_2D);

			isCreated = true;
		}
	}

}