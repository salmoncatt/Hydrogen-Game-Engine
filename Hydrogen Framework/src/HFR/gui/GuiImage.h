
#ifndef HFR_GUI_IMAGE_HEADER_INCLUDE
#define HFR_GUI_IMAGE_HEADER_INCLUDE

#include HFR_API
#include "GuiElement.h"
#include HFR_MATH


namespace HFR {

	class DLL_API GuiImage : GuiElement {
	public:

		//this is your actual image (set to null texture by default)
		Texture texture;

		//this adds color onto your image, alpha is the alpha value of the image (not added)
		Vec4f color = Vec4f(0, 0, 0, 1);

		//fill is for creating things like progress bars, this is for the x axis
		float xFill = 1;
		//this is the fill offset, this is for the x axis
		float xFillOffset = 0;

		//fill is for creating things like progress bars, this is for the y axis
		float yFill = 1;
		//this is the fill offset, this is for the y axis
		float yFillOffset = 0;

		//fill is for creating things like progress bars, this is for the radial axis
		float radialFill = 360;
		//this is the fill offset, this is for the radial axis
		Vec2f radialFillOffset = Vec2f();

		GuiImage();
		~GuiImage();
	};


}


#endif
