
#ifndef HFR_GUI_TEXT_HEADER_INCLUDE
#define HFR_GUI_TEXT_HEADER_INCLUDE


#include HFR_API

#include HFR_MESH
#include HFR_TRANSFORM
#include HFR_FONT

namespace HFR {

	class DLL_API GuiText {
	public:
		Mesh mesh;
		Transform2D transform;

		std::string text;

		Font font;

		Vec4f color = Vec4f(0, 0, 0, 1);

		GuiText();
		~GuiText();
		GuiText(const std::string& text, const Font& font, const Transform2D& transform);

		void create();

	};


}


#endif