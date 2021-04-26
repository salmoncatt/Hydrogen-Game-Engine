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

	Font::Font(const Font& font) {
		//face = FreeType::loadFace(font.face);
		face = nullptr;
		size = font.size;
		atlasSize = font.atlasSize;
		path = font.path;
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

		Image imageData = Image(width, height, 4, 0);
		texture = Texture(imageData);
		texture.byteAlignment = 1;
		texture.filterMode = Vec2i(GL_LINEAR);
		texture.internalFormat = GL_RED;
		texture.format = GL_RED;
		texture.generateMipmap = false;

		texture.create();


		Vec2i offset = Vec2i();

		//load glyphs into texture

		for (int i = 32; i < 128; ++i) {
			//super sophisticated error checking algorithm
			if (FT_Load_Char(face, i, FT_LOAD_RENDER)) {
				std::string character;
				character = (char)(i);

				std::string error = ("Loading character " + character + " has failed in font: " + Util::removePathFromFilePathAndName(path));
				Debug::systemErr(error);

				continue;
			}

			if (offset.x + glyph->bitmap.width + 1 >= maxTextureWidth) {
				offset.y += rowHeight;
				rowHeight = 0;
				offset.x = 0;
			}
			
			glTexSubImage2D(GL_TEXTURE_2D, 0, offset.x, offset.y, glyph->bitmap.width, glyph->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE, glyph->bitmap.buffer);

			characters[i].advance = Vec2i(glyph->advance.x >> 6, glyph->advance.y >> 6);
			characters[i].bitmapLeftTop = Vec2i(glyph->bitmap_left, glyph->bitmap_top);
			characters[i].size = Vec2i(glyph->bitmap.width, glyph->bitmap.rows);
			characters[i].textureOffset = Vec2i(offset.x / width, offset.y / height);

		}




		if (logStatus) {
			Debug::systemSuccess("Loaded font: " + Util::removePathFromFilePathAndName(path), DebugColor::Blue);
			Debug::systemSuccess(Util::removePathFromFilePathAndName(path) + " atlas size is " + std::to_string(width) + " x " + std::to_string(height) + " pixels and is " + std::to_string(width * height / 1024) + " kb", DebugColor::Blue);
		}
	}

	void Font::loadFont(const std::string& _path) {
		if(face != nullptr)
			FT_Done_Face(face);

		face = FreeType::loadFace(_path);
		path = _path;
	}

}
