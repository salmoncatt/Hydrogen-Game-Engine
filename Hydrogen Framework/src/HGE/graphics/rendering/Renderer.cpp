#include "hpch.h"
#include "Renderer.h"
#include "HGE/util/Util.h"
#include "HGE/camera/Camera.h"
#include "HGE/ECS/components/Mesh.h"
#include "HGE/ECS/ECS.h"
#include "HGE/ECS/components/Transform.h"
#include "HGE/math/HMath.h"
#include "HGE/util/time/Profiler.h"

namespace HGE {

	Mat4f Renderer::perspectiveMatrix = Mat4f();
	Mat4f Renderer::orthoMatrix = Mat4f::createOrthoMatrix(-1, 1, -1, 1, -1, 1);
	Mat4f Renderer::viewMatrix = Mat4f();
	
	Shader Renderer::mainShader = HGE::Shader(HGE_RES + "shaders/", "MainVertex.glsl", "MainFragment.glsl");
	Shader Renderer::guiShader = HGE::Shader(HGE_RES + "shaders/", "guiVertex.glsl", "guiFragment.glsl");

	Texture Renderer::nullTexture = Texture(HGE_RES + "textures/null.bmp");

	const std::vector<float> Renderer::quadVertices = {-1, 1,  -1, -1,  1, 1, 1, -1};
	Mesh Renderer::quad = Mesh(quadVertices, std::vector<unsigned int>(), std::vector<float>(), std::vector<float>());

	bool Renderer::wireframe = false;
	bool Renderer::cull = false;

	//set to per vertex for speed at first
	int Renderer::lightMode = HGE_PER_VERTEX_LIGHT;

	Vec2f Renderer::currentWindowSize = Vec2f();

	void Renderer::init(const float& screenWidth, const float& screenHeight) {
		//show opengl stuff
		Debug::newLine();

		std::string vendor((const char*)glGetString(GL_VENDOR));
		std::string version((const char*)glGetString(GL_VERSION));
		std::string gpu((const char*)glGetString(GL_RENDERER));

		Debug::systemLog("OpenGL Vendor: " + vendor, DebugColor::Aqua);
		Debug::systemLog("OpenGL Version: " + version, DebugColor::Aqua);

		Debug::newLine();

		Debug::systemLog("GPU: " + gpu, DebugColor::Aqua);
		Debug::systemLog("CPU: " + Util::getCPU(), DebugColor::Aqua);

		Debug::newLine();

		enableAlphaBlending();

		quad.type = HGE_2D;
		quad.create();

		mainShader.create();
		guiShader.create();
		nullTexture.create();
		createProjectionMatrix(screenWidth, screenHeight);

		Debug::newLine();
	}

	void Renderer::createProjectionMatrix(const float& screenWidth, const float& screenHeight) {
		perspectiveMatrix = Mat4f::createPerspectiveMatrix(screenWidth, screenHeight, 90, 0.1f, 1000);
		currentWindowSize.x = screenWidth;
		currentWindowSize.y = screenHeight;
	}

	void Renderer::close() {
		mainShader.close();
		guiShader.close();
	}

	void Renderer::setCamera(const Camera& camera) {
		viewMatrix = Mat4f::createViewMatrix(camera.position, camera.rotation);
	}

	void Renderer::setWireFrameMode(const bool& in) {
		wireframe = in;
		glPolygonMode(GL_FRONT_AND_BACK, in ? GL_LINE : GL_FILL);
	}

	bool Renderer::getWireFrameMode() {
		return wireframe;
	}

	void Renderer::toggleWireFrameMode() {
		setWireFrameMode(!wireframe);
	}

	void Renderer::setCullingMode(const bool& in) {
		cull = in;
		if (cull) {
			glEnable(GL_BACK);
			glEnable(GL_CULL_FACE);
		}
		else {
			glDisable(GL_BACK);
			glDisable(GL_CULL_FACE);
		}
	}

	bool Renderer::getCullingMode() {
		return cull;
	}

	void Renderer::toggleCullingMode() {
		setWireFrameMode(!cull);
	}

