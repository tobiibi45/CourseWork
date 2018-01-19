#pragma once
#include "FirstGame.h"
#include <fstream>
#include <sstream>
#include <json.h>
#include "PlayerCharacter.h"
#include <GameObject.h>
#include "MyGameObjects.h"
#include <InputHandler.h>

FirstGame::FirstGame() : scene_change(SceneChange::firstScene)
{
	loadLevelJSON("assets/levels/level1.json");
	m_engineInterfacePtr = nullptr;

}

void FirstGame::update(float dt)
{
	
	player.OnUpdate(dt);
	/*switch (scene_change)
	{
		case SceneChange::firstScene:
		{
			loadLevelJSON("assets/levels/level1.json");
			break;
		}
		case SceneChange::SecondScene:
		{
			loadLevelJSON("assets/levels/level2.json");
			break;
		}
		case SceneChange::ThirdScene:
		{
			loadLevelJSON("assets/levels/level3.json");
			break;
		}
	}*/

}

void FirstGame::render()
{
	// perform all the logic for your game world
	if (m_currentscene)
		m_currentscene->render(m_engineInterfacePtr);
}

bool FirstGame::loadLevelJSON(std::string levelJSONFile)
{
	

	if (m_currentscene)
	{
		m_currentscene->cleanup();
		delete m_currentscene;
	}

	m_currentscene = new GameScene();
	m_inputHandler = new InputHandler();

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

		string type = gameObjects[i]["type"].asString();

		if (type == "PlayerCharacter")
		{
			if (name == "duck")
			{
				m_currentscene->v_gameObjects.push_back(new PlayerCharacter());
				m_currentscene->v_gameObjects[i]->addComponent(new CameraComponent);
				//m_currentscene->m_camera = m_currentscene->v_gameObjects[i]->getComponent<CameraComponent>();
				trans = m_currentscene->v_gameObjects[i]->getComponent<TransformComponent>();
				m_inputHandler->addObjects(m_currentscene->v_gameObjects[i]);
				ModelComponent* duck = m_currentscene->v_gameObjects[i]->getComponent<ModelComponent>();
				mm.load_model("duck.dae");
				duck->themodel = (mm.get_model("duck.dae"));
			}
			else if (name == "deer")
			{
				m_currentscene->v_gameObjects.push_back(new PlayerCharacter());
			//	m_currentscene->m_camera = m_currentscene->v_gameObjects[i]->getComponent<CameraComponent>();
				m_inputHandler->addObjects(m_currentscene->v_gameObjects[i]);
				ModelComponent* deer = m_currentscene->v_gameObjects[i]->getComponent<ModelComponent>();
				mm.load_model("bigdeer.obj");
				deer->themodel = (mm.get_model("bigdeer.obj"));
			}
			
		}
		else if (type == "StaticEnvironmentObject")
		{
			if (name == "floor")
			{
				m_currentscene->v_gameObjects.push_back(new StaticEnvironmentObject());
				ModelComponent* floor = m_currentscene->v_gameObjects[i]->getComponent<ModelComponent>();
				mm.load_model("floor.dae");
				floor->themodel = (mm.get_model("floor.dae"));
			}
			else if (name == "grass")
			{
				m_currentscene->v_gameObjects.push_back(new StaticEnvironmentObject());
				ModelComponent* grass = m_currentscene->v_gameObjects[i]->getComponent<ModelComponent>();
				mm.load_model("grass.obj");
				grass->themodel = (mm.get_model("grass.obj"));
			}
			else if (name == "tree")
			{
				m_currentscene->v_gameObjects.push_back(new StaticEnvironmentObject());
				ModelComponent* tree = m_currentscene->v_gameObjects[i]->getComponent<ModelComponent>();
				mm.load_model("tree.obj");
				tree->themodel = (mm.get_model("tree.obj"));
			}
			else if (name == "rock")
			{
				m_currentscene->v_gameObjects.push_back(new StaticEnvironmentObject());
				ModelComponent* rock = m_currentscene->v_gameObjects[i]->getComponent<ModelComponent>();
				mm.load_model("rock.obj");
				rock->themodel = (mm.get_model("rock.obj"));
			}
		}
		else if (type == "DynamicEnvironmentObject")
		{
			if (name == "ball")
			{
				m_currentscene->v_gameObjects.push_back(new DynamicEnvironmentObject());
				ModelComponent* ball = m_currentscene->v_gameObjects[i]->getComponent<ModelComponent>();
				mm.load_model("ball.obj");
				ball->themodel = (mm.get_model("ball.obj"));
			}
		}
		else
		{
			std::cout << type << ": unknown type\n";
			continue; // not an object we can create
		}

		//m_currentscene->v_gameObjects[i]->addComponent(new TransformComponent(pos, orient, scale));

		std::cout << gameObjects[i]["name"].asString() << "-" << type << " loaded\n";

	}

	return true;
}

