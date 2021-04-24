#include "hfpch.h"
#include "Font.h"
#include HFR_FREETYPE
#include HFR_UTIL

namespace HFR {

	Font::Font() {
		face = nullptr;
		size = Vec2i(0, 48);
		atlasSize = Vec2i();
	}

	Font::Font(const std::string& _path) {
		face = FreeType::loadFace(_path);
		path = _path;
		size = Vec2i(0, 48);
		atlasSize = Vec2i();
	}

	Font::~Font() {
		FT_Done_Face(face);
	}

	void Font::create() {
		FT_Set_Pixel_Sizes(face, size.x, size.y);

		FT_GlyphSlot glyph = face->glyph;

		int width = 0;
		int height = 0;

		int rowWidth = 0;
		int rowHeight = 0;

		for (int i = 32; i < 128; ++i) {
			//super sophisticated error checking algorithm
			if (FT_Load_Char(face, i, FT_LOAD_RENDER)) {
				std::string character;
				character = (char)(i);

				std::string error = ("Loading character " + character + " has failed in font: " + Util::removePathFromFilePathAndName(path));
				Debug::systemErr(error);
				
				continue;
			}

			if (rowWidth + glyph->bitmap.width + 1 >= maxTextureWidth) {
				width = max(width, rowWidth);
				height += rowHeight;

				rowWidth = 0;
				rowHeight = 0;
			}

			rowWidth += glyph->bitmap.width + 1;
			rowHeight = max(height, glyph->bitmap.rows);
		}

		width = max(width, rowWidth);
		height += rowHeight;

		atlasSize = (width, height);

		texture = Texture(Image(width, height, 4, 0));
		texture.byteAlignment = 1;
		//texture.


	}

	void Font::loadFont(const std::string& _path) {
		if(face != nullptr)
			FT_Done_Face(face);

		face = FreeType::loadFace(_path);
		path = _path;
	}

}
