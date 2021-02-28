

#ifndef HGE_RENDERER_HEADER_INCLUDE
#define HGE_RENDERER_HEADER_INCLUDE

#include HGE_API
#include "HGE/math/matrixes/Mat4.h"
#include "HGE/ECS/components/Texture.h"
#include "HGE/graphics/rendering/Shader.h"
#include "HGE/math/vectors/Vec2.h"

namespace HGE {

	struct Camera;
	class Mesh;
	struct Vec3f;
	struct Transform;
	struct GameObject;
	struct GuiButton;
	struct GuiWindow;

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
		static Texture nullTexture;
		static Mat4f perspectiveMatrix;
		static Mat4f orthoMatrix;
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

		static void render(const GuiWindow& window);

	};

}

#endif