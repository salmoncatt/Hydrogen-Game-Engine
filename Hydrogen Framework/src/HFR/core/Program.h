
#ifndef HFR_PROGRAM_HEADER_INCLUDE
#define HFR_PROGRAM_HEADER_INCLUDE


#include HFR_API
#include HFR_WINDOW

namespace HFR {

	class DLL_API Program {
	protected:
		Window* window;
	public:

		Program();
		virtual ~Program();

		//void startEngine();
		//void updateEngine();
		//void closeEngine();
		
		virtual void create();
		virtual void start();
		bool shouldUpdate();
	};

	Program* createProgram();
}


#endif