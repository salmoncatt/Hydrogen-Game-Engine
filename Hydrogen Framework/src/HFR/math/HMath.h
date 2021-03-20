
#ifndef HFR_HMATH_HEADER_INCLUDE
#define HFR_HMATH_HEADER_INCLUDE

#include HFR_API
#include HFR_VEC2
#include HFR_VEC3
#include HFR_VEC4
#include HFR_MAT4
#include HFR_TRANSFORM
#include HFR_RANDOM

namespace HFR{

	struct Vec3f;
	
	class DLL_API HMath {
	public:
		static double PI;

		static double toRadians(const double& degrees);
		static double toDegrees(const double& radians);
		//static double sin(double);
		static double pow(const double& base, const double& exponent);
		static int factorial(const int& number);
		static Vec3f getCameraDirectionFromRotation(const Vec3f& rotation);

		static float f_sqrt(const float& in);
		static float f_isqrt(const float& in);

		static float sqrt(const float& in);
		static float isqrt(const float& in);
		static float lerp(const float& a, const float& b, const float& percentage);
		static float coslerp(const float& a, const float& b, const float& percentage);

		static int gcd(const int& a, const int& b);

		static void keepRotationInTermsOf360(Vec3f& rotation);
	};

}

#endif