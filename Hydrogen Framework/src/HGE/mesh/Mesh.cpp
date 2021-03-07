#include "hpch.h"

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


	void Mesh::calculateNormals(const float& boost) {
		normals.clear();


		if (vertices.size() >= 9) {
			normals.reserve(vertices.size() / 9);
			size_t j = 0;

			for (size_t i = 0; i < vertices.size() - 9; i += 9) {
				/*		a
				*		*
				*
				* *			 *
				* b			 c
				*
				*
				*/

				Vec3f a = Vec3f(vertices[i], vertices[i + 1], vertices[i + 2]);
				Vec3f b = Vec3f(vertices[i + 3], vertices[i + 4], vertices[i + 5]);
				Vec3f c = Vec3f(vertices[i + 6], vertices[i + 7], vertices[i + 8]);

				a.normalize();
				b.normalize();
				c.normalize();

				Vec3f normal = Vec3f::cross(b - a, c - a);

				normal *= boost;

				//normal.normalize();

				normals.push_back(normal.x);
				normals.push_back(normal.y);
				normals.push_back(normal.z);
				normals.push_back(normal.x);
				normals.push_back(normal.y);
				normals.push_back(normal.z);
				normals.push_back(normal.x);
				normals.push_back(normal.y);
				normals.push_back(normal.z);
				j += 3;
			}
		}

	}

	void Mesh::smoothNormals(const float& smoothingValue, const size_t& passes) {
		if (normals.size() > 3) {
			
			for (size_t j = 0; j < passes; j++) {
				
				if (normals.size() > 6) {

					for (size_t i = 3; i < normals.size() - 3; i += 3) {
						Vec3f a = Vec3f(normals[i - 3], normals[i - 2], normals[i - 1]);
						Vec3f b = Vec3f(normals[i], normals[i + 2], normals[i + 3]);

						Vec3f normal = Vec3f((normals[i - 3] + normals[i]) / 2, (normals[i - 2] + normals[i + 1]) / 2, (normals[i - 1] + normals[i + 2]) / 2);
						
						//normal.normalize();

						normals[i] = normal.x;
						normals[i + 1] = normal.y;
						normals[i + 2] = normal.z;

					}
				}
			}
		}
	}

}
