#pragma once
#include "FirstGame.h"
#include <fstream>
#include <sstream>
#include <json.h>

FirstGame::FirstGame()
{

}

void FirstGame::update(float dt)
{

}

void FirstGame::render()
{

}

bool loadLevelJSON(std::string levelJSONFile)
{
	if (m_currentScene)
	{
		m_currentScene->cleanup();
		delete m_currentScene;
	}

	m_currentScene = new Scene;

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

	// resize our vector of cubes
	//m_currentScene->v_gameObjects.resize(gameObjects.size());

	for (int i = 0; i < gameObjects.size(); i++)
	{
		m_currentScene->v_gameObjects.push_back(new GameObject);

		std::cout << gameObjects[i]["name"].asString() << " loaded\n";

		float w, x, y, z;
		// has to have a position node
		const Json::Value posNode = gameObjects[i]["position"];
		x = posNode[0].asFloat();
		y = posNode[1].asFloat();
		z = posNode[2].asFloat();

		glm::vec3 pos(x, y, z);

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

	}

	return true;
}

