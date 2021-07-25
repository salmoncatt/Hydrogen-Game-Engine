#include "hfpch.h"
#include "Renderer2D.h"

namespace HFR {

	Shader Renderer2D::guiFrameShader = HFR::Shader(HFR_RES + "shaders/", "guiVertex.glsl", "guiFrameFragment.glsl");
	Shader Renderer2D::guiImageShader = HFR::Shader(HFR_RES + "shaders/", "guiVertex.glsl", "guiImageFragment.glsl");
	Shader Renderer2D::guiTextShader = HFR::Shader(HFR_RES + "shaders/", "guiTextVertex.glsl", "guiTextFragment.glsl");


	Mat4f Renderer2D::orthoMatrix = Mat4f::createOrthoMatrix(-1, 1, -1, 1, -1, 1);
	Mat4f Renderer2D::pixelOrthoMatrix = Mat4f::createOrthoMatrix(-1, 1, -1, 1, -1, 1);

	const std::vector<float> Renderer2D::quadVertices = { -1, 1,  -1, -1,  1, 1, 1, -1 };
	Mesh Renderer2D::quad = Mesh(quadVertices, std::vector<unsigned int>(), std::vector<float>(), std::vector<float>());
	
	Vec2f Renderer2D::currentWindowSize = Vec2f();

	void Renderer2D::init(const float& screenWidth, const float& screenHeight) {
		//show opengl stuff
		Debug::newLine();

		setAlphaBlending(true);

		quad.type = HFR_2D;
		quad.create();

		Debug::systemLog("Creating gui shaders");

		guiFrameShader.create();
		guiImageShader.create();
		guiTextShader.create();

		createProjectionMatrix(screenWidth, screenHeight);

		Debug::systemSuccess("Created gui shaders");

		Debug::newLine();
	}

	void Renderer2D::createProjectionMatrix(const float& screenWidth, const float& screenHeight) {
		currentWindowSize.x = screenWidth;
		currentWindowSize.y = screenHeight;

		glViewport(0, 0, (GLsizei)screenWidth, (GLsizei)screenHeight);

		//for use with pixel sized gui (top left coordinate system btw)
		pixelOrthoMatrix = Mat4f::createOrthoMatrix(0, 2 * screenWidth, -2 * screenHeight, 0, -1, 1);

		//its weird for top left based coords
		if (screenWidth < screenHeight)
			orthoMatrix = Mat4f::createOrthoMatrix(0, 2, -2 / getAspectRatio(), 0, -1, 1);
		else
			orthoMatrix = Mat4f::createOrthoMatrix(0, 2 * getAspectRatio(), -2, 0, -1, 1);
	}

	void Renderer2D::close() {
		guiFrameShader.close();
		guiImageShader.close();
		guiTextShader.close();

	}

	void Renderer2D::setDepthTest(const bool& in) {
		if(in)
			glEnable(GL_DEPTH_TEST);
		else
			glDisable(GL_DEPTH_TEST);
	}

	void Renderer2D::setAlphaBlending(const bool& in) {
		if (in) {
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}else
			glDisable(GL_BLEND);
	}

	float Renderer2D::getAspectRatio() {
		return currentWindowSize.x / currentWindowSize.y;
	}

