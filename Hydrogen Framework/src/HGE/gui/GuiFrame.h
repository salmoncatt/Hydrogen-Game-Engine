
#ifndef HGE_GUI_FRAME_HEADER_INCLUDE
#define HGE_GUI_FRAME_HEADER_INCLUDE

#include HGE_API
#include "GuiElement.h"
#include HGE_VEC2
#include HGE_VEC3
#include HGE_VEC4

namespace HGE {

	class DLL_API GuiFrame : public GuiElement {
	private:
		bool selected = false;
	public:
		std::string name;
		
		Vec2f position;
		Vec2f size;
		float rotation;
		Vec2f anchorPoint;

		Vec4f backgroundColor;
		Vec4f borderColor;
		
		unsigned int borderSize;

		int sizeType;
		int roundedCornerRadius = 0;
		float cornerSmoothing = 0.7f;

		bool visible = true;
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