
#ifndef HGE_GUI_WINDOW_HEADER_INCLUDE
#define HGE_GUI_WINDOW_HEADER_INCLUDE

#include HGE_API
#include "HGE/ECS/components/Transform.h"
#include "HGE/math/vectors/Vec3.h"
#include "GuiElement.h"

namespace HGE {

	struct DLL_API GuiWindow : public GuiElement{
	public:

		GuiWindow();
		~GuiWindow();


		const static Vec3f backgroundColor;
		const static Vec3f foregroundColor;

	};


}


#endif