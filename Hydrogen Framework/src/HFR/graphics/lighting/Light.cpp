#include "hfpch.h"
#include "Light.h"


namespace HFR {

	Light::Light() {

	}

	Light::Light(Vec3f _position, Vec3f _color) {
		position = _position;
		color = _color;
	}

	Light::~Light() {

	}

}