
#ifndef HGE_EDITOR_CAMERA_HEADER_INCLUDE
#define HGE_EDITOR_CAMERA_HEADER_INCLUDE

#include HGE_API
#include "Camera.h"
#include HGE_TRANSFORM

namespace HGE {

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
