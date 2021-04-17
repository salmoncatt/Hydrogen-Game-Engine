

#ifndef HFR_TEXTURE_HEADER_INCLUDE
#define HFR_TEXTURE_HEADER_INCLUDE

#include HFR_API
#include HFR_IMAGE

namespace HFR {

	class DLL_API Texture {
	public:
		Image image;
		unsigned int textureID;
		bool isCreated = false;

		//mmmmmm many variables yes fun

		//1 is none, default is 4
		const int byteAlignment = 4;
		
		const int minMipmapFilter = GL_NEAREST_MIPMAP_LINEAR;
		const int magMipmapFilter = GL_NEAREST_MIPMAP_LINEAR;


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