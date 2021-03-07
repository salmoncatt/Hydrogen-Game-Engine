#include "hpch.h"

namespace HGE {

	Mat4f::Mat4f() {
		m00 = 0.0f;
		m01 = 0.0f;
		m02 = 0.0f;
		m03 = 0.0f;
		m10 = 0.0f;
		m11 = 0.0f;
		m12 = 0.0f;
		m13 = 0.0f;
		m20 = 0.0f;
		m21 = 0.0f;
		m22 = 0.0f;
		m23 = 0.0f;
		m30 = 0.0f;
		m31 = 0.0f;
		m32 = 0.0f;
		m33 = 0.0f;
	}

	void Mat4f::setIdentity() {
		m00 = 1.0f;
		m01 = 0.0f;
		m02 = 0.0f;
		m03 = 0.0f;
		m10 = 0.0f;
		m11 = 1.0f;
		m12 = 0.0f;
		m13 = 0.0f;
		m20 = 0.0f;
		m21 = 0.0f;
		m22 = 1.0f;
		m23 = 0.0f;
		m30 = 0.0f;
		m31 = 0.0f;
		m32 = 0.0f;
		m33 = 1.0f;
	}

	Mat4f Mat4f::operator*(const Mat4f& other) {
		Mat4f out = Mat4f();
		out.setIdentity();

		out.m00 = m00 * other.m00 + m10 * other.m01 + m20 * other.m02 + m30 * other.m03;
		out.m01 = m01 * other.m00 + m11 * other.m01 + m21 * other.m02 + m31 * other.m03;
		out.m02 = m02 * other.m00 + m12 * other.m01 + m22 * other.m02 + m32 * other.m03;
		out.m03 = m03 * other.m00 + m13 * other.m01 + m23 * other.m02 + m33 * other.m03;
		out.m10 = m00 * other.m10 + m10 * other.m11 + m20 * other.m12 + m30 * other.m13;
		out.m11 = m01 * other.m10 + m11 * other.m11 + m21 * other.m12 + m31 * other.m13;
		out.m12 = m02 * other.m10 + m12 * other.m11 + m22 * other.m12 + m32 * other.m13;
		out.m13 = m03 * other.m10 + m13 * other.m11 + m23 * other.m12 + m33 * other.m13;
		out.m20 = m00 * other.m20 + m10 * other.m21 + m20 * other.m22 + m30 * other.m23;
		out.m21 = m01 * other.m20 + m11 * other.m21 + m21 * other.m22 + m31 * other.m23;
		out.m22 = m02 * other.m20 + m12 * other.m21 + m22 * other.m22 + m32 * other.m23;
		out.m23 = m03 * other.m20 + m13 * other.m21 + m23 * other.m22 + m33 * other.m23;
		out.m30 = m00 * other.m30 + m10 * other.m31 + m20 * other.m32 + m30 * other.m33;
		out.m31 = m01 * other.m30 + m11 * other.m31 + m21 * other.m32 + m31 * other.m33;
		out.m32 = m02 * other.m30 + m12 * other.m31 + m22 * other.m32 + m32 * other.m33;
		out.m33 = m03 * other.m30 + m13 * other.m31 + m23 * other.m32 + m33 * other.m33;

		return out;
	}

	Mat4f Mat4f::operator*(const Vec4f& other) {
		Mat4f out = Mat4f();
		out.setIdentity();

		out.m00 = m00 * other.x + m10 * other.y + m20 * other.z + m30 * other.w;
		out.m01 = m01 * other.x + m11 * other.y + m21 * other.z + m31 * other.w;
		out.m02 = m02 * other.x + m12 * other.y + m22 * other.z + m32 * other.w;
		out.m03 = m03 * other.x + m13 * other.y + m23 * other.z + m33 * other.w;

		return out;
	}

	Vec4f operator*(const Vec4f& other, const Mat4f& matrix) {
		Vec4f out = Vec4f();

		out.x = matrix.m00 * other.x + matrix.m10 * other.y + matrix.m20 * other.z + matrix.m30 * other.w;
		out.y = matrix.m01 * other.x + matrix.m11 * other.y + matrix.m21 * other.z + matrix.m31 * other.w;
		out.z = matrix.m02 * other.x + matrix.m12 * other.y + matrix.m22 * other.z + matrix.m32 * other.w;
		out.w = matrix.m03 * other.x + matrix.m13 * other.y + matrix.m23 * other.z + matrix.m33 * other.w;

		return out;
	}

