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
			gameobject.getComponent<CameraComponent>()->OnMessage("rotateCameraRight");
		std::cout << "Pressing Left Arrow" << "/n";
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
			gameobject.OnMessage("rotateCameraDown");
	}

};

class MovePlayerLeft : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.OnMessage("MovePlayerLeft");
	}

};
class MovePlayerRight : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<TransformComponent>())
			gameobject.OnMessage("MovePlayerRight");
	}

};

class MovePlayerForward : public InputCommand
{
public:
	void execute(GameObject&gameobject) override
	{
		if (gameobject.getComponent<TransformComponent>())
			gameobject.OnMessage("MovePlayerForward");
	}
};

class MovePlayerBack : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<TransformComponent>())
			gameobject.OnMessage("MovePlayerBack");
	}
};
class FirstPersonCamera : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.OnMessage("FirstPersonCamera");
	}
};

class ThirdPersonCamera : public InputCommand
{
public:
	void execute(GameObject& gameobject) override
	{
		if (gameobject.getComponent<CameraComponent>())
			gameobject.OnMessage("ThirdPersonCamera");
	}
};

struct InputHandler
{

	std::vector<GameObject*> v_objectsRequiringInput;
	std::map<int, InputCommand*> m_controlMapping;

	InputHandler()
		{

			// the idea will be to map the keys directly from a config file that can be loaded in
			// and changed on the fly
			m_controlMapping[37] = new RotateCameraLeft; // Left Arrow
			m_controlMapping[39] = new RotateCameraRight; // Right Arrow
			m_controlMapping[38] = new RotateCameraUp; // Up Arrow
			m_controlMapping[40] = new RotateCameraDown; // Down Arrow
			m_controlMapping[65] = new MovePlayerLeft; // A
			m_controlMapping[68] = new MovePlayerRight; // D
			m_controlMapping[87] = new MovePlayerForward; // W
			m_controlMapping[83] = new MovePlayerBack; // S
			m_controlMapping[49] = new FirstPersonCamera; // 1
			m_controlMapping[50] = new ThirdPersonCamera; // 2
		}

	void handleInputs(const std::vector<bool>& keyBuffer)
	{
		for (const auto& mapEntry : m_controlMapping)
		{
			if (keyBuffer[mapEntry.first])
			{
				for (int i = 0; i < v_objectsRequiringInput.size(); i++)
				{
					mapEntry.second->execute(*v_objectsRequiringInput[i]);
				}
			}
		}

	}

	void addObjects(GameObject* objects)
	{
		v_objectsRequiringInput.push_back(objects);

	}
};
