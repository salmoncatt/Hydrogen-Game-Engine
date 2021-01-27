
#ifndef HGE_MESH_COMPONENT_HEADER_INCLUDE
#define HGE_MESH_COMPONENT_HEADER_INCLUDE

#include HGE_API
#include "Mesh.h"

namespace HGE {

	struct DLL_API MeshComponent {
		std::vector<Mesh> meshes;

		MeshComponent();
		~MeshComponent();

	};


}

#endif