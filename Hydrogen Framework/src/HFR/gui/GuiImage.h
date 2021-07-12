
#ifndef HFR_GUI_IMAGE_HEADER_INCLUDE
#define HFR_GUI_IMAGE_HEADER_INCLUDE

#include HFR_API
#include "GuiElement.h"
#include HFR_MATH
#include HFR_TEXTURE


namespace HFR {

	class DLL_API GuiImage : public GuiElement {
	public:

		//this is your actual image
		Texture texture;

		//this is the texture under the main texture (useful for making progress bars n stuff)
		Texture backgroundTexture;

		//this adds color onto your image, alpha is the alpha value of the image (not added)
		Vec4f color = Vec4f(0, 0, 0, 1);

		//fill is for creating things like progress bars, it is 0 - 1 how much it will fill
		Vec2f fill = Vec2f();
		//this is the fill offset, it offsets where to fill from
		Vec2f fillOffset = Vec2f();

		//fill is for creating things like progress bars, this is for the radial axis
		float radialFill = 360;
		//this is for offseting the radial fill angle
		float radialFillAngleOffset = 0;
		//this is so if you want to unfill the angle you specify
		bool radialFillInverse = false;
		//this is the fill offset, it offsets where to rotate the fill from
		Vec2f radialFillOffset = Vec2f(0.5f, 0.5f);

		GuiImage();
		~GuiImage();
	};


}


#endif
