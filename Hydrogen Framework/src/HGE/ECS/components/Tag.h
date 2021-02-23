
#ifndef HGE_TAG_COMPONENT_HEADER_INCLUDE
#define HGE_TAG_COMPONENT_HEADER_INCLUDE

#include HGE_API

namespace HGE {

	struct DLL_API Tag {
		std::string name;

		Tag() {
			name = "";
		}

		Tag(const std::string& _name) {
			name = _name;
		}

		~Tag() {

		}


	};

}

#endif