#include "hfpch.h"
#include "GuiFrame.h"

namespace HFR {

	GuiFrame::GuiFrame() {
		position = Vec2f();
		size = Vec2f(100, 100);
		anchorPoint = Vec2f();

		backgroundColor = Vec4f(1);
		borderColor = Vec4f(0, 0, 0, 1);

		rotation = 0;
		sizeType = HFR_PIXEL_SIZE;
		borderSize = 5;

		Engine::registerGuiFrame(this);
	}

	GuiFrame::~GuiFrame() {
	
	}

	bool GuiFrame::isHovered() {
		bool x = false;
		bool y = false;

		if (sizeType == HFR_PIXEL_SIZE) {
			float xOffset = size.x * anchorPoint.x;
			float yOffset = size.y * anchorPoint.y;

			x = (Input::getMousePosition().x > position.x - xOffset && Input::getMousePosition().x < position.x + size.x - xOffset);
			y = (Input::getMousePosition().y > position.y - yOffset && Input::getMousePosition().y < position.y + size.y - yOffset);
		}
		else {

			if (Renderer::getCurrentWindowSize().x < Renderer::getCurrentWindowSize().y) {
				float xOffset = size.x * anchorPoint.x;
				float yOffset = size.y * anchorPoint.y * Renderer::getAspectRatio();

				x = (Input::getMousePositionScreenSpace().x > position.x - xOffset && Input::getMousePositionScreenSpace().x < position.x + size.x - xOffset);
				y = (Input::getMousePositionScreenSpace().y > position.y - yOffset && Input::getMousePositionScreenSpace().y < position.y + size.y * Renderer::getAspectRatio() - yOffset);
			}
			else {

				float xOffset = size.x * anchorPoint.x / Renderer::getAspectRatio();
				float yOffset = size.y * anchorPoint.y;

				x = (Input::getMousePositionScreenSpace().x > position.x - xOffset && Input::getMousePositionScreenSpace().x < position.x + size.x / Renderer::getAspectRatio() - xOffset);
				y = (Input::getMousePositionScreenSpace().y > position.y - yOffset && Input::getMousePositionScreenSpace().y < position.y + size.y - yOffset);
			}
		}

		return (x && y);
	}

	bool GuiFrame::isSelected() {
		if (selectable) {
			if (!selected) {
				selected = (isHovered() && Input::getMouseButtonDown(HFR_MOUSE_BUTTON_0));
				return selected;
			}
			else {
				selected = !Input::getMouseButtonUp(HFR_MOUSE_BUTTON_0);
				return selected;
			}
		}
		else
			return false;
	}

}