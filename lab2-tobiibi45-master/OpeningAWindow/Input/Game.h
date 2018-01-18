#pragma once
#include "IEngineCore.h"
#include "InputHandler.h"

class Game
{
public:

	virtual ~Game() = default;
	IEngineCore* m_engineInterfacePtr;
	InputHandler* m_inputHandler;

	virtual void update(float dt) = 0;
	virtual void render() = 0;
};
