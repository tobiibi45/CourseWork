#include "GameScene.h"



GameScene::GameScene()
{

}


GameScene::~GameScene()
{

}

void GameScene::update()
{

}


void GameScene::render(IEngineCore * m_engineInterfacePtr)
{
	// e.g. pass object details to the engine to render the next frame
	// also clears the screen ready for the next frame
	m_engineInterfacePtr->renderColouredBackground(0, 0, 0);

	// update the camera (probably don't need to do this each frame)

	m_engineInterfacePtr->setCamera(m_camera);
}

void GameScene::cleanup()
{

}
