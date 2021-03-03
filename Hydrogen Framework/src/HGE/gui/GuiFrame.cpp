#include "hpch.h"
#include "GuiFrame.h"
#include "HGE/core/Engine.h"

namespace HGE {

	GuiFrame::GuiFrame() {
		position = Vec2f();
		size = Vec2f();
		anchorPoint = Vec2f();

		backgroundColor = Vec4f(1);
		borderColor = Vec4f(0, 0, 0, 1);

		rotation = 0;
		sizeType = HGE_PIXEL_SIZE;
		borderSize = 5;
		
		//Engine::registerGuiFrame(&this);
	}

	GuiFrame::~GuiFrame() {
		//Engine::removeGuiFrame(this);
	}

}