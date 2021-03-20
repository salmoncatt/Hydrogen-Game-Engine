
#ifndef HFR_PROFILE_HEADER_INCLUDE
#define HFR_PROFILE_HEADER_INCLUDE

#include HFR_API

namespace HFR {

	class DLL_API Profile {
	protected:
		size_t calls;
		double duration;

		friend class Profiler;
		friend class Debug;

	public:
		std::string name;

		Profile();
		Profile(const std::string& name);
		~Profile();

		Profile operator+(const Profile& other);
		Profile operator+=(const Profile& other);

		//returns amount of calls made to this function
		size_t getCalls();
		double getDuration();

		//resets calls and duration but not name
		void reset();

	};


}


#endif
