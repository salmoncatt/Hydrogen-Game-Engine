
#ifndef HGE_GUI_FRAME_HEADER_INCLUDE
#define HGE_GUI_FRAME_HEADER_INCLUDE

#include HGE_API
#include "GuiElement.h"
#include "HGE/math/vectors/Vec2.h"
#include "HGE/math/vectors/Vec3.h"
#include "HGE/math/vectors/Vec4.h"

namespace HGE {

	class DLL_API GuiFrame : public GuiElement {
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

		bool visible = true;
		bool draggable = false;
		bool active = false;
		bool selectable = false;

		GuiFrame();
		~GuiFrame();

		bool isHovered();

		//bool isSelected();
	};


}


#endif