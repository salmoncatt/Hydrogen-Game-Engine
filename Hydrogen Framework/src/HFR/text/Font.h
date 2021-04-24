
#ifndef HFR_FONT_HEADER_INCLUDE
#define HFR_FONT_HEADER_INCLUDE

#include HFR_API
#include HFR_VEC2
#include HFR_CHARACTER

namespace HFR {

	class DLL_API Font {
	public:
		FT_Face face;
		Vec2i size;
		Vec2i atlasSize;

		Texture texture;

		int maxTextureWidth = 1024;

		Character characters[128];
		//std::map<unsigned char, Character> characters;
		std::string path;

		Font();
		Font(const std::string& path);
		~Font();

		void create();
		void loadFont(const std::string& path);

	};

}



#endif
