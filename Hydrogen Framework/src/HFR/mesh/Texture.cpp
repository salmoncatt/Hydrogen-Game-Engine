#include "hfpch.h"

namespace HFR {

	Texture::Texture() {
		textureID = 0;
		image = Image();
	}

	Texture::Texture(const Image& _image) {
		image = _image;
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
		if (!isCreated) {

			//glActiveTexture(GL_TEXTURE0);
			glGenTextures(1, &textureID);
			glBindTexture(textureType, textureID);

			glPixelStorei(GL_UNPACK_ALIGNMENT, byteAlignment);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMode.x);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMode.y);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode.x);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode.y);

			if (image.data != nullptr)
				glTexImage2D(textureType, 0, internalFormat, image.width, image.height, 0, format, dataType, image.data);
			else
				glTexImage2D(textureType, 0, internalFormat, image.width, image.height, 0, format, dataType, 0);

			if(generateMipmap)
				glGenerateMipmap(textureType);

			isCreated = true;

			glBindTexture(textureType, 0);
		}
	}

}