
#ifndef HFR_MESH_COMPONENT_HEADER_INCLUDE
#define HFR_MESH_COMPONENT_HEADER_INCLUDE

#include HFR_API
#include "Mesh.h"

namespace HFR {

	struct DLL_API MeshComponent {
		std::vector<Mesh> meshes;

		MeshComponent();
		~MeshComponent();

		void clearAllVertices();
		void clearAllNormals();
		void clearAllTextureCoordinates();

	};


}

#endif