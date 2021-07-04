
#ifndef HFR_LIGHT_HEADER_INCLUDE
#define HFR_LIGHT_HEADER_INCLUDE


#include HFR_API
#include HFR_MATH

namespace HFR {

	class DLL_API Light {
	private:
	public:

		Vec3f position;
		Vec3f color;

		Light();
		~Light();

	};

}

#endif