	Mat4f Mat4f::operator*=(const Mat4f& other) {

		m00 = m00 * other.m00 + m10 * other.m01 + m20 * other.m02 + m30 * other.m03;
		m01 = m01 * other.m00 + m11 * other.m01 + m21 * other.m02 + m31 * other.m03;
		m02 = m02 * other.m00 + m12 * other.m01 + m22 * other.m02 + m32 * other.m03;
		m03 = m03 * other.m00 + m13 * other.m01 + m23 * other.m02 + m33 * other.m03;
		m10 = m00 * other.m10 + m10 * other.m11 + m20 * other.m12 + m30 * other.m13;
		m11 = m01 * other.m10 + m11 * other.m11 + m21 * other.m12 + m31 * other.m13;
		m12 = m02 * other.m10 + m12 * other.m11 + m22 * other.m12 + m32 * other.m13;
		m13 = m03 * other.m10 + m13 * other.m11 + m23 * other.m12 + m33 * other.m13;
		m20 = m00 * other.m20 + m10 * other.m21 + m20 * other.m22 + m30 * other.m23;
		m21 = m01 * other.m20 + m11 * other.m21 + m21 * other.m22 + m31 * other.m23;
		m22 = m02 * other.m20 + m12 * other.m21 + m22 * other.m22 + m32 * other.m23;
		m23 = m03 * other.m20 + m13 * other.m21 + m23 * other.m22 + m33 * other.m23;
		m30 = m00 * other.m30 + m10 * other.m31 + m20 * other.m32 + m30 * other.m33;
		m31 = m01 * other.m30 + m11 * other.m31 + m21 * other.m32 + m31 * other.m33;
		m32 = m02 * other.m30 + m12 * other.m31 + m22 * other.m32 + m32 * other.m33;
		m33 = m03 * other.m30 + m13 * other.m31 + m23 * other.m32 + m33 * other.m33;

		return *this;
	}

	void Mat4f::transpose(const Mat4f& src) {
		m00 = src.m00;
		m01 = src.m10;
		m02 = src.m20;
		m03 = src.m30;
		m10 = src.m01;
		m11 = src.m11;
		m12 = src.m21;
		m13 = src.m31;
		m20 = src.m02;
		m21 = src.m12;
		m22 = src.m22;
		m23 = src.m32;
		m30 = src.m03;
		m31 = src.m13;
		m32 = src.m23;
		m33 = src.m33;
	}

	void Mat4f::transposeWithoutRotation(const Mat4f& src) {
		m00 = src.m00;
		m01 = src.m10;
		m02 = src.m20;
		m10 = src.m01;
		m11 = src.m11;
		m12 = src.m21;
		m20 = src.m02;
		m21 = src.m12;
		m22 = src.m22;
	}

	void Mat4f::scale(const Vec3f& vec) {
		m00 *= vec.x;
		m01 *= vec.x;
		m02 *= vec.x;
		m03 *= vec.x;
		m10 *= vec.y;
		m11 *= vec.y;
		m12 *= vec.y;
		m13 *= vec.y;
		m20 *= vec.z;
		m21 *= vec.z;
		m22 *= vec.z;
		m23 *= vec.z;
	}

	void Mat4f::scale(const Vec2f& vec) {
		m00 *= vec.x;
		m01 *= vec.x;
		m02 *= vec.x;
		m03 *= vec.x;
		m10 *= vec.y;
		m11 *= vec.y;
		m12 *= vec.y;
		m13 *= vec.y;
	}

	void Mat4f::rotate(const float& angle, const Vec3f& axis) {
		float c = (float)cos(angle);
		float s = (float)sin(angle);
		float oneminusc = 1.0f - c;
		float xy = axis.x * axis.y;
		float yz = axis.y * axis.z;
		float xz = axis.x * axis.z;
		float xs = axis.x * s;
		float ys = axis.y * s;
		float zs = axis.z * s;

		float f00 = axis.x * axis.x * oneminusc + c;
		float f01 = xy * oneminusc + zs;
		float f02 = xz * oneminusc - ys;
		// n[3] not used
		float f10 = xy * oneminusc - zs;
		float f11 = axis.y * axis.y * oneminusc + c;
		float f12 = yz * oneminusc + xs;
		// n[7] not used
		float f20 = xz * oneminusc + ys;
		float f21 = yz * oneminusc - xs;
		float f22 = axis.z * axis.z * oneminusc + c;

		float t00 = m00 * f00 + m10 * f01 + m20 * f02;
		float t01 = m01 * f00 + m11 * f01 + m21 * f02;
		float t02 = m02 * f00 + m12 * f01 + m22 * f02;
		float t03 = m03 * f00 + m13 * f01 + m23 * f02;
		float t10 = m00 * f10 + m10 * f11 + m20 * f12;
		float t11 = m01 * f10 + m11 * f11 + m21 * f12;
		float t12 = m02 * f10 + m12 * f11 + m22 * f12;
		float t13 = m03 * f10 + m13 * f11 + m23 * f12;
		m20 = m00 * f20 + m10 * f21 + m20 * f22;
		m21 = m01 * f20 + m11 * f21 + m21 * f22;
		m22 = m02 * f20 + m12 * f21 + m22 * f22;
		m23 = m03 * f20 + m13 * f21 + m23 * f22;
		m00 = t00;
		m01 = t01;
		m02 = t02;
		m03 = t03;
		m10 = t10;
		m11 = t11;
		m12 = t12;
		m13 = t13;
	}

