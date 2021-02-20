#include "hpch.h"
#include "GuiWindow.h"


namespace HGE {

	GuiWindow::GuiWindow() {
		backgroundColor = Vec3f(0.1882f);
		foregroundColor = Vec3f(0.2353f);
		transform = Transform2D();
	}

	GuiWindow::~GuiWindow() {

	}

}