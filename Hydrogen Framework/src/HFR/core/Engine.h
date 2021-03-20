
#ifndef HFR_ENGINE_HEADER_INCLUDE
#define HFR_ENGINE_HEADER_INCLUDE

#include HFR_API
#include HFR_WINDOW
#include HFR_GUI_FRAME

namespace HFR {

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
