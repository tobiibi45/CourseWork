#pragma once
#include "Game.h"
#include "GameScene.h"
#include <ModelManager.h>

class FirstGame : public Game
{
public: 
	FirstGame();

	void update(float dt) override;
	void render() override;

	bool loadLevelJSON(std::string levelJSONFile);

	GameScene* m_currentscene;
	ModelManager mm;
};