#include "hpch.h"
#include "CameraController.h"
#include "HGE/io/Input.h"
#include "HGE/util/time/Time.h"
#include "HGE/util/Debug.h"
#include "HGE/math/HMath.h"
#include "HGE/math/vectors/Vec2.h"

namespace HGE {

	CameraController::CameraController() {
		sensitivity = 0;
		movementSpeed = 0;
		direction = Vec3f();
	}

	CameraController::CameraController(const Camera& _camera, const float& _sensitivity, const float& _movementSpeed) {
		camera = _camera;
		sensitivity = _sensitivity;
		movementSpeed = _movementSpeed;
		direction = Vec3f();
	}

	CameraController::~CameraController() {

	}

	void CameraController::update() {

		float speed = Time::getDeltaTime() * movementSpeed;

		float directionx = direction.x * speed;
		float directionz = direction.z * speed;

		if (Input::getKey(GLFW_KEY_W))
			camera.position += Vec3f(-directionx, 0, -directionz);
		if (Input::getKey(GLFW_KEY_A))
			camera.position += Vec3f(-directionz, 0, directionx);
		if (Input::getKey(GLFW_KEY_S))
			camera.position += Vec3f(directionx, 0, directionz);
		if (Input::getKey(GLFW_KEY_D))
			camera.position += Vec3f(directionz, 0, -directionx);

		if (fly) {
			if (Input::getKey(GLFW_KEY_SPACE))
				camera.position += Vec3f(0, speed, 0);
			if (Input::getKey(GLFW_KEY_LEFT_CONTROL))
				camera.position += Vec3f(0, -speed, 0);
		}

		Vec2f rotationAmount = -Input::getMouseMovement() * sensitivity;

		camera.rotation += Vec3f(rotationAmount.y, rotationAmount.x, 0);

		if (camera.rotation.x < -90)
			camera.rotation.x = -90;
		else if (camera.rotation.x > 90)
			camera.rotation.x = 90;

		direction = HMath::getCameraDirectionFromRotation(Vec3f(0, camera.rotation.y, 0));
	}


}