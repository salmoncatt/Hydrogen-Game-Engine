
#ifndef HGE_GUI_WINDOW_HEADER_INCLUDE
#define HGE_GUI_WINDOW_HEADER_INCLUDE

#include HGE_API
#include "HGE/ECS/components/Transform.h"
#include "HGE/math/vectors/Vec3.h"

namespace HGE {

	class DLL_API GuiWindow {
	public:
		Transform2D transform;


		GuiWindow();
		~GuiWindow();


		const static Vec3f backgroundColor;
		const static Vec3f foregroundColor;

	};


}


#endif