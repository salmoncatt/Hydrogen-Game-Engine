

#ifndef HFR_MATRIX_HEADER_INCLUDE
#define HFR_MATRIX_HEADER_INCLUDE

#include HFR_API

namespace HFR {

	struct Vec2f;
	struct Vec3f;
	struct Vec4f;
	class FloatBuffer;

	struct DLL_API Mat4f {
		float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;

		Mat4f();

		void setIdentity();

		void transpose(const Mat4f& src);

		void transposeWithoutRotation(const Mat4f& src);

		void scale(const Vec3f& scale);

		void scale(const Vec2f& scale);

		void rotate(const float& angle, const Vec3f& axis);

		void store(FloatBuffer* buffer);

		void translate(const Vec3f& translation);

		void translate(const Vec2f& translation);

		//create important matrixes
		static Mat4f createTransformationMatrix(const Vec3f& translation, const Vec3f& rotation, const Vec3f& scale);

		static Mat4f createTransformationMatrix(const Vec2f& translation, const Vec3f& rotation, const Vec2f& scale);

		static Mat4f createTransformationMatrix_ScaleBeforeRotation(const Vec2f& translation, const Vec3f& rotation, const Vec2f& scale);

		static Mat4f createPerspectiveMatrix(const float& screenWidth, const float& screenHeight, const float& fov, const float& nearPlane, const float& farPlane);

		static Mat4f createOrthoMatrix(const float& left, const float& right, const float& bottom, const float& top, const float& nearPlane, const float& farPlane);

		static Mat4f createViewMatrix(const Vec3f& position, const Vec3f& rotation);

		Mat4f operator*(const Mat4f& other);

		Mat4f operator*(const Vec4f& other);

		friend Vec4f operator*(const Vec4f& other, const Mat4f& matrix);

		Mat4f operator*=(const Mat4f& other);

	};
}

#endif