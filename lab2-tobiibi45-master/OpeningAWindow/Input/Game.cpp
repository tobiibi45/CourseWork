#include "Game.h"
#include "TransformComponent.h"
#include "ColourComponent.h"
#include <fstream>
#include <sstream>
#include "json.h"

Game::Game()
{

	//loadLevel("assets/levels/myCubeLevel.txt");
	//loadLevelJSON("assets/levels/myCubeLevel.json");

	m_currentScene->m_playerBackground.addComponent(new RedComponent);
	m_currentScene->m_playerBackground.addComponent(new GreenComponent);
	m_currentScene->m_playerBackground.addComponent(new BlueComponent);
	m_currentScene->m_playerCube.addComponent(new TransformComponent);


	m_engineInterfacePtr = nullptr;
	//m_inputHandler = nullptr;
	m_inputHandler = new InputHandler(&m_currentScene->m_playerCube);

	// move the cube
	TransformComponent* temp = m_currentScene->m_playerCube.getComponent<TransformComponent>();
	temp->translate(0, 0, -5);

}

void Game::update()
{
	// perform all the logic for your game world
	if (m_currentScene)
		m_currentScene->update();
}

void Game::render()
{
	//// perform all the logic for your game world
	//if (m_currentScene)
	//	m_currentScene->render(m_engineInterfacePtr);

	// update the camera (probably don't need to do this each frame)
	m_engineInterfacePtr->setCamera(&m_camera);

	// draw the cube
	m_engineInterfacePtr->drawCube(m_currentScene->m_playerCube.getComponent<TransformComponent>()->getModelMatrix());
}