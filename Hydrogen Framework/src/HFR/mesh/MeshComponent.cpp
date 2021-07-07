#include "hfpch.h"

namespace HFR {


	MeshComponent::MeshComponent() {

	}

	MeshComponent::~MeshComponent() {
		meshes.clear();
	}

	void MeshComponent::clearAllVertices() {
		for (int i = 0; i < meshes.size(); i++) {
			auto& component = meshes[i];

			component.vertices.clear();
		}
	}


	void MeshComponent::clearAllNormals() {
		for (int i = 0; i < meshes.size(); i++) {
			auto& component = meshes[i];

			component.normals.clear();
		}
	}


	void MeshComponent::clearAllTextureCoordinates() {
		for (int i = 0; i < meshes.size(); i++) {
			auto& component = meshes[i];

			component.texturecoords.clear();
		}
	}

}