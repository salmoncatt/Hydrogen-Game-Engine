#include "hfpch.h"
#include "GuiImage.h"

namespace HFR {

	GuiImage::GuiImage() {
		position = Vec2f();
		size = Vec2f(100, 100);
		anchorPoint = Vec2f();
		visible = true;
		rotation = 0;
		sizeType = HFR_PIXEL_SIZE;
		
		color = Vec4f(0, 0, 0, 1);
		radialFill = 360;
		radialFillAngleOffset = 0;
		radialFillInverse = false;
		radialFillOffset = Vec2f(0.5f, 0.5f);

		fill = Vec2f(1, 1);
		fillOffset = Vec2f();

		Engine::registerGuiImage(this);
	}

	GuiImage::~GuiImage() {

	}

}
