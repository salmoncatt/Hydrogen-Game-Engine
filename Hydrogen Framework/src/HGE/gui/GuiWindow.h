
#ifndef HGE_GUI_WINDOW_HEADER_INCLUDE
#define HGE_GUI_WINDOW_HEADER_INCLUDE

#include HGE_API
#include "HGE/ECS/components/Transform.h"
#include "HGE/math/vectors/Vec3.h"
#include "GuiElement.h"

namespace HGE {

	struct DLL_API GuiWindow : public GuiElement{
	public:

		std::vector<GuiElement> elements = std::vector<GuiElement>();

		Vec3f backgroundColor;
		Vec3f foregroundColor;
		
		float titleBarHeight = 20;
		float cornerSmoothingRadius = 10;
		
		string title;

		bool resizable = true;

		GuiWindow();
		~GuiWindow();

	};


}


#endif