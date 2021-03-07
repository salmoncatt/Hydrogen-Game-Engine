#include "hpch.h"


namespace HGE {

	Camera::Camera() {
		position = Vec3f();
		rotation = Vec3f();
	}

	Camera::Camera(const Vec3f& _position, const Vec3f& _rotation) {
		position = _position;
		rotation = _rotation;
	}

	Camera::~Camera() {

	}

}