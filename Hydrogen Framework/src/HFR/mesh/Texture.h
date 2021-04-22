

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
		const int byteAlignment = 4;
		
		const int MipmapFilter = GL_NEAREST_MIPMAP_LINEAR;
		const int filter = GL_NEAREST;
		const Vec2i wrapMode = (GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);

		const int textureType = GL_TEXTURE_2D;

		const int internalFormat = GL_RGBA8;
		const int format = GL_RGBA;

		const int dataType = GL_UNSIGNED_BYTE;

		Texture();
		Texture(const Texture& texture);

		Texture(const std::string& path);
		Texture& operator=(const Texture& texture);
		~Texture();

		void create();
		void destroy();
	};

}


#endif