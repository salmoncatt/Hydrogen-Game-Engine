
#ifndef HFR_EDITOR_CAMERA_HEADER_INCLUDE
#define HFR_EDITOR_CAMERA_HEADER_INCLUDE

#include HFR_API
#include "Camera.h"
#include HFR_TRANSFORM

namespace HFR {

	class DLL_API EditorCamera {
	public:
		Camera camera;
		Transform transform;
		float sensitivity, movementSpeed;
		Vec3f direction;

		EditorCamera();
		~EditorCamera();

		void update();

	};

}

#endif
