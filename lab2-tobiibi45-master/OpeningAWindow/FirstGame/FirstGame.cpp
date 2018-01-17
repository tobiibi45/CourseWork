#pragma once
#include "FirstGame.h"
#include <fstream>
#include <sstream>
#include <json.h>
#include "PlayerCharacter.h"
#include <GameObject.h>
#include "GameObjects.h"
#include <InputHandler.h>
#include <Model.h>

FirstGame::FirstGame()
{
	//loadLevelJSON("assets/levels/level1");
	m_currentScene = new GameScene;
	m_engineInterfacePtr = nullptr;

}

void FirstGame::update(float dt)
{
	

}

void FirstGame::render()
{
	// perform all the logic for your game world
	if (m_currentScene)
		m_currentScene->render(m_engineInterfacePtr);
}

bool FirstGame::loadLevelJSON(std::string levelJSONFile)
{
	mm.addModel("duck.dae");
	mm.addModel("floor.dae");
	//Model* player = new Model("assets/models/duck/duck.dae");
	//Model* floor = new Model("assets/models/duck/floor.dae");

	if (m_currentScene)
	{
		m_currentScene->cleanup();
		delete m_currentScene;
	}

	std::ifstream jsonData;
	Json::Value root;

	jsonData.open(levelJSONFile.c_str());

	Json::Reader reader;
	if (!reader.parse(jsonData, root))
	{
		std::cout << "Failed to parse data from: " << levelJSONFile << reader.getFormattedErrorMessages();
		return false;
	}
	const Json::Value gameObjects = root["GameObjects"];


	for (int i = 0; i < gameObjects.size(); i++)
	{
		string name = gameObjects[i]["name"].asString();

		if (name == "duck")
		{
			mm.getModel("duck.dae");

		}
		else if (name == "floor")
		{
			mm.getModel("floor.dae");
		}

		float w, x, y, z;
		const Json::Value orientNode = gameObjects[i]["orientation"];

		// check if the node exists
		if (orientNode.type() != Json::nullValue)
		{
			w = orientNode[0].asFloat();
			x = orientNode[1].asFloat();
			y = orientNode[2].asFloat();
			z = orientNode[3].asFloat();
		}
		else
		{
			w = 1; x = 0; y = 0; z = 0;
		}

		glm::quat orient(w, x, y, z);

		// has to have a position node
		const Json::Value posNode = gameObjects[i]["position"];
		x = posNode[0].asFloat();
		y = posNode[1].asFloat();
		z = posNode[2].asFloat();

		glm::vec3 pos(x, y, z);

		const Json::Value scaleNode = gameObjects[i]["scale"];

		// check if the node exists
		if (scaleNode.type() != Json::nullValue)
		{
			x = orientNode[1].asFloat();
			y = orientNode[2].asFloat();
			z = orientNode[3].asFloat();
		}
		else
		{
			x = 1; y = 1; z = 1;
		}
		
		glm::vec3 scale(x, y, z);

		m_currentScene->v_gameObjects[i]->addComponent(new TransformComponent(pos, orient, scale));

		string type = gameObjects[i]["type"].asString();

		if (type == "PlayerCharacter")
		{
			m_currentscene->v_gameObjects.push_back(new PlayerCharacter());
			m_currentscene->m_camera = m_currentScene->v_gameObjects[i]->getComponent<CameraComponent>();
			//m_inputHandler->v_objectsRequiringInput.push_back(m_currentScene->v_gameObjects[i]);
		}
		else if (type == "StaticEnvironmentObject")
		{
			m_currentScene->v_gameObjects.push_back(new StaticEnvironmentObject());
		}
		else
		{
			std::cout << type << ": unknown type\n";
			continue; // not an object we can create
		}

		std::cout << gameObjects[i]["name"].asString() << "-" << type << " loaded\n";

	}

	return true;
}

