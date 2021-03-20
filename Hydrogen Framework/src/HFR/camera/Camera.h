
#ifndef HFR_CAMERA_HEADER_INCLUDE
#define HFR_CAMERA_HEADER_INCLUDE

#include HFR_API
#include HFR_VEC3

namespace HFR {

	struct DLL_API Camera {
		Vec3f position, rotation;

		Camera();
		Camera(const Vec3f& position, const Vec3f& rotation);
		~Camera();

	};

}

#endif