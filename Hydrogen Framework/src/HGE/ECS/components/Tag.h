
#ifndef HGE_TAG_COMPONENT_HEADER_INCLUDE
#define HGE_TAG_COMPONENT_HEADER_INCLUDE

#include HGE_API

namespace HGE {

	struct DLL_API Tag {
		const char* name;

		Tag() {
			name = "";
		}

		Tag(const char* _name) {
			name = _name;
		}

		~Tag() {

		}


	};

}

#endif