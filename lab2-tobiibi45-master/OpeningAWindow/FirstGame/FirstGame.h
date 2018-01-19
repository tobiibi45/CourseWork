#pragma once
#include "Game.h"
#include "GameScene.h"
#include <ModelManager.h>

class FirstGame : public Game
{
	enum class SceneChange { firstScene, SecondScene, ThirdScene };
public: 
	FirstGame();

	void update(float dt) override;
	void render() override;

	bool loadLevelJSON(std::string levelJSONFile);

	GameScene* m_currentscene;
	ModelManager mm;
	SceneChange scene_change;
	TransformComponent* trans;

};