	void Renderer::enableAlphaBlending() {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void Renderer::disableAlphaBlending() {
		glDisable(GL_BLEND);
		enableDepthTest();
	}

	void Renderer::enableDepthTest() {
		glEnable(GL_DEPTH_TEST);
	}

	void Renderer::disableDepthTest() {
		glDisable(GL_DEPTH_TEST);
	}

	void Renderer::setLightMode(const int& _lightMode) {
		lightMode = _lightMode;
	}

	int Renderer::getLightMode() {
		return lightMode;
	}

	void Renderer::render(Mesh& mesh, const Vec3f& position, const Vec3f& rotation, const Vec3f& scale, const Texture& texture) {
		render(mesh, mainShader, position, rotation, scale, texture);
	}

	void Renderer::render(Mesh& mesh, Shader& shader, const Transform& transform, const Texture& texture) {
		render(mesh, shader, transform.position, transform.rotation, transform.scale, texture);
	}

	void Renderer::render(Mesh& mesh, const Transform& transform, const Texture& texture) {
		render(mesh, mainShader, transform.position, transform.rotation, transform.scale, texture);
	}

	//position and size in pixels
	void Renderer::renderRectangle(const Vec2f& position, const Vec2f& size, const Texture& texture) {
		disableDepthTest();

		glBindVertexArray(quad.VAO);
		glEnableVertexAttribArray(0);

		guiShader.bind();
		glActiveTexture(GL_TEXTURE0);

		if (!texture.image.data.empty())
			glBindTexture(GL_TEXTURE_2D, texture.textureID);
		else
			glBindTexture(GL_TEXTURE_2D, nullTexture.textureID);

		//matrix stuff
		Mat4f transform = Mat4f::createTransformationMatrix(
			Vec2f((((position.x + (size.x / 2)) / currentWindowSize.x) * 2) - 1, (((currentWindowSize.y - position.y - (size.y / 2)) / currentWindowSize.y) * 2) - 1),
			Vec2f(),
			Vec2f(size.x / currentWindowSize.x, size.y / currentWindowSize.y));

		guiShader.setUniform("transform", transform);
		guiShader.setUniform("hasTexture", true);
		guiShader.setUniform("uiPosition", position);
		guiShader.setUniform("uiWidth", size.x / currentWindowSize.x);
		guiShader.setUniform("uiHeight", size.y / currentWindowSize.y);
		guiShader.setUniform("drawmode", HGE_RECTANGLE);


		glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)quad.vertices.size());

		guiShader.unbind();

		glDisableVertexAttribArray(0);
		glBindVertexArray(0);