	void Renderer2D::render(const GuiFrame& frame) {

		glBindVertexArray(quad.VAO);
		glEnableVertexAttribArray(0);

		guiFrameShader.bind();

		Vec2f uiPosition;

		Mat4f transform;
		Mat4f outlineTransform;

		//matrix stuff
		if (frame.sizeType == HFR_SCREEN_SPACE_SIZE) {

			uiPosition = Vec2f(frame.position.x * 2 * Renderer::getAspectRatio(), -frame.position.y * 2) + Vec2f(frame.size.x - frame.size.x * frame.anchorPoint.x * 2, -frame.size.y + frame.size.y * frame.anchorPoint.y * 2);

			transform = orthoMatrix * Mat4f::createTransformationMatrix(uiPosition, Vec3f(0, 0, frame.rotation), frame.size);

			//because dank aspect ratio madness fuck me
			if (currentWindowSize.x < currentWindowSize.y)
				guiFrameShader.setUniform("uiSize", Vec2f(frame.size.x * currentWindowSize.x, frame.size.y * currentWindowSize.x));
			else
				guiFrameShader.setUniform("uiSize", Vec2f(frame.size.x * currentWindowSize.y, frame.size.y * currentWindowSize.y));

		}
		else if (frame.sizeType == HFR_PIXEL_SIZE) {

			transform = pixelOrthoMatrix * Mat4f::createTransformationMatrix(Vec2f(frame.position.x * 2, -frame.position.y * 2) + Vec2f(frame.size.x - frame.size.x * frame.anchorPoint.x * 2, -frame.size.y + frame.size.y * frame.anchorPoint.y * 2), Vec3f(0, 0, frame.rotation), frame.size);

			guiFrameShader.setUniform("uiSize", frame.size);
		}

		guiFrameShader.setUniform("transform", transform);
		guiFrameShader.setUniform("color", frame.backgroundColor);
		guiFrameShader.setUniform("borderColor", frame.borderColor);
		guiFrameShader.setUniform("borderSize", (float)frame.borderSize);
		guiFrameShader.setUniform("cornerRadius", (float)frame.roundedCornerRadius);
		guiFrameShader.setUniform("aspectRatio", getAspectRatio());


		glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)quad.vertices.size());

		guiFrameShader.unbind();

		glDisableVertexAttribArray(0);
		glBindVertexArray(0);
	}

	void Renderer2D::render(const GuiImage& image) {

		glBindVertexArray(quad.VAO);
		glEnableVertexAttribArray(0);

		guiImageShader.bind();

		Vec2f uiPosition;

		Mat4f transform;
		Mat4f outlineTransform;

		//matrix stuff
		if (image.sizeType == HFR_SCREEN_SPACE_SIZE) {

			uiPosition = Vec2f(image.position.x * 2 * Renderer::getAspectRatio(), -image.position.y * 2) + Vec2f(image.size.x - image.size.x * image.anchorPoint.x * 2, -image.size.y + image.size.y * image.anchorPoint.y * 2);

			transform = orthoMatrix * Mat4f::createTransformationMatrix(uiPosition, Vec3f(0, 0, image.rotation), image.size);

			//because dank aspect ratio madness fuck me
			if (currentWindowSize.x < currentWindowSize.y)
				guiImageShader.setUniform("uiSize", Vec2f(image.size.x * currentWindowSize.x, image.size.y * currentWindowSize.x));
			else
				guiImageShader.setUniform("uiSize", Vec2f(image.size.x * currentWindowSize.y, image.size.y * currentWindowSize.y));

		}
		else if (image.sizeType == HFR_PIXEL_SIZE) {

			transform = pixelOrthoMatrix * Mat4f::createTransformationMatrix(Vec2f(image.position.x * 2, -image.position.y * 2) + Vec2f(image.size.x - image.size.x * image.anchorPoint.x * 2, -image.size.y + image.size.y * image.anchorPoint.y * 2), Vec3f(0, 0, image.rotation), image.size);

			guiImageShader.setUniform("uiSize", image.size);
		}

		guiImageShader.setUniform("transform", transform);
		guiImageShader.setUniform("color", image.color);

		guiImageShader.setUniform("angle", (float)HMath::toRadians((int)image.radialFill));
		guiImageShader.setUniform("offsetAngle", (float)HMath::toRadians((int)image.radialFillAngleOffset));
		guiImageShader.setUniform("radialFillOffset", image.radialFillOffset);
		guiImageShader.setUniform("radialFillFlipped", image.radialFillInverse);

		guiImageShader.setUniform("fill", image.fill);
		guiImageShader.setUniform("fillOffset", image.fillOffset);

		if (image.texture.image.hasData()) {
			guiImageShader.setUniform("hasTextureCoords", true);
			
			glActiveTexture(GL_TEXTURE0);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image.texture.textureID);
		}

		glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)quad.vertices.size());

		guiImageShader.unbind();

		glDisableVertexAttribArray(0);
		glBindVertexArray(0);
	}

	void Renderer2D::render(const GuiText& text) {
		setDepthTest(false);
		setAlphaBlending(true);

		glBindVertexArray(text.mesh.VAO);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		guiTextShader.bind();

		glActiveTexture(GL_TEXTURE0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, text.font.texture.textureID);


		guiTextShader.setUniform("color", text.color);

		if (!text.mesh.vertices.empty())
			glDrawArrays(GL_TRIANGLES, 0, (int)text.mesh.vertices.size() / text.mesh.type);


		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glBindVertexArray(0);

		guiTextShader.unbind();

		setDepthTest(true);
		setAlphaBlending(false);
	}

	void Renderer2D::renderGuis() {
		setDepthTest(false);
		setAlphaBlending(true);


		for (size_t i = 0; i < Engine::guiFrames.size(); ++i) {
			auto& frame = Engine::guiFrames[i];
			if (frame->active && frame->draggable && frame->isSelected())
				frame->position += frame->sizeType == HFR_PIXEL_SIZE ? Vec2f(Input::getMouseMovement().x / 2, Input::getMouseMovement().y / 2) : Vec2f(Input::getMouseMovementScreenSpace().x / 2, Input::getMouseMovementScreenSpace().y / 2);

			if (frame->visible)
				Renderer2D::render(*frame);
		}


		for (size_t i = 0; i < Engine::guiImages.size(); ++i) {
			auto& image = Engine::guiImages[i];

			if (image->visible)
				Renderer2D::render(*image);
		}
		setDepthTest(true);
		setAlphaBlending(false);
	}

}