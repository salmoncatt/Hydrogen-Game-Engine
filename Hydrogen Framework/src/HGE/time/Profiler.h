
#ifndef HGE_PROFILER_INCLUDE
#define HGE_PROFILER_INCLUDE

#include HGE_API

namespace HGE {

	class DLL_API Profiler {
	protected:
		double startTime;

		std::string nameOfFunction;
		
		bool stopped = false;
		bool shouldLogOnStop = true;
		bool storeInDebug = true;
		bool shouldProfile = true;

		friend class Debug;
	public:

		Profiler();
		Profiler(const bool& shouldProfile);
		Profiler(const std::string& nameOfFunction);
		Profiler(const std::string& nameOfFunction, const bool& logOnStop);
		Profiler(const std::string& nameOfFunction, const bool& logOnStop, const bool& storeInDebug);
		
		/*Profiler operator+(const Profiler& other);
		Profiler operator+=(const Profiler& other);*/

		~Profiler();
		
		void stop();
		void dontLogOnStop();
		
		double getDuration() const;
	};

}

#endif