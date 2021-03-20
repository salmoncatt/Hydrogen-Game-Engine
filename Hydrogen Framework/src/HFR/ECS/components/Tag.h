
#ifndef HFR_TAG_COMPONENT_HEADER_INCLUDE
#define HFR_TAG_COMPONENT_HEADER_INCLUDE

#include HFR_API

namespace HFR {

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