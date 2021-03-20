#include "hfpch.h"


namespace HFR {


	Profile::Profile() {
		duration = 0;
		calls = 0;
	}
	
	Profile::Profile(const std::string& _name) {
		name = _name;
		duration = 0;
		calls = 0;
	}

	Profile::~Profile() {

	}

	Profile Profile::operator+(const Profile& other) {
		Profile out = Profile(name);

		out.duration = duration + other.duration;
		out.calls = calls + other.calls;

		return out;
	}
	Profile Profile::operator+=(const Profile& other) {
		duration += other.duration;
		calls += other.calls;
		return *this;
	}

	size_t Profile::getCalls() {
		return calls;
	}

	double Profile::getDuration() {
		return duration;
	}

	void Profile::reset() {
		duration = 0;
		calls = 0;
	}

}