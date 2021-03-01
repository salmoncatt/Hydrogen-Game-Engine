
#ifndef HGE_GUI_ELEMENT_HEADER_INCLUDE
#define HGE_GUI_ELEMENT_HEADER_INCLUDE

#include HGE_API
#include "HGE/ECS/components/Transform.h"

namespace HGE {

	class DLL_API GuiElement {
	public:
		Transform2D transform;
		GuiElement* parent;

		GuiElement();

	};

}


#endif