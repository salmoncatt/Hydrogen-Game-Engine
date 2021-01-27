#include "hpch.h"
#include "GuiWindow.h"


namespace HGE {

	const Vec3f GuiWindow::backgroundColor = Vec3f(48 / 255);
	const Vec3f GuiWindow::foregroundColor = Vec3f(60 / 255);


	GuiWindow::GuiWindow() : transform(Transform2D()){}

	GuiWindow::~GuiWindow() {

	}

}