

#ifndef HFR_RENDERER_HEADER_INCLUDE
#define HFR_RENDERER_HEADER_INCLUDE

#include HFR_API
#include HFR_MAT4
#include HFR_TEXTURE
#include HFR_SHADER
#include HFR_VEC2

namespace HFR {

	struct Camera;
	class Mesh;
	struct Vec3f;
	struct Transform;
	struct GameObject;
	class GuiFrame;
	class Font;

	class DLL_API Renderer {
	private:
		static bool wireframe;
		static bool cull;
		static int lightMode;
		static Mesh quad;
		const static std::vector<float> quadVertices;
		static Vec2f currentWindowSize;

	public:
		static Shader mainShader;
		static Shader guiShader;
		static Shader guiFrameShader;
		static Shader textShader;

		static Texture nullTexture;
		
		static Mat4f perspectiveMatrix;
		static Mat4f orthoMatrix;
		static Mat4f pixelOrthoMatrix;
		static Mat4f viewMatrix;

		static void init(const float& screenWidth, const float& screenHeight);
		static void createProjectionMatrix(const float& screenWidth, const float& screenHeight);
		static void close();
		static void setCamera(const Camera& camera);

		static float getAspectRatio();
		static Vec2f getCurrentWindowSize();

		static void setWireFrameMode(const bool& wireframe);
		static void toggleWireFrameMode();
		static bool getWireFrameMode();

		static void setCullingMode(const bool& cull);
		static void toggleCullingMode();
		static bool getCullingMode();

		static void enableAlphaBlending();
		static void disableAlphaBlending();

		static void enableDepthTest();
		static void disableDepthTest();

		static void setLightMode(const int& lightMode);
		static int getLightMode();

		static void render(Mesh& mesh, const Vec3f& position, const Vec3f& rotation, const Vec3f& scale, const Texture& texture);
		static void render(Mesh& mesh, Shader& shader, const Vec3f& position, const Vec3f& rotation, const Vec3f& scale, const Texture& texture);

		static void render(Mesh& mesh, const Transform& transform, const Texture& texture);
		static void render(Mesh& mesh, Shader& shader, const Transform& transform, const Texture& texture);

		static void renderRectangle(const Vec2f& position, const Vec2f& size, const Texture& texture);
		static void renderRectangle(const Vec2f& position, const Vec2f& size, const Vec3f& color);
		static void renderRectangle(const Vec2f& position, const Vec2f& size, const float& rotation, const Vec3f& color);
		
		static void renderRoundedRectangle(const Vec2f& position, const Vec2f& size, const float& radius, const Texture& texture);
		static void renderRoundedRectangle(const Vec2f& position, const Vec2f& size, const float& radius, const Vec3f& color);

		static void radialRevealRectangle(const Vec2f& position, const Vec2f& size, const float& angle, const float& offset, const bool& flipped, const Texture& texture);
		static void radialRevealRectangle(const Vec2f& position, const Vec2f& size, const float& angle, const float& offset, const bool& flipped, const Vec3f& color);

		static void render(const GuiFrame& frame);

		static void renderGuis();

		//scale scales the pixel size used to create the font (48 pixels tall by default), also creates mesh on the fly so isn't as efficient as static text just so you know
		static void render(const Font& font, const char* text, const Vec2i& position, const Vec2i& scale, const Vec4f& color);
	};

}

#endif