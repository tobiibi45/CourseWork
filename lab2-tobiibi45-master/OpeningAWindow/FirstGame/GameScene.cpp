#include "GameScene.h"



GameScene::GameScene()
{

}

void GameScene::update()
{

}


void GameScene::render(IEngineCore * m_engineInterfacePtr)
{
	// e.g. pass object details to the engine to render the next frame
	// e.g. pass object details to the engine to render the next frame
	// also clears the screen ready for the next frame
	m_engineInterfacePtr->renderColouredBackground(0, 0, 0);

	// update the camera (probably don't need to do this each frame)
	/*for (int i = 0; i < v_gameObjects.size(); i++)
	{
		m_engineInterfacePtr->setCamera(v_gameObjects[i]->getComponent<CameraComponent>());
	}*/
	m_engineInterfacePtr->setCamera(m_camera);
	

	// draw the models
	for (auto gameobjects : v_gameObjects)
	{

		m_engineInterfacePtr->drawModel(gameobjects->getComponent<ModelComponent>()->themodel 
			,gameobjects->getComponent<TransformComponent>()->getModelMatrix());
	}

}

void GameScene::cleanup()
{

}

GameScene::~GameScene()
{

}
