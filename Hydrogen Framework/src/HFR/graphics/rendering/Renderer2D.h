
#ifndef HFR_RENDERER2D_HEADER_INCLUDE
#define HFR_RENDERER2D_HEADER_INCLUDE

#include HFR_API
#include HFR_MAT4
#include HFR_TEXTURE
#include HFR_SHADER
#include HFR_VEC2
#include HFR_GUI_ELEMENT
#include HFR_GUI_FRAME
#include HFR_GUI_IMAGE
#include HFR_GUI_TEXT

namespace HFR {

	class DLL_API Renderer2D {
	private:
		static bool wireframe;
		static Mesh quad;
		const static std::vector<float> quadVertices;
		static Vec2f currentWindowSize;

	public:

		static Shader guiFrameShader;
		static Shader guiImageShader;
		static Shader guiTextShader;

		static Mat4f orthoMatrix;
		static Mat4f pixelOrthoMatrix;

		static void init(const float& screenWidth, const float& screenHeight);
		static void createProjectionMatrix(const float& screenWidth, const float& screenHeight);
		static void close();

		static float getAspectRatio();
		//static Vec2f getCurrentWindowSize();

		/*static void setWireFrameMode(const bool& wireframe);
		static void toggleWireFrameMode();
		static bool getWireFrameMode();*/

		static void setDepthTest(const bool& in);
		static void setAlphaBlending(const bool& in);

		/*static void renderRectangle(const Vec2f& position, const Vec2f& size, const Texture& texture);
		static void renderRectangle(const Vec2f& position, const Vec2f& size, const Vec3f& color);
		static void renderRectangle(const Vec2f& position, const Vec2f& size, const float& rotation, const Vec3f& color);

		static void renderRoundedRectangle(const Vec2f& position, const Vec2f& size, const float& radius, const Texture& texture);
		static void renderRoundedRectangle(const Vec2f& position, const Vec2f& size, const float& radius, const Vec3f& color);

		static void radialRevealRectangle(const Vec2f& position, const Vec2f& size, const float& angle, const float& offset, const bool& flipped, const Texture& texture);
		static void radialRevealRectangle(const Vec2f& position, const Vec2f& size, const float& angle, const float& offset, const bool& flipped, const Vec3f& color);*/

		static void render(const GuiFrame& frame);
		static void render(const GuiImage& image);
		static void render(const GuiText& text);

		static void renderGuis();
	};

}

#endif