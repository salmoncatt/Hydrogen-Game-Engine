
#ifndef HFR_TRANSFORM_HEADER_INCLUDE
#define HFR_TRANSFORM_HEADER_INCLUDE

#include HFR_API
#include HFR_ECS
#include HFR_VEC2
#include HFR_VEC3

namespace HFR {

	struct DLL_API Transform {
		Vec3f position, rotation, scale;

		Transform() : position(Vec3f()), rotation(Vec3f()), scale(Vec3f(1)) {}

		Transform(const Vec3f& _position, const Vec3f& _rotation, const Vec3f& _scale) : position(_position), rotation(_rotation), scale(_scale) {}

	};

	struct DLL_API Transform2D {
		Vec2f position, rotation, scale;

		Transform2D() : position(Vec2f()), rotation(Vec2f()), scale(Vec2f(1)) {}

		Transform2D(const Vec2f& _position, const Vec2f& _rotation, const Vec2f& _scale) : position(_position), rotation(_rotation), scale(_scale) {}

	};


}

#endif