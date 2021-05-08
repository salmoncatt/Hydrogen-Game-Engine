#include "hfpch.h"
#include "Font.h"
#include HFR_FREETYPE
#include HFR_UTIL
#include "Face.h"

namespace HFR {

	Font::Font() {
		size = Vec2i(0, 48);
		atlasSize = Vec2i();
	}

	Font::~Font() {
         
	}

	void Font::create(Face* face) {
		FT_Set_Pixel_Sizes(face->freeTypeFace, size.x, size.y);

		FT_GlyphSlot glyph = face->freeTypeFace->glyph;

		unsigned int width = 0;
		unsigned int height = 0;

		unsigned int rowWidth = 0;
		unsigned int rowHeight = 0;

		for (int i = 32; i < 128; ++i) {
			//super sophisticated error checking algorithm
			if (FT_Load_Char(face->freeTypeFace, i, FT_LOAD_RENDER)) {
				std::string character;
				character = (char)(i);

				std::string error = ("Loading character " + character + " has failed in font: " + name);
				Debug::systemErr(error);
				
				continue;
			}

			if (rowWidth + glyph->bitmap.width + 1 >= (unsigned int)maxTextureWidth) {
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
			if (FT_Load_Char(face->freeTypeFace, i, FT_LOAD_RENDER)) {
				std::string character;
				character = (char)(i);

				std::string error = ("Loading character " + character + " has failed in font: " + Util::removePathFromFilePathAndName(path));
				Debug::systemErr(error);

				continue;
			}

			if (offset.x + glyph->bitmap.width + 1 >= (unsigned int)maxTextureWidth) {
				offset.y += rowHeight;
				rowHeight = 0;
				offset.x = 0;
			}
			
			glTexSubImage2D(GL_TEXTURE_2D, 0, offset.x, offset.y, glyph->bitmap.width, glyph->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE, glyph->bitmap.buffer);

			characters[i].advance = Vec2f((float)(glyph->advance.x >> 6), (float)(glyph->advance.y >> 6));
			characters[i].bitmapLeftTop = Vec2f((float)glyph->bitmap_left, (float)glyph->bitmap_top);
			characters[i].size = Vec2f((float)glyph->bitmap.width, (float)glyph->bitmap.rows);
			characters[i].textureOffset = Vec2f((float)(offset.x / width), (float)(offset.y / height));

		}

		if (logStatus) {
			Debug::systemSuccess("Loaded font: " + Util::removePathFromFilePathAndName(path), DebugColor::Blue);
			Debug::systemSuccess(Util::removePathFromFilePathAndName(path) + " atlas size is " + std::to_string(width) + " x " + std::to_string(height) + " pixels and is " + std::to_string(width * height / 1024) + " kb", DebugColor::Blue);
		}
	}

}
