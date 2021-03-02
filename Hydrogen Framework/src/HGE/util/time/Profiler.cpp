#include "hpch.h"
#include "Profiler.h"
#include "Time.h"
#include "../Debug.h"

namespace HGE {

	Profiler::Profiler() {
		shouldProfile = false;
		startTime = 0;
	}

	Profiler::Profiler(const std::string& _nameOfFunction) {
		nameOfFunction = _nameOfFunction;
		startTime = Time::getTime();
	}

	Profiler::Profiler(const bool& _shouldProfile) {
		shouldProfile = _shouldProfile;
		startTime = Time::getTime();
	}
	
	Profiler::Profiler(const std::string& _nameOfFunction, const bool& logOnStop) {
		nameOfFunction = _nameOfFunction;
		shouldLogOnStop = logOnStop;
		startTime = Time::getTime();
	}
	
	Profiler::Profiler(const std::string& _nameOfFunction, const bool& logOnStop, const bool& _storeInDebug) {
		nameOfFunction = _nameOfFunction;
		shouldLogOnStop = logOnStop;
		storeInDebug = _storeInDebug;
		startTime = Time::getTime();
	}

	Profiler::~Profiler() {
		if(!stopped)
		stop();
	}

	double Profiler::getDuration() const{
		return Time::getTime() - startTime;
	}

	void Profiler::stop() {
		if (shouldProfile) {
			
			if (shouldLogOnStop) {
				std::string Duration = std::to_string(getDuration());
				Debug::log(nameOfFunction + " ms: " + Duration);
			}

			if (storeInDebug) {
				Profile p(nameOfFunction);
				p.duration = getDuration();
				p.calls = 1;
				Debug::storeProfile(p);
			}

			stopped = true;
		}
	}

	void Profiler::dontLogOnStop() {
		shouldLogOnStop = false;
	}

}