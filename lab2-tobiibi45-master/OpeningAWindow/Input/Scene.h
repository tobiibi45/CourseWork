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

	std::vector<GameObject*> v_gameObjects;
	CameraComponent* m_camera;
};
