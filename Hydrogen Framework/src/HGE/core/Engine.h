
#ifndef HGE_ENGINE_HEADER_INCLUDE
#define HGE_ENGINE_HEADER_INCLUDE

#include HGE_API
#include "HGE/io/Window.h"
#include "HGE/gui/GuiFrame.h"

namespace HGE {

	class DLL_API Engine {
	public:
		static std::vector<GuiFrame*> guiFrames;
		static Window* window;

		static void startEngine();
		static void updateEngine();
		static void stopEngine();

		//gui stuff
		static void registerGuiFrame(GuiFrame* frame);
		static void removeGuiFrame(GuiFrame* frame);
		static void removeGuiFrame(const std::string& frame);

	};


}


#endif
