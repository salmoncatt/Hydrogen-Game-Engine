
#ifndef HFR_CHARACTER_HEADER_INCLUDE
#define HFR_CHARACTER_HEADER_INCLUDE

#include HFR_API
#include HFR_VEC2

namespace HFR {

	struct DLL_API Character {
		Vec2f size; //size
		Vec2f textureOffset; //offset in texture coordinates for a glyph
		Vec2f advance; //amount to offset glyph in rendering
		Vec2f bitmapLeftTop; //the top and left of the bitmap

	};


}


#endif