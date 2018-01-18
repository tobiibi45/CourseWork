#pragma once
#include "Scene.h"
#include <IEngineCore.h>
#include <CameraComponent.h>
#include <GameObject.h>

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	void update() override;
	void render(IEngineCore* m_engineInterfacePtr) override;

	void cleanup() override;

	CameraComponent* m_camera;
	std::vector<GameObject*> v_gameObjects;


};
