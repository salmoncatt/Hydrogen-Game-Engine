
#ifndef HFR_MATERIAL_HEADER_INCLUDE
#define HFR_MATERIAL_HEADER_INCLUDE

#include HFR_API
#include HFR_VEC3
#include HFR_TEXTURE

namespace HFR {

	struct DLL_API Material {
		std::string name;

		//float dissolve;

		Texture diffuseMap;
		Vec3f diffuseColor;
		
		Vec3f specularColor;
		float specularExponent;

		Vec3f ambientColor;

		Material() {
			diffuseMap = Texture();
			diffuseColor = Vec3f(0.8f);
			specularColor = Vec3f(0.5f);
			ambientColor = Vec3f(0.8f);
			specularExponent = 32;
		}

		~Material() {

		}

	};

}


#endif
