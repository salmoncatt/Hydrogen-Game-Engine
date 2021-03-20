#include "hfpch.h"

namespace HFR {

	EditorCamera::EditorCamera() {
		camera = Camera();
		transform = Transform();
		sensitivity = 0.08f;
		movementSpeed = 10;
		direction = Vec3f();
	}

	EditorCamera::~EditorCamera() {

	}


	void EditorCamera::update() {

		float speed = Time::getDeltaTime() * (Input::getKey(HFR_KEY_LEFT_SHIFT) ? movementSpeed * 2 : movementSpeed);

		float directionx = direction.x * speed;
		float directionz = direction.z * speed;

		if (Input::getKey(HFR_KEY_W))
			transform.position += Vec3f(-directionx, 0, -directionz);
		if (Input::getKey(HFR_KEY_A))
			transform.position += Vec3f(-directionz, 0, directionx);
		if (Input::getKey(HFR_KEY_S))
			transform.position += Vec3f(directionx, 0, directionz);
		if (Input::getKey(HFR_KEY_D))
			transform.position += Vec3f(directionz, 0, -directionx);
		if (Input::getKey(HFR_KEY_SPACE))
			transform.position += Vec3f(0, speed, 0);
		if (Input::getKey(HFR_KEY_LEFT_CONTROL))
			transform.position += Vec3f(0, -speed, 0);

		Vec2f rotationAmount = !Cursor::getMouseState() ? -Input::getMouseMovement() * sensitivity : Vec2f();

		transform.rotation += Vec3f(rotationAmount.y, rotationAmount.x, 0);

		direction = HMath::getCameraDirectionFromRotation(Vec3f(0, transform.rotation.y, 0));

		if (transform.rotation.x < -90)
			transform.rotation.x = -90;
		else if (transform.rotation.x > 90)
			transform.rotation.x = 90;

		camera.position = transform.position;
		camera.rotation = transform.rotation;
	}

}
