
#ifndef HFR_FONT_HEADER_INCLUDE
#define HFR_FONT_HEADER_INCLUDE

#include HFR_API
#include HFR_VEC2
#include HFR_CHARACTER
#include HFR_TEXTURE

namespace HFR {

	class Face;

	class DLL_API Font {
	public:
		Vec2i size;
		Vec2i atlasSize;

		Texture texture;

		int maxTextureWidth = 1024;

		bool logStatus = true;

		Character characters[128];
		//std::map<unsigned char, Character> characters;
		std::string path;
		std::string name;

		Font();
		Font(const std::string& path);
		~Font();

		void create();

	};

}



#endif
