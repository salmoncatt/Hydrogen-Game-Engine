#include "hfpch.h"

namespace HFR {

	double HMath::PI = 3.14159265;

	double HMath::toRadians(const double &degrees) {
		return degrees * PI / 180;
	}

	double HMath::toDegrees(const double &radians) {
		return radians * 180 / PI;
	}

	int HMath::factorial(const int &number) {
		int out = 1;

		for (int i = 0; i < number; i++) {
			out *= number - i;
		}

		return out;
	}

	double HMath::pow(const double &base, const double &exponent) {
		double out = 1;
		double currentPower = exponent;

		while (currentPower != 0) {
			out *= base;
			currentPower -= 1;
		}

		return out;

	}

	Vec3f HMath::getCameraDirectionFromRotation(const Vec3f& rotation) {
		Vec3f out = Vec3f(sin((float)toRadians(rotation.y)), tan((float)toRadians(rotation.x)), cos((float)toRadians(rotation.y)));
		out.normalize();
		return out;
	}

	float HMath::f_sqrt(const float& in) {
		long i;
		float x2, y;
		const float threeHalfs = 1.5f;

		//we are doing the inverse of inverse and its fast
		float inverseIn = 1 / in;

		x2 = inverseIn * 0.5f;
		y = inverseIn;

		i = *(long*)&y; // convert memory address to long for bit shifting
		i = 0x5f375a86 - (i >> 1); // shift exponent right to divide by two and negate that (y^(-1/2)), also what the fuck?
		y = *(float*)&i; //convert memory address back to float for output
		y = y * (threeHalfs - (x2 * y * y)); // newton iteration, 1 is fine because we are close enough to answer, btw what the fuck is this
		//second iteration to make it more accurate
		y = y * (threeHalfs - (x2 * y * y)); // newton iteration, 2 is fine because we are close enough to answer, btw what the fuck is this

		return y;
	}

	float HMath::f_isqrt(const float& in) {
		long i;
		float x2, y;
		const float threeHalfs = 1.5f;

		x2 = in * 0.5f;
		y = in;

		i = *(long*)&y; // convert memory address to long for bit shifting
		i = 0x5f375a86 - (i >> 1); // shift exponent right to divide by two and negate that (y^(-1/2)), also what the fuck?
		y = *(float*)&i; //convert memory address back to float for output
		y = y * (threeHalfs - (x2 * y * y)); // newton iteration, 1 is fine because we are close enough to answer, btw what the fuck is this

		return y;
	}

	float HMath::sqrt(const float& in) {
		long i;
		float x2, y;
		const float threeHalfs = 1.5f;

		//we are doing the inverse of inverse and its fast
		float inverseIn = 1 / in;

		x2 = inverseIn * 0.5f;
		y = inverseIn;

		i = *(long*)&y; // convert memory address to long for bit shifting
		i = 0x5f375a86 - (i >> 1); // shift exponent right to divide by two and negate that (y^(-1/2)), also what the fuck?
		y = *(float*)&i; //convert memory address back to float for output

		y = y * (threeHalfs - (x2 * y * y)); // newton iteration, 3 because we are close enough to answer but this is accurate and not fast, btw what the fuck is this

		//second iteration to make it more accurate
		y = y * (threeHalfs - (x2 * y * y)); // newton iteration

		//third iteration to make it more accurate
		y = y * (threeHalfs - (x2 * y * y)); // newton iteration

		return y;
	}

	float HMath::isqrt(const float& in) {
		long i;
		float x2, y;
		const float threeHalfs = 1.5f;

		x2 = in * 0.5f;
		y = in;

		i = *(long*)&y; // convert memory address to long for bit shifting
		i = 0x5f375a86 - (i >> 1); // shift exponent right to divide by two and negate that (y^(-1/2)), also what the fuck?
		y = *(float*)&i; //convert memory address back to float for output

		y = y * (threeHalfs - (x2 * y * y)); // newton iteration, 3 because we are close enough to answer but this is accurate and not fast, btw what the fuck is this

		//second iteration to make it more accurate
		y = y * (threeHalfs - (x2 * y * y)); // newton iteration

		//third iteration to make it more accurate
		y = y * (threeHalfs - (x2 * y * y)); // newton iteration
		
		return y;
	}

	float HMath::lerp(const float& a, const float& b, const float& percentage)
	{
		return a + percentage * (b - a);
	}

	float HMath::coslerp(const float& a, const float& b, const float& percentage)
	{
		float cosPercentage = (1 - (float)cos(percentage * PI)) / 2;
		return (a * (1 - cosPercentage) + b * cosPercentage);
	}

	void HMath::keepRotationInTermsOf360(Vec3f& rotation) {

		if (rotation.x > 360)
			rotation.x -= 360;
		if (rotation.x < -360)
			rotation.x += 360;

		if (rotation.y > 360)
			rotation.y -= 360;
		if (rotation.y < -360)
			rotation.y += 360;

		if (rotation.z > 360)
			rotation.z -= 360;
		if (rotation.z < -360)
			rotation.z += 360;
	}

	int HMath::gcd(const int& a, const int& b) {
		if (b == 0)
			return a;
		
		return gcd(b, a % b);
	}

}