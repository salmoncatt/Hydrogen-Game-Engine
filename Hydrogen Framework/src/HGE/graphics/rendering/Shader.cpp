#include "hpch.h"
#include "Shader.h"
#include "HGE/util/Util.h"
#include "HGE/util/memory/FloatBuffer.h"
#include "HGE/math/matrixes/Mat4.h"
#include "HGE/math/vectors/Vec3.h"
#include "HGE/math/vectors/Vec2.h"

namespace HGE {

	Shader::Shader(const std::string& FolderPath, const std::string& VertexFilePath, const std::string& FragmentFilePath) {
		vertexShader = Util::readAsString(FolderPath + VertexFilePath, HGE_BINARY_READ);
		fragmentShader = Util::readAsString(FolderPath + FragmentFilePath, HGE_BINARY_READ);
		vertexName = VertexFilePath;
		fragmentName = FragmentFilePath;

		vertexID = 0;
		fragmentID = 0;
		programID = 0;
	}

	Shader::~Shader() {
		close();
	}

	void Shader::create() {
		programID = glCreateProgram();
		vertexID = glCreateShader(GL_VERTEX_SHADER);
		fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

		Util::compileShader(vertexID, vertexShader, vertexName);
		Util::compileShader(fragmentID, fragmentShader, fragmentName);

		glAttachShader(programID, vertexID);
		glAttachShader(programID, fragmentID);

		Util::linkAndValidateProgram(programID);
	}

	void Shader::bind() {
		glUseProgram(programID);
	}

	void Shader::unbind() {
		glUseProgram(0);
	}

	unsigned int Shader::getLocation(const std::string& name) {
		return glGetUniformLocation(programID, name.c_str());
	}

	void Shader::setUniform(const std::string& name, Mat4f& data) {
		FloatBuffer* matbuffer = new FloatBuffer(16);
		data.store(matbuffer);
		glUniformMatrix4fv(getLocation(name), 1, false, matbuffer->data);
		delete matbuffer;
	}

	void Shader::setUniform(const std::string& name, const Vec2f& data) {
		glUniform2f(getLocation(name), data.x, data.y);
	}

	void Shader::setUniform(const std::string& name, const Vec3f& data) {
		glUniform3f(getLocation(name), data.x, data.y, data.z);
	}

	void Shader::setUniform(const std::string& name, const bool& data) {
		glUniform1f(getLocation(name), data ? (GLfloat)1 : (GLfloat)0);
	}

	void Shader::setUniform(const std::string& name, const float& data) {
		glUniform1f(getLocation(name), data);
	}

	void Shader::setUniform(const std::string& name, const int& data) {
		glUniform1i(getLocation(name), data);
	}

	void Shader::close() {
		glDetachShader(programID, vertexID);
		glDetachShader(programID, fragmentID);
		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);
		glDeleteShader(programID);
	}

}
