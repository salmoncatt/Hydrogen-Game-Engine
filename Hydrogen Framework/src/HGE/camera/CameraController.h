
#ifndef HGE_CAMERA_CONTROLLER_HEADER_INCLUDE
#define HGE_CAMERA_CONTROLLER_HEADER_INCLUDE

#include HGE_API

#include "Camera.h"
#include "HGE/math/vectors/Vec3.h"

namespace HGE {

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