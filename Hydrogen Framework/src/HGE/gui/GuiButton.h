
#ifndef HGE_GUI_BUTTON_HEADER_INCLUDE
#define HGE_GUI_BUTTON_HEADER_INCLUDE

#include HGE_API
#include "GuiElement.h"
#include "HGE/ECS/components/Transform.h"

namespace HGE {

	struct DLL_API GuiButton : public GuiElement {
		Transform2D transform;
		bool pressed, hovered;

		GuiButton() : transform(Transform2D()), pressed(false), hovered(false){}



	};

}

#endif