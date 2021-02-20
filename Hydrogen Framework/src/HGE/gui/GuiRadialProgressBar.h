
#ifndef HGE_GUI_RADIAL_PROGRESS_BAR_HEADER_INCLUDE
#define HGE_GUI_RADIAL_PROGRESS_BAR_HEADER_INCLUDE

#include HGE_API
#include "GuiElement.h"
#include "HGE/math/vectors/Vec3.h"
#include "HGE/ECS/components/Transform.h"
#include "HGE/ECS/components/Texture.h"


namespace HGE {

	class DLL_API GuiRadialProgressBar : public GuiElement {
	private:
	
	public:
		Transform2D barTransform;

		Vec3f backgroundColor;
		Vec3f foregroundColor;
		
		Texture backgroundTexture;
		Texture foregroundTexture;

		float angleFillAmount = 0;
		float offset = 0;
		bool flipped = 0;

		GuiRadialProgressBar();
		~GuiRadialProgressBar();

	};

}



#endif