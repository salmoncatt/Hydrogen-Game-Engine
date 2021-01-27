
#ifndef HGE_MATERIAL_HEADER_INCLUDE
#define HGE_MATERIAL_HEADER_INCLUDE

#include HGE_API
#include "HGE/math/vectors/Vec3.h"
#include "Texture.h"

namespace HGE {

	struct DLL_API Material {
		std::string name;

		//Vec3f ambientColor;
		//Vec3f specularColor;
		//float specularExponent;
		//float dissolve;

		Texture albedoTexture;
		Vec3f albedoColor;

		Material() {
			albedoTexture = Texture();
			albedoColor = Vec3f(0.8f, 0.8f, 0.8f);
		}

		~Material() {

		}

	};

}


#endif
