#include "hpch.h"
#include "Mesh.h"
#include "HGE/util/Util.h"

namespace HGE {

	Mesh::Mesh() {
		VAO = 0;
		IBO = 0;
	}

	Mesh::Mesh(const std::vector<float>& _vertices, const std::vector<unsigned int>& _indices, const std::vector<float>& _normals, const std::vector<float>& _texturecoords) {
		vertices = _vertices;
		texturecoords = _texturecoords;
		indices = _indices;
		normals = _normals;

		VAO = 0;
		IBO = 0;
	}

	Mesh::~Mesh() {
		glDeleteVertexArrays(1, &VAO);
	}

	void Mesh::create() {
		VAO = Util::generateVAO();
		IBO = Util::generateVBO();


		//using type variable if i want to use 2d mesh

		//vertices
		if (!vertices.empty())
			Util::pushDataToVBO(0, type, vertices);

		//texture
		if (!texturecoords.empty())
			Util::pushDataToVBO(1, 2, texturecoords);

		if (!normals.empty())
			Util::pushDataToVBO(2, 3, normals);

		//indices
		if (!indices.empty())
			Util::pushDataToIBO(indices, IBO);

		created = true;
	}


}
