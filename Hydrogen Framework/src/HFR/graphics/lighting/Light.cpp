#include "hfpch.h"
#include "Light.h"


namespace HFR {

	Light::Light() {

	}

	Light::Light(Vec3f _position, Vec3f color) {
		position = _position;
		diffuseColor = color * 0.5f;
		specularColor = color;
		ambientColor = color * 0.1f;
		usePerPixelLighting = true;
	}

	Light::~Light() {

	}

}