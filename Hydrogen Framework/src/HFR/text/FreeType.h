
#ifndef HFR_FREETYPE_HEADER_INCLUDE
#define HFR_FREETYPE_HEADER_INCLUDE

#include HFR_API

namespace HFR {

	class DLL_API FreeType {
	public:
		static FT_Library ftLibrary;

		static void init();
		static void close();

		static FT_Face loadFace(const std::string& path);
		static FT_Face loadFace(FT_Face& face);

	};


}

#endif