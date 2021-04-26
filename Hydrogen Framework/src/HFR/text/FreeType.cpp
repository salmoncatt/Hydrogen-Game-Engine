#include "hfpch.h"
#include "FreeType.h"

namespace HFR {

	FT_Library FreeType::ftLibrary = nullptr;

	void FreeType::init() {
		if (!FT_Init_FreeType(&ftLibrary)) {
			Debug::systemSuccess("Freetype was initialized");
		}
		else
			Debug::systemErr("Couldn't initialize Freetype");
	}

	void FreeType::close() {
		if (!FT_Done_FreeType(ftLibrary)) {
			Debug::systemSuccess("Closed FreeType");
		}
		else
			Debug::systemErr("Couldn't close Freetype");
	}
	
	FT_Face FreeType::loadFace(const std::string& path) {
		FT_Face out = nullptr;

		if (FT_New_Face(ftLibrary, path.c_str(), 0, &out)) {
			Debug::systemErr("Couldn't load font: " + path);
		}

		return out;
	}

	FT_Face FreeType::loadFace(FT_Face& face) {
		FT_Face out = nullptr;

		/*if (FT_New_Memory_Face(ftLibrary, &out, sizeof(face), 0, &face)) {
			Debug::systemErr("Couldn't load font");
		}*/

		return out;
	}

}
