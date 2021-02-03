#include "hpch.h"
#include "Profiler.h"
#include "Time.h"
#include "../Debug.h"

namespace HGE {

	Profiler::Profiler(const std::string &_nameOfFunction) {
		nameOfFunction = _nameOfFunction;
		startTime = Time::getTime();
	}
	
	Profiler::Profiler(const std::string& _nameOfFunction, const bool& logOnStop) {
		nameOfFunction = _nameOfFunction;
		shouldLogOnStop = logOnStop;
		startTime = Time::getTime();
	}

	Profiler::~Profiler() {
		if(!stopped)
		stop();
	}

	float Profiler::getDuration() {
		return (float)(Time::getTime() - startTime);
	}

	void Profiler::stop() {
		if (shouldLogOnStop) {
			std::string Duration = std::to_string(getDuration());
			Debug::log(nameOfFunction + " ms: " + Duration);
		}
		stopped = true;
	}

	void Profiler::dontLogOnStop() {
		shouldLogOnStop = false;
	}

}