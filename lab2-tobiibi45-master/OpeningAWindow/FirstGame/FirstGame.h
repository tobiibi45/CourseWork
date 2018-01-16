#pragma once
#include "Game.h"

class FirstGame : public Game
{
public: 
	FirstGame();

	void update(float dt) override;
	void render() override;

	bool loadLevelJSON(std::string levelJSONFile);
};