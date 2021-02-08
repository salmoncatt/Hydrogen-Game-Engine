#include "hpch.h"
#include "Vec3.h"
#include "HGE/math/HMath.h"

namespace HGE {

	Vec3f::Vec3f(const float& _x, const float& _y, const float& _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	Vec3f::Vec3f(const float& all) {
		x = all;
		y = all;
		z = all;
	}

	Vec3f::Vec3f() : x(0), y(0), z(0) {}

	void Vec3f::normalize() {
		float l = ilength();
		x /= l;
		y /= l;
		z /= l;
	}

	float Vec3f::length() {
		return HMath::f_sqrt(x * x + y * y + z * z);
	}

	float Vec3f::ilength() {
		return HMath::f_isqrt(x * x + y * y + z * z);
	}

	Vec3f Vec3f::operator+(const Vec3f& other) {
		Vec3f out = Vec3f();
		out.x = x + other.x;
		out.y = y + other.y;
		out.z = z + other.z;
		return out;
	}

	Vec3f Vec3f::operator+=(const Vec3f& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vec3f Vec3f::operator-(const Vec3f& other) {
		Vec3f out = Vec3f();
		out.x = x - other.x;
		out.y = y - other.y;
		out.z = z - other.z;
		return out;
	}

	Vec3f Vec3f::operator-=(const Vec3f& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vec3f Vec3f::cross(const Vec3f& left, const Vec3f& right) {
		Vec3f out = Vec3f();
		out.x = left.y * right.z - left.z * right.y;
		out.y = left.z * right.x - left.x * right.z;
		out.z = left.x * right.y - left.y * right.x;
		return out;
	}

	Vec3f Vec3f::operator*(const Vec3f& other) {
		Vec3f out = Vec3f();
		out.x = x * other.x;
		out.y = y * other.y;
		out.z = z * other.z;
		return out;
	}

	Vec3f Vec3f::operator*=(const Vec3f& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vec3f Vec3f::operator*(const float& other) {
		Vec3f out = Vec3f();
		out.x = x * other;
		out.y = y * other;
		out.z = z * other;
		return out;
	}

	Vec3f Vec3f::operator*=(const float& other) {
		x *= other;
		y *= other;
		z *= other;
		return *this;
	}

}