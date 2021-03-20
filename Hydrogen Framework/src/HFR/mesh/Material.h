
#ifndef HFR_MATERIAL_HEADER_INCLUDE
#define HFR_MATERIAL_HEADER_INCLUDE

#include HFR_API
#include HFR_VEC3
#include HFR_TEXTURE

namespace HFR {

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
