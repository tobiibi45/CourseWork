#pragma once

#include "GameObject.h"
#include "CameraComponent.h"
#include "IEngineCore.h"

class Scene
{
public:
	Scene() {};

	virtual void update() = 0;
	virtual void render(IEngineCore* m_engineInterfacePtr) = 0;

	virtual void cleanup() = 0;

	std::vector<GameObject*> v_gameObjects;
	//CameraComponent* m_camera;
};
