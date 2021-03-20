
#ifndef HFR_CAMERA_CONTROLLER_HEADER_INCLUDE
#define HFR_CAMERA_CONTROLLER_HEADER_INCLUDE

#include HFR_API

#include "Camera.h"
#include HFR_VEC3

namespace HFR {

	class DLL_API CameraController {
	public:
		Camera camera;
		float sensitivity, movementSpeed;
		Vec3f direction;
		bool fly = false;

		CameraController();
		CameraController(const Camera& camera, const float& sensitivity, const float& movementSpeed);
		~CameraController();

		void update();


	};

}

#endif