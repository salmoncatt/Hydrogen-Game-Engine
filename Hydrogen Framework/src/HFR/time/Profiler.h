
#ifndef HFR_PROFILER_INCLUDE
#define HFR_PROFILER_INCLUDE

#include HFR_API

namespace HFR {

	class DLL_API Profiler {
	protected:
		double startTime;

		std::string nameOfFunction;
		
		bool stopped = false;
		bool shouldLogOnStop = true;
		bool storeInDebug = true;

		friend class Debug;
	public:

		Profiler();
		Profiler(const std::string& nameOfFunction);
		Profiler(const std::string& nameOfFunction, const bool& logOnStop);
		Profiler(const std::string& nameOfFunction, const bool& logOnStop, const bool& storeInDebug);

		~Profiler();
		
		void stop();
		void dontLogOnStop();
		
		double getDuration() const;
	};

}

#endif