	void Mat4f::store(FloatBuffer* buffer) {
		buffer->put(m00);
		buffer->put(m01);
		buffer->put(m02);
		buffer->put(m03);
		buffer->put(m10);
		buffer->put(m11);
		buffer->put(m12);
		buffer->put(m13);
		buffer->put(m20);
		buffer->put(m21);
		buffer->put(m22);
		buffer->put(m23);
		buffer->put(m30);
		buffer->put(m31);
		buffer->put(m32);
		buffer->put(m33);
	}

	void Mat4f::translate(const Vec3f& vec) {
		m30 += m00 * vec.x + m10 * vec.y + m20 * vec.z;
		m31 += m01 * vec.x + m11 * vec.y + m21 * vec.z;
		m32 += m02 * vec.x + m12 * vec.y + m22 * vec.z;
		m33 += m03 * vec.x + m13 * vec.y + m23 * vec.z;
	}

	void Mat4f::translate(const Vec2f& vec) {
		m30 += m00 * vec.x + m10 * vec.y;
		m31 += m01 * vec.x + m11 * vec.y;
		m32 += m02 * vec.x + m12 * vec.y;
		m33 += m03 * vec.x + m13 * vec.y;
	}

	//create important matrixes
	Mat4f Mat4f::createTransformationMatrix(const Vec3f& translation, const Vec3f& rotation, const Vec3f& scale) {
		Mat4f transformation = Mat4f();
		transformation.setIdentity();
		transformation.translate(translation);
		transformation.rotate((float)HMath::toRadians(rotation.x), Vec3f(1, 0, 0));
		transformation.rotate((float)HMath::toRadians(rotation.y), Vec3f(0, 1, 0));
		transformation.rotate((float)HMath::toRadians(rotation.z), Vec3f(0, 0, 1));
		transformation.scale(scale);
		return transformation;
	}

	Mat4f Mat4f::createTransformationMatrix(const Vec2f& translation, const Vec3f& rotation, const Vec2f& scale) {
		Mat4f transformation = Mat4f();
		transformation.setIdentity();
		transformation.translate(translation);
		transformation.rotate((float)HMath::toRadians(rotation.x), Vec3f(1, 0, 0));
		transformation.rotate((float)HMath::toRadians(rotation.y), Vec3f(0, 1, 0));
		transformation.rotate((float)HMath::toRadians(rotation.z), Vec3f(0, 0, 1));
		transformation.scale(Vec3f(scale.x, scale.y, 1));
		return transformation;
	}

	Mat4f Mat4f::createTransformationMatrix_ScaleBeforeRotation(const Vec2f& translation, const Vec3f& rotation, const Vec2f& scale) {
		Mat4f transformation = Mat4f();
		transformation.setIdentity();
		transformation.translate(translation);
		transformation.scale(Vec3f(scale.x, scale.y, 1));
		transformation.rotate((float)HMath::toRadians(rotation.x), Vec3f(1, 0, 0));
		transformation.rotate((float)HMath::toRadians(rotation.y), Vec3f(0, 1, 0));
		transformation.rotate((float)HMath::toRadians(rotation.z), Vec3f(0, 0, 1));
		return transformation;
	}

	Mat4f Mat4f::createPerspectiveMatrix(const float& screenWidth, const float& screenHeight, const float& fov, const float& nearPlane, const float& farPlane) {
		Mat4f projectionMatrix = Mat4f();
		float aspectRatio = screenWidth / screenHeight;
		float y_scale = (float)((1 / tan(HMath::toRadians(fov / 2))));
		float x_scale = y_scale / aspectRatio;
		float frustum_length = farPlane - nearPlane;

		projectionMatrix.m00 = x_scale;
		projectionMatrix.m11 = y_scale;
		projectionMatrix.m22 = -((farPlane + nearPlane) / frustum_length);
		projectionMatrix.m23 = -1;
		projectionMatrix.m32 = -((2 * nearPlane * farPlane) / frustum_length);
		projectionMatrix.m33 = 0;
		return projectionMatrix;
	}

	Mat4f Mat4f::createOrthoMatrix(const float& left, const float& right, const float& bottom, const float& top, const float& nearPlane, const float& farPlane) {
		Mat4f out = Mat4f();
		out.setIdentity();
		out.m00 = 2 / (right - left);
		out.m11 = 2 / (top - bottom);
		out.m22 = -2 / (farPlane - nearPlane);
		out.m30 = -(right + left) / (right - left);
		out.m31 = -(top + bottom) / (top - bottom);
		out.m32 = -(farPlane + nearPlane) / (farPlane - nearPlane);
		return out;
	}

	Mat4f Mat4f::createViewMatrix(const Vec3f& position, const Vec3f& rotation) {
		Mat4f viewMatrix = Mat4f();
		viewMatrix.setIdentity();
		viewMatrix.rotate((float)HMath::toRadians(-rotation.x), Vec3f(1, 0, 0));
		viewMatrix.rotate((float)HMath::toRadians(-rotation.y), Vec3f(0, 1, 0));
		viewMatrix.rotate((float)HMath::toRadians(0), Vec3f(0, 0, 1));
		Vec3f negcampos = Vec3f(-position.x, -position.y, -position.z);
		viewMatrix.translate(negcampos);
		return viewMatrix;
	}

};
