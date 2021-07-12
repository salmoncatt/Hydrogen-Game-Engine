
#ifndef HFR_GUI_ELEMENT_HEADER_INCLUDE
#define HFR_GUI_ELEMENT_HEADER_INCLUDE

#include HFR_API

namespace HFR {

	class DLL_API GuiElement {
	public:
		//you can give your gui items names with this
		std::string name;

		//size of the gui element (in screen space or pixels), (100, 100) by default
		Vec2f size = Vec2f(100, 100);

		//position of the gui element (in screen space or pixels), (0, 0) by default
		Vec2f position = Vec2f();

		//the rotation value of the gui element, 0 by default
		float rotation = 0;

		//the anchor point of the gui element is the origin point (0, 0) is top left, (0.5, 0.5) is center, (1, 1) is bottom right, (0, 0) by default
		Vec2f anchorPoint;

		//the size type defines whether to use screen space (opengl) coordinates, or to use pixel coordinates, (HFR_PIXEL_SIZE for pixels) (HFR_SCREEN_SPACE_SIZE for screen space), (HFR_PIXEL_SIZE) by default
		int sizeType = HFR_PIXEL_SIZE;

		//whether or not this gui element can be seen, (true) by default
		bool visible = true;

		//the parent of this gui element
		GuiElement* parent;

		//the child of this gui element
		GuiElement* child;

		GuiElement();

	};

}


#endif