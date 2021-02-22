
#ifndef HGE_GUI_WINDOW_HEADER_INCLUDE
#define HGE_GUI_WINDOW_HEADER_INCLUDE

#include HGE_API
#include "HGE/ECS/components/Transform.h"
#include "HGE/math/vectors/Vec3.h"
#include "GuiElement.h"

namespace HGE {

	struct DLL_API GuiWindow : public GuiElement{
	public:
		Transform2D titleBarTransform;

		std::vector<GuiElement> elements = std::vector<GuiElement>();

		Vec3f backgroundColor;
		Vec3f foregroundColor;

		float cornerSmoothingRadius = 10;
		
		string title;

		bool resizable = true;

		GuiWindow();
		~GuiWindow();

		void setPosition(const Vec2f& position);
		void setScale(const Vec2f& scale);

		Vec2f getPosition();
		Vec2f getScale();

		void setTitleBarPosition(const Vec2f& position);
		void setTitleBarScale(const Vec2f& scale);

		Vec2f getTitleBarPosition();
		Vec2f getTitleBarScale();

	};


}


#endif