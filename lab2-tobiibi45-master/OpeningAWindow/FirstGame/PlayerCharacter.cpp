#include "PlayerCharacter.h"



PlayerCharacter::PlayerCharacter() : m_cameraState(CameraViewState::firstPersonCamera)
{
	addComponent(new TransformComponent);
	addComponent(new CameraComponent);
	addComponent(new ModelComponent);

}

void PlayerCharacter::OnUpdate(float dt)
{
	switch (m_cameraState)
	{
		case CameraViewState::firstPersonCamera:
		{
			// get the transform component details
			TransformComponent* transform = getComponent<TransformComponent>();
			// first person view - just have the camera in place on the player
			// need inverse pos and orientation
			getComponent<CameraComponent>()->m_position = -1.0f * transform->m_position;
			getComponent<CameraComponent>()->m_orientation = inverse(transform->m_orientation);
			break;
		}
		case CameraViewState::thirdPersonCamera:
		{
			// get the transform component details
			TransformComponent* transform = getComponent<TransformComponent>();
			// third person view - stay at a set distance from the player
			glm::quat inverseOrientation = inverse(transform->m_orientation);
			getComponent<CameraComponent>()->m_position =
				-1.0f*(transform->m_position + glm::vec3(0, 150, 500) * inverseOrientation);
			getComponent<CameraComponent>()->m_orientation = inverseOrientation;
			break;
		}
	}

}
void PlayerCharacter::OnMessage(const std::string msg)
{
	if (msg == "SetCameraFirstPerson")
	{
		m_cameraState = CameraViewState::firstPersonCamera;
	}
	else if (msg == "SetCameraThirdPerson")
	{
		m_cameraState = CameraViewState::thirdPersonCamera;
	}
	else if (msg.compare(0, 12, "rotateCamera") == 0)
	{
		TransformComponent* transform = getComponent<TransformComponent>();
		float rotationValue;
		if (msg == "rotateCameraLeft") rotationValue = -0.05;
		else rotationValue = 0.05;
		// same rotation for both first and third person cameras
		transform->yaw(rotationValue);
	}
	else if (msg.compare(0, 10, "movePlayer") == 0)
	{
		// determine the correct translation vector
		glm::vec3 translationVector(0, 0, 0);
		if (msg == "movePlayerForward")translationVector.z = -10;
		else if (msg == "movePlayerBackward")translationVector.z = 10;
		else if (msg == "movePlayerLeft")translationVector.x = -10;
		else if (msg == "movePlayerRight")translationVector.x = 10;
		TransformComponent* transform = getComponent<TransformComponent>();
		transform->translate(translationVector
			* inverse(transform->m_orientation));
	}

}

PlayerCharacter::~PlayerCharacter()
{

}
