
#ifndef HGE_VECTOR_FOUR_HEADER_INCLUDE
#define HGE_VECTOR_FOUR_HEADER_INCLUDE

#include HGE_API

namespace HGE {

	struct DLL_API Vec4f {
		float x, y, z, w;

		Vec4f(const float &_x, const float &_y, const float& _z, const float &_w) : x(_x), y(_y), z(_z), w(_w) {}

		Vec4f() : x(0), y(0), z(0), w(0) {}
		
		Vec4f(const float& value) : x(value), y(value), z(value), w(value) {}

		//Vec3f xyz() { return Vec3f(x, y, z); }

	};
}

#endif
