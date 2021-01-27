

#ifndef HGE_TEXTURE_HEADER_INCLUDE
#define HGE_TEXTURE_HEADER_INCLUDE

#include HGE_API
#include "HGE/graphics/image/Image.h"

namespace HGE {

	class DLL_API Texture {
	public:
		Image image;
		unsigned int textureID;
		bool isCreated = false;

		Texture();
		Texture(const Texture& texture);
		Texture(const std::string& path);
		~Texture();

		void create();
		void destroy();
	};

}


#endif