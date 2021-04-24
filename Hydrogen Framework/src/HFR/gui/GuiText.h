
#ifndef HFR_GUI_TEXT_HEADER_INCLUDE
#define HFR_GUI_TEXT_HEADER_INCLUDE


#include HFR_API


namespace HFR {

	class DLL_API GuiText {
	protected:
		static unsigned int staticVBO;
		static unsigned int textureCoordAttribute;

		friend class Renderer;
		friend class Engine;

		static void init();

	public:



	};


}


#endif