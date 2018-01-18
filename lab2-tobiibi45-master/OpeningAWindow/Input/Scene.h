#pragma once

#include "IEngineCore.h"

class Scene
{
public:
	virtual ~Scene() = default;

	virtual void update() = 0;
	virtual void render(IEngineCore* m_engineInterfacePtr) = 0;

	virtual void cleanup() = 0;
};
