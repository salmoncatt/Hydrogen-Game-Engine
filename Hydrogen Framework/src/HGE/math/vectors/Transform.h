
#ifndef HGE_TRANSFORM_HEADER_INCLUDE
#define HGE_TRANSFORM_HEADER_INCLUDE

#include HGE_API
#include HGE_ECS
#include HGE_VEC2
#include HGE_VEC3

namespace HGE {

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