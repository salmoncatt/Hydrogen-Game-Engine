
#ifndef HFR_GUI_ELEMENT_HEADER_INCLUDE
#define HFR_GUI_ELEMENT_HEADER_INCLUDE

#include HFR_API

namespace HFR {

	class DLL_API GuiElement {
	public:
		//you can give your gui items names with this
		std::string name;

		//size of the gui element (in screen space or pixels)
		Vec2f size;

		//position of the gui element (in screen space or pixels)
		Vec2f position;

		//the rotation value of the gui element
		float rotation;

		//the anchor point of the gui element is the origin point (0, 0) is top left, (0.5, 0.5) is center, (1, 1) is bottom right
		Vec2f anchorPoint;

		//the size type defines whether to use screen space (opengl) coordinates, or to use pixel coordinates, (HFR_PIXEL_SIZE for pixels) (HFR_SCREEN_SPACE_SIZE for screen space)
		int sizeType;

		//the parent of this gui element
		GuiElement* parent;

		//the child of this gui element
		GuiElement* child;

		GuiElement();

	};

}


#endif