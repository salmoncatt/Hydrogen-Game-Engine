
#ifndef HFR_SCENE_HEADER_INCLUDE
#define HFR_SCENE_HEADER_INCLUDE

#include HFR_API

#include "ECS.h"
#include HFR_EDITOR_CAMERA
#include HFR_TEXTURE

namespace HFR {

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