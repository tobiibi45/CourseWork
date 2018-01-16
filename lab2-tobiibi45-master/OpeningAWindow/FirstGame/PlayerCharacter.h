#pragma once
#include "GameObject.h"
class PlayerCharacter : public GameObject
{
	enum class CameraViewState { firstPersonCamera, thirdPersonCamera };

public:
	PlayerCharacter();
	~PlayerCharacter();

	void OnUpdate(float dt) override;
	void OnMessage(const std::string msg) override;

	CameraViewState m_cameraState;
};

