#include "hpch.h"
#include "GuiWindow.h"


namespace HGE {

	GuiWindow::GuiWindow() {
		backgroundColor = Vec3f(0.1882f);
		foregroundColor = Vec3f(0.2353f);
		transform = Transform2D();
		titleBarTransform = Transform2D();
		titleBarTransform.scale = Vec2f(transform.scale.x, 20);
	}

	GuiWindow::~GuiWindow() {

	}

	void GuiWindow::setPosition(const Vec2f& position) {
		transform.position = position;
	}

	void GuiWindow::setScale(const Vec2f& scale) {
		transform.position = scale;
	}


	Vec2f GuiWindow::getPosition() {
		return transform.position;
	}

	Vec2f GuiWindow::getScale() {
		return transform.scale;
	}


	void GuiWindow::setTitleBarPosition(const Vec2f& position) {
		titleBarTransform.position = position;
	}

	void GuiWindow::setTitleBarScale(const Vec2f& scale) {
		titleBarTransform.position = scale;
	}


	Vec2f GuiWindow::getTitleBarPosition() {
		return titleBarTransform.position;
	}

	Vec2f GuiWindow::getTitleBarScale() {
		return titleBarTransform.scale;
	}

}