		enableDepthTest();
	}

	//position and size in pixels
	void Renderer::renderRectangle(const Vec2f& position, const Vec2f& size, const Vec3f& color) {
		disableDepthTest();

		glBindVertexArray(quad.VAO);
		glEnableVertexAttribArray(0);

		guiShader.bind();

		//matrix stuff
		Mat4f transform = Mat4f::createTransformationMatrix(
			Vec2f((((position.x + (size.x / 2)) / currentWindowSize.x) * 2) - 1, (((currentWindowSize.y - position.y - (size.y / 2)) / currentWindowSize.y) * 2) - 1),
			Vec2f(), 
			Vec2f(size.x / currentWindowSize.x, size.y / currentWindowSize.y));

		guiShader.setUniform("transform", transform);
		guiShader.setUniform("hasTexture", false);
		guiShader.setUniform("color", color);
		guiShader.setUniform("uiPosition", position);
		guiShader.setUniform("uiWidth", size.x / currentWindowSize.x);
		guiShader.setUniform("uiHeight", size.y / currentWindowSize.y);
		guiShader.setUniform("drawmode", HGE_RECTANGLE);


		glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)quad.vertices.size());

		guiShader.unbind();

		glDisableVertexAttribArray(0);
		glBindVertexArray(0);

		enableDepthTest();
	}

	void Renderer::renderRoundedRectangle(const Vec2f& position, const Vec2f& size, const float& radius, const Texture& texture) {

	}

	void Renderer::renderRoundedRectangle(const Vec2f& position, const Vec2f& size, const float& radius, const Vec3f& color) {
		disableDepthTest();

		glBindVertexArray(quad.VAO);
		glEnableVertexAttribArray(0);

		guiShader.bind();

		Vec2f uiposition = Vec2f((((position.x + (size.x / 2)) / currentWindowSize.x) * 2) - 1, (((currentWindowSize.y - position.y - (size.y / 2)) / currentWindowSize.y) * 2) - 1);
		Vec2f uiSize = Vec2f(size.x / currentWindowSize.x, size.y / currentWindowSize.y);

		//matrix stuff
		Mat4f transform = Mat4f::createTransformationMatrix(
			uiposition,
			Vec2f(),
			uiSize);

		guiShader.setUniform("transform", transform);
		guiShader.setUniform("uiSize", size);
		guiShader.setUniform("hasTexture", false);
		guiShader.setUniform("color", color);
		guiShader.setUniform("radius", radius);
		guiShader.setUniform("smoothness", 0.7f);
		guiShader.setUniform("drawmode", HGE_RECTANGLE_ROUNDED);


		glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)quad.vertices.size());

		guiShader.unbind();

		glDisableVertexAttribArray(0);
		glBindVertexArray(0);

		enableDepthTest();
	}

	//position and size in pixels, angle in degrees, also draws from middle
	void Renderer::radialRevealRectangle(const Vec2f& position, const Vec2f& size, const float& angle, const float& offset, const bool& flipped, const Texture& texture) {
		disableDepthTest();

		glBindVertexArray(quad.VAO);
		glEnableVertexAttribArray(0);

		guiShader.bind();

		glActiveTexture(GL_TEXTURE0);

		if (!texture.image.data.empty())
			glBindTexture(GL_TEXTURE_2D, texture.textureID);
		else
			glBindTexture(GL_TEXTURE_2D, nullTexture.textureID);


		//matrix stuff
		Mat4f transform = Mat4f::createTransformationMatrix(
			Vec2f((((position.x + (size.x / 2)) / currentWindowSize.x) * 2) - 1, (((currentWindowSize.y - position.y - (size.y / 2)) / currentWindowSize.y) * 2) - 1),
			Vec2f(),
			Vec2f(size.x / currentWindowSize.x, size.y / currentWindowSize.y));

		guiShader.setUniform("transform", transform);
		guiShader.setUniform("hasTexture", true);
		guiShader.setUniform("angle", (float)HMath::toRadians(angle));
		guiShader.setUniform("offset", (float)HMath::toRadians(offset));
		guiShader.setUniform("flipped", flipped);
		guiShader.setUniform("drawmode", HGE_RADIAL_REVEAL_RENDER);

		glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)quad.vertices.size());

		guiShader.unbind();

		glDisableVertexAttribArray(0);
		glBindVertexArray(0);

		enableDepthTest();
	}

	void Renderer::render(Mesh& mesh, Shader& shader, const Vec3f& position, const Vec3f& rotation, const Vec3f& scale, const Texture& texture) {
		glBindVertexArray(mesh.VAO);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.IBO);

		shader.bind();
		glActiveTexture(GL_TEXTURE0);

		if (!texture.image.data.empty())
			glBindTexture(GL_TEXTURE_2D, texture.textureID);
		else
			glBindTexture(GL_TEXTURE_2D, nullTexture.textureID);

		//matrix stuff
		Mat4f transform = Mat4f::createTransformationMatrix(position, rotation, scale);
		Mat4f projectionViewTransform = perspectiveMatrix * viewMatrix * transform;
		Mat4f projectionTransform = perspectiveMatrix * transform;

		shader.setUniform("projectionViewTransform", projectionViewTransform);
		shader.setUniform("projectionTransform", projectionTransform);
		shader.setUniform("color", mesh.material.albedoColor);
		shader.setUniform("hasTextureCoords", !mesh.texturecoords.empty());
		shader.setUniform("lightMode", lightMode);

		//stupid cast size_t to GLsizei warning
		if (!mesh.indices.empty())
			glDrawElements(GL_TRIANGLES, (int)mesh.indices.size(), GL_UNSIGNED_INT, 0);
		else if(!mesh.vertices.empty())
			glDrawArrays(GL_TRIANGLES, 0, (int)mesh.vertices.size() / mesh.type);

		shader.unbind();

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindVertexArray(0);
	}

}
