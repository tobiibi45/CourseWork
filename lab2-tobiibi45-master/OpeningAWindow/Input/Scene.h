#pragma once

#include "GameObject.h"
#include "Camera.h"

class Scene
{
public:
	Scene();

	void update();
	void render(IEngineCore* m_engineInterfacePtr);

	void cleanup();

	GameObject m_playerBackground;
	GameObject m_playerCube;

	std::vector<GameObject*> v_gameObjects;
	Camera m_camera;
};
