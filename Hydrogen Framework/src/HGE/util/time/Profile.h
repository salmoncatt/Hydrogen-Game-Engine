
#ifndef HGE_PROFILE_HEADER_INCLUDE
#define HGE_PROFILE_HEADER_INCLUDE

#include HGE_API

namespace HGE {

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

	};


}


#endif
