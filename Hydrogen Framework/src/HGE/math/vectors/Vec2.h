

#ifndef HGE_VECTOR_TWO_HEADER_INCLUDE
#define HGE_VECTOR_TWO_HEADER_INCLUDE

#include HGE_API

namespace HGE {

	struct DLL_API Vec2i {
		int x, y;

		Vec2i(const int& x, const int& y);

		Vec2i(const int& all);

		Vec2i();

		Vec2i operator-(const Vec2i& other) const;

		Vec2i operator-();

		Vec2i operator*(const Vec2i& other) const;

		Vec2i operator*(const int& other) const;

		Vec2i operator*(const float& other) const;

		Vec2i operator/(const Vec2i& other) const;

		Vec2i operator/(const int& other) const;

		Vec2i operator/(const float& other) const;

	};

	struct DLL_API Vec2f {
		float x, y;

		Vec2f(const float& _x, const float& _y);

		Vec2f(const float& all);

		Vec2f();

		Vec2f operator-(const Vec2f& other) const;

		Vec2f operator+(const Vec2f& other) const;

		Vec2f operator+=(const Vec2f& other);

		Vec2f operator-();

		Vec2f operator*(const Vec2f& other) const;

		Vec2f operator*(const int& other) const;

		Vec2f operator*(const float& other) const;

		Vec2f operator/(const Vec2f& other) const;

		Vec2f operator/(const int& other) const;

		Vec2f operator/(const float& other) const;

	};
}

#endif