

#ifndef HFR_TEXTURE_HEADER_INCLUDE
#define HFR_TEXTURE_HEADER_INCLUDE

#include HFR_API
#include HFR_IMAGE
#include HFR_MATH

namespace HFR {

	class DLL_API Texture {
	public:
		Image image;
		unsigned int textureID;
		bool isCreated = false;

		//mmmmmm many variables yes fun

		//1 is none, default is 4
		int byteAlignment = 4;

		Vec2i wrapMode = (GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
		Vec2i filterMode = (GL_NEAREST_MIPMAP_LINEAR, GL_NEAREST);

		int textureType = GL_TEXTURE_2D;

		int internalFormat = GL_RGBA8;
		int format = GL_RGBA;

		int dataType = GL_UNSIGNED_BYTE;

		bool generateMipmap = true;

		int textureUnit = 0;

		Texture();
		Texture(const Image& image);
		Texture(const Texture& texture);

		Texture(const std::string& path);
		Texture& operator=(const Texture& texture);
		~Texture();

		void create();
		void destroy();
		void setSubImage(const int& level, const Vec2i& offset, const Vec2i& size, const void* pixels);
	};

}


#endif