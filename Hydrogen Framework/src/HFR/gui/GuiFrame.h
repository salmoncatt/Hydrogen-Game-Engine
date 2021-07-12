
#ifndef HFR_GUI_FRAME_HEADER_INCLUDE
#define HFR_GUI_FRAME_HEADER_INCLUDE

#include HFR_API
#include "GuiElement.h"
#include HFR_MATH

namespace HFR {

	class DLL_API GuiFrame : public GuiElement {
	private:
		bool selected = false;
	public:
		std::string name;
		
		Vec2f size;
		float rotation;
		Vec2f anchorPoint;

		Vec4f backgroundColor;
		Vec4f borderColor;
		
		unsigned int borderSize;

		int sizeType;
		int roundedCornerRadius = 0;
		float cornerSmoothing = 0.7f;

		bool draggable = false;
		bool active = false;
		bool selectable = false;

		GuiFrame();
		~GuiFrame();

		bool isHovered();
		bool isSelected();
	};


}


#endif