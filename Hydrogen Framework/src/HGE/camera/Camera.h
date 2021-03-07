
#ifndef HGE_CAMERA_HEADER_INCLUDE
#define HGE_CAMERA_HEADER_INCLUDE

#include HGE_API
#include HGE_VEC3

namespace HGE {

	struct DLL_API Camera {
		Vec3f position, rotation;

		Camera();
		Camera(const Vec3f& position, const Vec3f& rotation);
		~Camera();

	};

}

#endif