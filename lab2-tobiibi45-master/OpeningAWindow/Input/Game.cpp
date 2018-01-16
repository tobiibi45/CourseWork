#include "Game.h"
#include "TransformComponent.h"
#include "ColourComponent.h"

Game::Game()
{
	

}

//void Game::update()
//{
//	// perform all the logic for your game world
//	if (m_currentScene)
//		m_currentScene->update();
//}
//
//void Game::render()
//{
//	//// perform all the logic for your game world
//	//if (m_currentScene)
//	//	m_currentScene->render(m_engineInterfacePtr);
//
//	// update the camera (probably don't need to do this each frame)
//	m_engineInterfacePtr->setCamera(&m_camera);
//
//	// draw the cube
//	m_engineInterfacePtr->drawCube(m_currentScene->m_playerCube.getComponent<TransformComponent>()->getModelMatrix());
//}