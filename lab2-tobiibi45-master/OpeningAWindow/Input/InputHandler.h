#pragma once
#include <map>
#include "GameObject.h"
#include <vector>
#include "TransformComponent.h"


class InputCommand
{
public:
	virtual ~InputCommand() {}
	virtual void execute(GameObject& playerBackground) = 0;
};


class RotateLeftCommand : public InputCommand
{
public:
	void execute(GameObject& playerCube) override
	{
		if (playerCube.getComponent<TransformComponent>())
			playerCube.getComponent<TransformComponent>()->OnMessage("rotateLeft");
	}
};

class RotateRightCommand : public InputCommand
{
public:
	void execute(GameObject& playerCube) override
	{
		if (playerCube.getComponent<TransformComponent>())
			playerCube.getComponent<TransformComponent>()->OnMessage("rotateRight");
	}
};

class rotateUpCommand : public InputCommand
{
public:
	void execute(GameObject& cube) override
	{
		if (cube.getComponent<TransformComponent>())
			cube.getComponent<TransformComponent>()->OnMessage("rotateUp");
	}

};
class rotateDownCommand : public InputCommand
{
public:
	void execute(GameObject& cube) override
	{
		if (cube.getComponent<TransformComponent>())
			cube.getComponent<TransformComponent>()->OnMessage("rotateDown");
	}

};

class scaleUpCommand : public InputCommand
{
public:
	void execute(GameObject& cube) override
	{
		if (cube.getComponent<TransformComponent>())
			cube.getComponent<TransformComponent>()->OnMessage("scaleUp");
	}

};
class scaleDownCommand : public InputCommand
{
public:
	void execute(GameObject& cube) override
	{
		if (cube.getComponent<TransformComponent>())
			cube.getComponent<TransformComponent>()->OnMessage("scaleDown");
	}

};

class TranslateLeftCommand : public InputCommand
{
public:
	void execute(GameObject& playerCube) override
	{
		if (playerCube.getComponent<TransformComponent>())
			playerCube.getComponent<TransformComponent>()->OnMessage("translateLeft");
	}
};

class TranslateRightCommand : public InputCommand
{
public:
	void execute(GameObject& playerCube) override
	{
		if (playerCube.getComponent<TransformComponent>())
			playerCube.getComponent<TransformComponent>()->OnMessage("translateRight");
	}
};
class TranslateUpCommand : public InputCommand
{
public:
	void execute(GameObject& playerCube) override
	{
		if (playerCube.getComponent<TransformComponent>())
			playerCube.getComponent<TransformComponent>()->OnMessage("translateUp");
	}
};

class TranslateDownCommand : public InputCommand
{
public:
	void execute(GameObject& playerCube) override
	{
		if (playerCube.getComponent<TransformComponent>())
			playerCube.getComponent<TransformComponent>()->OnMessage("translateDown");
	}
};

struct InputHandler
{
	//GameObject* m_playerBackground;
	GameObject* m_playerCube;

	std::map<int, InputCommand*> m_controlMapping;

	InputHandler(GameObject* playerCube) : m_playerCube(playerCube)
	{
		// the idea will be to map the keys directly from a config file that can be loaded in
		// and changed on the fly
		m_controlMapping[65] = new RotateLeftCommand;
		m_controlMapping[68] = new RotateRightCommand;
		m_controlMapping[87] = new rotateUpCommand;
		m_controlMapping[83] = new rotateDownCommand;
		m_controlMapping[90] = new scaleUpCommand;
		m_controlMapping[88] = new scaleDownCommand;
		m_controlMapping[69] = new TranslateLeftCommand;
		m_controlMapping[81] = new TranslateRightCommand;
		m_controlMapping[82] = new TranslateUpCommand;
		m_controlMapping[84] = new TranslateDownCommand;
	}

	void handleInputs(const std::vector<bool>& keyBuffer)
	{
		for (const auto& mapEntry : m_controlMapping)
		{
			if (keyBuffer[mapEntry.first])
			{
				mapEntry.second->execute(*m_playerCube);
			}
		}

	}
};

