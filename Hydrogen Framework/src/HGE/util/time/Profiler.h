
#ifndef HGE_PROFILER_INCLUDE
#define HGE_PROFILER_INCLUDE

#include HGE_API

namespace HGE {

	class DLL_API Profiler {
	private:
		double startTime;
		std::string nameOfFunction;
		bool stopped = false;
		bool shouldLogOnStop = true;
	public:
		Profiler(const std::string& nameOfFunction);
		Profiler(const std::string& nameOfFunction, const bool& logOnStop);
		~Profiler();
		void stop();
		void dontLogOnStop();
		float getDuration();
	};

}

#endif