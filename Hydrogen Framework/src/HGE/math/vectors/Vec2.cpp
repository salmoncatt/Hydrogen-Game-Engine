#include "hpch.h"

namespace HGE {

	Vec2i::Vec2i(const int& _x, const int& _y) : x(_x), y(_y) {}

	Vec2i::Vec2i(const int& all) {
		x = all;
		y = all;
	}

	Vec2i::Vec2i() : x(0), y(0) {}

	Vec2i Vec2i::operator-(const Vec2i& other) const {
		Vec2i out = Vec2i();
		out.x = x - other.x;
		out.y = y - other.y;
		return out;
	}

	Vec2i Vec2i::operator-() {
		Vec2i out = Vec2i();
		out.x = -x;
		out.y = -y;
		return out;
	}

	Vec2i Vec2i::operator*(const Vec2i& other) const {
		Vec2i out = Vec2i();
		out.x = x * other.x;
		out.y = y * other.y;
		return out;
	}

	Vec2i Vec2i::operator*(const int& other) const {
		Vec2i out = Vec2i();
		out.x = x * other;
		out.y = y * other;
		return out;
	}

	Vec2i Vec2i::operator*(const float& other) const {
		Vec2i out = Vec2i();
		int outx = (int)((float)x * other);
		int outy = (int)((float)y * other);
		out.x = outx;
		out.y = outy;
		return out;
	}

	Vec2i Vec2i::operator/(const Vec2i& other) const {
		Vec2i out = Vec2i();
		out.x = x / other.x;
		out.y = y / other.y;
		return out;
	}

	Vec2i Vec2i::operator/(const int& other) const {
		Vec2i out = Vec2i();
		out.x = x / other;
		out.y = y / other;
		return out;
	}

	Vec2i Vec2i::operator/(const float& other) const {
		Vec2i out = Vec2i();
		int outx = (int)((float)x / other);
		int outy = (int)((float)y / other);
		out.x = outx;
		out.y = outy;
		return out;
	}




	Vec2f::Vec2f(const float& _x, const float& _y) : x(_x), y(_y) {}

	Vec2f::Vec2f(const float& all) {
		x = all;
		y = all;
	}

	Vec2f::Vec2f() : x(0), y(0) {}

	Vec2f Vec2f::operator-(const Vec2f& other) const {
		Vec2f out = Vec2f();
		out.x = x - other.x;
		out.y = y - other.y;
		return out;
	}

	Vec2f Vec2f::operator+(const Vec2f& other) const {
		Vec2f out = Vec2f();
		out.x = x + other.x;
		out.y = y + other.y;
		return out;
	}

	Vec2f Vec2f::operator+=(const Vec2f& other) {
		x = x + other.x;
		y = y + other.y;
		return *this;
	}

	Vec2f Vec2f::operator-() {
		Vec2f out = Vec2f();
		out.x = -x;
		out.y = -y;
		return out;
	}

	Vec2f Vec2f::operator*(const Vec2f& other) const {
		Vec2f out = Vec2f();
		out.x = x * other.x;
		out.y = y * other.y;
		return out;
	}

	Vec2f Vec2f::operator*(const int& other) const {
		Vec2f out = Vec2f();
		float outx = (float)((int)x * other);
		float outy = (float)((int)y * other);
		return out;
	}

	Vec2f Vec2f::operator*(const float& other) const {
		Vec2f out = Vec2f();
		out.x = x * other;
		out.y = y * other;
		return out;
	}

	Vec2f Vec2f::operator/(const Vec2f& other) const {
		Vec2f out = Vec2f();
		out.x = x / other.x;
		out.y = y / other.y;
		return out;
	}

	Vec2f Vec2f::operator/(const int& other) const {
		Vec2f out = Vec2f();
		float outx = (float)((int)x / other);
		float outy = (float)((int)y / other);
		return out;
	}

	Vec2f Vec2f::operator/(const float& other) const {
		Vec2f out = Vec2f();
		out.x = x / other;
		out.y = y / other;
		return out;
	}






	
}