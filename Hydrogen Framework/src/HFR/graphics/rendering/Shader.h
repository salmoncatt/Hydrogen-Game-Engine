
#ifndef HFR_SHADER_HEADER_INCLUDE
#define HFR_SHADER_HEADER_INCLUDE

#include HFR_API

namespace HFR {

	struct Mat4f;
	struct Vec4f;
	struct Vec3f;
	struct Vec2f;

	class DLL_API Shader {
	private:
		std::string vertexShader, fragmentShader, vertexName, fragmentName;
		int vertexID, fragmentID, programID;
	public:
		Shader(const std::string& FolderPath, const std::string& VertexFilePath, const std::string& FragmentFilePath);
		~Shader();

		void create();
		void bind();
		void unbind();
		void close();

		unsigned int getLocation(const std::string& name);
		void setUniform(const std::string& name, Mat4f& data);
		void setUniform(const std::string& name, const Vec4f& data);
		void setUniform(const std::string& name, const Vec3f& data);
		void setUniform(const std::string& name, const Vec2f& data);
		void setUniform(const std::string& name, const bool& data);
		void setUniform(const std::string& name, const int& data);
		void setUniform(const std::string& name, const float& data);
	};

}

#endif