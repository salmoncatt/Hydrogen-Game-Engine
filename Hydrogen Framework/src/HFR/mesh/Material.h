
#ifndef HFR_MATERIAL_HEADER_INCLUDE
#define HFR_MATERIAL_HEADER_INCLUDE

#include HFR_API
#include HFR_VEC3
#include HFR_TEXTURE

namespace HFR {

	struct DLL_API Material {
		std::string name;

		bool created = false;

		//float dissolve;

		Texture diffuseMap;
		Vec3f diffuseColor;

		Texture ambientMap;
		Vec3f ambientColor;

		Texture specularMap;
		Vec3f specularColor;
		float specularExponent;

		Texture emissionMap;
		Vec3f emissionColor;

		Material() {
			diffuseMap = Texture();
			diffuseColor = Vec3f(0.8f);

			ambientMap = Texture();
			ambientColor = Vec3f(0.8f);

			specularMap = Texture();
			specularColor = Vec3f(0.5f);
			specularExponent = 32;

			emissionMap = Texture();
			emissionColor = Vec3f(0);
		}

		~Material() {

		}

		void create() {
			diffuseMap.textureUnit = 0;
			ambientMap.textureUnit = 1;
			specularMap.textureUnit = 2;
			emissionMap.textureUnit = 3;

			if (diffuseMap.image.hasData())
				diffuseMap.create();

			if (ambientMap.image.hasData())
				ambientMap.create();

			if (specularMap.image.hasData())
				specularMap.create();

			if (emissionMap.image.hasData())
				emissionMap.create();

			created = true;
		}

		//shader NEEDS to be BINDED before calling this
		//void bindLightMaps(const Shader& shader) {

		//	if (diffuseMap.image.hasData()) {
		//		glActiveTexture(GL_TEXTURE0);
		//		glBindTexture(GL_TEXTURE_2D, diffuseMap.textureID);
		//		shader.setUniform("material.diffuseMap", (int)0);
		//		shader.setUniform("material.useDiffuseMap", true);
		//	}

		//	if (ambientMap.image.hasData()) {
		//		glActiveTexture(GL_TEXTURE1);
		//		shader.setUniform("material.ambientMap", (int)1);
		//		shader.setUniform("material.useAmbientMap", true);
		//		glBindTexture(GL_TEXTURE_2D, ambientMap.textureID);
		//	}

		//	if (specularMap.image.hasData()) {
		//		glActiveTexture(GL_TEXTURE2);
		//		shader.setUniform("material.specularMap", (int)2);
		//		shader.setUniform("material.useSpecularMap", true);
		//		glBindTexture(GL_TEXTURE_2D, specularMap.textureID);
		//	}

		//	if (emissionMap.image.hasData()) {
		//		glActiveTexture(GL_TEXTURE3);
		//		shader.setUniform("material.emissionMap", (int)3);
		//		shader.setUniform("material.useEmissionMap", true);
		//		glBindTexture(GL_TEXTURE_2D, emissionMap.textureID);
		//	}


		//	//material things for lighting n stuff
		//	shader.setUniform("material.diffuseColor", diffuseColor);
		//	shader.setUniform("material.ambientColor", ambientColor);
		//	shader.setUniform("material.specularColor", specularColor);
		//	shader.setUniform("material.specularExponent", specularExponent);
		//	shader.setUniform("material.emissionColor", emissionColor);
		//	//shader.setUniform("material.ambientIntensity", ambientIntensity);
		//}

	};

}


#endif
