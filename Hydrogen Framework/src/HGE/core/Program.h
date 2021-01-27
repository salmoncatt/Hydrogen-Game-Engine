
#ifndef HGE_PROGRAM_HEADER_INCLUDE
#define HGE_PROGRAM_HEADER_INCLUDE


#include HGE_API
#include "HGE/io/Window.h"

namespace HGE {

	class DLL_API Program {
	public:
		Window* window;
		Program();
		virtual ~Program();

		void startEngine();
		void updateEngine();
		void closeEngine();
		
		virtual void create();
		virtual void start();
		bool shouldUpdate();
	};

	Program* createProgram();
}


#endif