#include "hpch.h"
#include "Texture.h"
#include "HGE/util/Debug.h"

namespace HGE {

	Texture::Texture() {
		textureID = 0;
	}

	Texture::Texture(const Texture& texture) : image(texture.image){
		image = Image(texture.image);
		textureID = 0;
	}

	Texture::Texture(const std::string& path) : image(path) {
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

			//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data);

			glGenerateMipmap(GL_TEXTURE_2D);

			isCreated = true;
		}
	}

}