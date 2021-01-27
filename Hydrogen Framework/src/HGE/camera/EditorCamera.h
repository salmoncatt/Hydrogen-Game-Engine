
#ifndef HGE_EDITOR_CAMERA_HEADER_INCLUDE
#define HGE_EDITOR_CAMERA_HEADER_INCLUDE

#include HGE_API
#include "HGE/math/vectors/Vec3.h"
#include "Camera.h"
#include "HGE/ECS/components/Transform.h"

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
