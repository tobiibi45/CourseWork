#include "Game.h"
#include "TransformComponent.h"
#include "ColourComponent.h"
#include "Scene.h"

Scene::Scene()
{
}

void Scene::update()
{
	// perform all the logic for your game world
	
}

void Scene::render(IEngineCore* engineInterfacePtr)
{
	// e.g. pass object details to the engine to render the next frame
	// also clears the screen ready for the next frame
	engineInterfacePtr->renderColouredBackground(0, 0, 0);

	// update the camera (probably don't need to do this each frame)
	engineInterfacePtr->setCamera(&m_camera);

	// draw the cubes
	for (auto cube : v_gameObjects)
	{
		engineInterfacePtr->drawCube(cube.getComponent<TransformComponent>()->getModelMatrix());
	}
}

void Scene::cleanup()
{
	// cleanup any memory created in the scene
}
