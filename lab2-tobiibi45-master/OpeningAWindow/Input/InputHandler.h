#pragma once
#include <map>
#include "GameObject.h"
#include <vector>
#include "TransformComponent.h"
#include "CameraComponent.h"


class InputCommand
{
public:
	virtual ~InputCommand() {}
	virtual void execute(GameObject& gameobject) = 0;
};


class RotateCameraLeft : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("rotateCameraLeft");
	}
};

class RotateCameraRight : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("rotateCameraRight");
	}
};

class RotateCameraUp : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("rotateCameraUp");
	}

};
class RotateCameraDown : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("rotateCameraDown");
	}

};

class MovePlayerLeft : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("MovePlayerLeft");
	}

};
class MovePlayerRight : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("MovePlayerRight");
	}

};

class MovePlayerForward : public InputCommand
{
public:
	void execute(GameObject&gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("MovePlayerForward");
	}
};

class MovePlayerBack : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("MovePlayerBack");
	}
};
class FirstPersonCamera : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("FirstPersonCamera");
	}
};

class ThirdPersonCamera : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.getComponent<CameraComponent>()->OnMessage("ThirdPersonCamera");
	}
};

struct InputHandler
{
	GameObject* m_gameobjects;

	std::vector<GameObject*> v_objectsRequiringInput;

	std::map<int, InputCommand*> m_controlMapping;


	InputHandler(GameObject* objectsRequiringInput) : m_gameobjects(objectsRequiringInput)
	{
		// the idea will be to map the keys directly from a config file that can be loaded in
		// and changed on the fly
		m_controlMapping[65] = new RotateCameraLeft;
		m_controlMapping[68] = new RotateCameraRight;
		m_controlMapping[87] = new RotateCameraUp;
		m_controlMapping[83] = new RotateCameraDown;
		m_controlMapping[90] = new MovePlayerLeft;
		m_controlMapping[88] = new MovePlayerRight;
		m_controlMapping[69] = new MovePlayerForward;
		m_controlMapping[81] = new MovePlayerBack;
		m_controlMapping[82] = new FirstPersonCamera;
		m_controlMapping[84] = new ThirdPersonCamera;
	}

	void handleInputs(const std::vector<bool>& keyBuffer)
	{
		for (const auto& mapEntry : m_controlMapping)
		{
			if (keyBuffer[mapEntry.first])
			{
				mapEntry.second->execute(*m_gameobjects);
			}
		}

	}
};
