
#ifndef HGE_VECTOR_THREE_HEADER_INCLUDE
#define HGE_VECTOR_THREE_HEADER_INCLUDE

#include HGE_API

namespace HGE {

	struct DLL_API Vec3f {
		float x, y, z;

		Vec3f(const float& x, const float& y, const float& z);

		Vec3f(const float& all);

		Vec3f();

		void normalize();

		float length();

		float ilength();

		Vec3f operator+(const Vec3f& other);

		Vec3f operator+=(const Vec3f& other);

		Vec3f operator-(const Vec3f& other);

		Vec3f operator-=(const Vec3f& other);

		Vec3f operator*(const Vec3f& other);

		Vec3f operator*=(const Vec3f& other);

		Vec3f operator*(const float& other);

		Vec3f operator*=(const float& other);

		static Vec3f cross(const Vec3f& left, const Vec3f& right);

	};
}

#endif