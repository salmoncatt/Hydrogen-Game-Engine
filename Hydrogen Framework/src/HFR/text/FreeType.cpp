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

		FT_Error error = FT_New_Face(ftLibrary, path.c_str(), 0, &out);

		if (error == FT_Err_Unknown_File_Format)
			Debug::systemErr("Unkown font format at: " + path);
		else if(error)
			Debug::systemErr("Couldn't load font: " + path);

		return out;
	}

}
