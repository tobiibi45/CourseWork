#pragma once
#include "IEngineCore.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "ColourComponent.h"
#include "Scene.h"
#include "Camera.h"
#include "Model.h"

class Game
{
public:
	Game();
	IEngineCore* m_engineInterfacePtr;
	InputHandler* m_inputHandler;
	Scene* m_currentScene;

	void update();
	void render();

	void loadLevel(std::string levelFile);
	bool loadLevelJSON(std::string levelJSONFile);

private:
	Camera m_camera;
	Model *theModel;
};
