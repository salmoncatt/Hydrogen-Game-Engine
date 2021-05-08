
#ifndef HFR_FACE_HEADER_INCLUDE
#define HFR_FACE_HEADER_INCLUDE

#include HFR_API


namespace HFR {

	class DLL_API Face {
	public:
		std::string name;
		std::string path;
		FT_Face freeTypeFace = nullptr;

		Face();
		~Face();

	};



}



#endif
