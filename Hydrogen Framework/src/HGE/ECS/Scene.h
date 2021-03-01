
#ifndef HGE_SCENE_HEADER_INCLUDE
#define HGE_SCENE_HEADER_INCLUDE

#include HGE_API

#include "ECS.h"
#include "HGE/camera/EditorCamera.h"
#include "HGE/ECS/components/Texture.h"

namespace HGE {

	struct Entity;
	struct GameObject;

	class DLL_API Scene {
	private:
		System system;

		//GuiWindow performanceStats;
		//GuiWindow gameObjectList;
		//GuiWindow gameObjectComponentsList;

		Texture radialBarTexture;
		float lerpedCpuUsage;
		float lerpedRamUsage;

	public:
		EditorCamera editorCamera;

		void initialize();

		Scene();
		~Scene();

		GameObject createGameObject(const std::string& name);

		void updateEditor();
		//void startPlay();
		//void updatePlay();

		System* getSystem();

	};


}

#endif