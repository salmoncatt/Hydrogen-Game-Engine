#include "hfpch.h"
#include "Renderer2D.h"

namespace HFR {


	//void Renderer2D::render(const GuiFrame& frame) {
	//	disableDepthTest();

	//	glBindVertexArray(quad.VAO);
	//	glEnableVertexAttribArray(0);

	//	guiFrameShader.bind();

	//	Vec2f uiPosition;

	//	Mat4f transform;
	//	Mat4f outlineTransform;

	//	//matrix stuff
	//	if (frame.sizeType == HFR_SCREEN_SPACE_SIZE) {

	//		uiPosition = Vec2f(frame.position.x * 2 * Renderer::getAspectRatio(), -frame.position.y * 2) + Vec2f(frame.size.x - frame.size.x * frame.anchorPoint.x * 2, -frame.size.y + frame.size.y * frame.anchorPoint.y * 2);

	//		transform = orthoMatrix * Mat4f::createTransformationMatrix(uiPosition, Vec3f(0, 0, frame.rotation), frame.size);

	//		//because dank aspect ratio madness fuck me
	//		if (currentWindowSize.x < currentWindowSize.y)
	//			guiFrameShader.setUniform("uiSize", Vec2f(frame.size.x * currentWindowSize.x, frame.size.y * currentWindowSize.x));
	//		else
	//			guiFrameShader.setUniform("uiSize", Vec2f(frame.size.x * currentWindowSize.y, frame.size.y * currentWindowSize.y));

	//	}
	//	else if (frame.sizeType == HFR_PIXEL_SIZE) {

	//		transform = pixelOrthoMatrix * Mat4f::createTransformationMatrix(Vec2f(frame.position.x * 2, -frame.position.y * 2) + Vec2f(frame.size.x - frame.size.x * frame.anchorPoint.x * 2, -frame.size.y + frame.size.y * frame.anchorPoint.y * 2), Vec3f(0, 0, frame.rotation), frame.size);

	//		guiFrameShader.setUniform("uiSize", frame.size);
	//	}

	//	guiFrameShader.setUniform("transform", transform);
	//	guiFrameShader.setUniform("color", frame.backgroundColor);
	//	guiFrameShader.setUniform("borderColor", frame.borderColor);
	//	guiFrameShader.setUniform("borderSize", (float)frame.borderSize);
	//	guiFrameShader.setUniform("cornerRadius", (float)frame.roundedCornerRadius);
	//	guiFrameShader.setUniform("aspectRatio", getAspectRatio());


	//	glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)quad.vertices.size());

	//	guiFrameShader.unbind();

	//	glDisableVertexAttribArray(0);
	//	glBindVertexArray(0);

	//	enableDepthTest();
	//}



}