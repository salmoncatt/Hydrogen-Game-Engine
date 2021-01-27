
#ifndef HGE_PROFILER_INCLUDE
#define HGE_PROFILER_INCLUDE

#include HGE_API

namespace HGE {

	class DLL_API Profiler {
	private:
		double startTime;
		std::string nameOfFunction;
		bool stopped = false;
	public:
		Profiler(const std::string& nameOfFunction);
		~Profiler();
		void stop();
		float getDuration();
	};

}

#endif