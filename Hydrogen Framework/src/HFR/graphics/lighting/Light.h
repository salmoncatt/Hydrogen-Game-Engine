
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

		//ambient color and intensity of light
		Vec3f ambientColor = Vec3f(0.1f);

		//diffuse color and intensity of light
		Vec3f diffuseColor = Vec3f(0.5f);

		//specular color and intensity of light
		Vec3f specularColor = Vec3f(1);

		Light();
		//creates a light and auto generates the ambient, diffuse, and specular light amounts
		Light(Vec3f position, Vec3f color);
		~Light();



	};

}

#endif