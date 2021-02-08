

#ifndef HGE_MESH_HEADER_INCLUDE
#define HGE_MESH_HEADER_INCLUDE

#include HGE_API
#include "HGE/math/vectors/Vec3.h"
#include "Material.h"

namespace HGE {

	class DLL_API Mesh{
	public:
		Material material;
		std::vector<float> vertices;
		std::vector<float> texturecoords;
		std::vector<float> normals;
		std::vector<unsigned int> indices;

		unsigned int VAO, IBO;
		bool isUsingIndices = false;
		bool created = false;
		//set to 3d by default so you dont have to
		int type = HGE_3D;

		Mesh();

		Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const std::vector<float>& normals, const std::vector<float>& texturecoords);

		~Mesh();

		void create();

		/*
		* Calulates normals using the current vertex data. Will delete any current normals
		* 
		* @param A multiplier for boosting light values
		* 
		* @author Salmoncatt
		* 
		*/
		void calculateNormals(const float& boost);

		void smoothNormals(const float& smoothingValue, const size_t& passes);

	};
}

#endif
