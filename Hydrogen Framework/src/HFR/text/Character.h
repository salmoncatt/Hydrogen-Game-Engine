
#ifndef HFR_CHARACTER_HEADER_INCLUDE
#define HFR_CHARACTER_HEADER_INCLUDE

#include HFR_API
#include HFR_VEC2

namespace HFR {

	struct DLL_API Character {
		//unsigned int textureID;
		Vec2i size;
		Vec2i Offset;

		//offset amount to next glyph when rendering
		unsigned int advance;

	};


}


#endif