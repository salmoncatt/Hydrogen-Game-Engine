

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