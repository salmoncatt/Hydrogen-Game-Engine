
#ifndef HFR_LIGHT_HEADER_INCLUDE
#define HFR_LIGHT_HEADER_INCLUDE


#include HFR_API
#include HFR_MATH

namespace HFR {

	class DLL_API Light {
	private:
	public:

		//position of light, default is (0,0,0)
		Vec3f position = Vec3f();

		//color of light, default is (1,1,1)
		Vec3f color = Vec3f(1);

		Light();
		Light(Vec3f position, Vec3f color);
		~Light();



	};

}

#endif