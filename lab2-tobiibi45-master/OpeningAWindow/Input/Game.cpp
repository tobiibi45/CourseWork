#include "Game.h"
#include "TransformComponent.h"
#include "ColourComponent.h"
#include <fstream>
#include <sstream>
#include "json.h"

Game::Game()
{

	//loadLevel("assets/levels/myCubeLevel.txt");
	loadLevelJSON("assets/levels/myCubeLevel.json");

	m_currentScene->m_playerBackground.addComponent(new RedComponent);
	m_currentScene->m_playerBackground.addComponent(new GreenComponent);
	m_currentScene->m_playerBackground.addComponent(new BlueComponent);
	m_currentScene->m_playerCube.addComponent(new TransformComponent);
	m_currentScene->m_playerCube.addComponent(new playerCamera);


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
	// perform all the logic for your game world
	if (m_currentScene)
		m_currentScene->render(m_engineInterfacePtr);
}


bool Game::loadLevelJSON(std::string levelJSONFile)
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


void Game::loadLevel(std::string levelFile)
{
	if (m_currentScene)
	{
		m_currentScene->cleanup();
		delete m_currentScene;
	}

	m_currentScene = new Scene;

	// create an input filestream
	std::ifstream myInputFile;
	std::string s;
	std::stringstream ss;
	int numCubesToRead;

	myInputFile.open(levelFile, std::ios_base::in);
	if (myInputFile.is_open())
	{
		// read the first line which has the number of elements
		std::getline(myInputFile, s);
		ss.str(s);
		ss.ignore(17); // ignore the first 17 chars
		ss >> numCubesToRead;

		// resize the correct size for the vector
		m_currentScene->v_gameObjects.resize(numCubesToRead);
		ss.clear();

		for (int i = 0; i < numCubesToRead; i++)
		{
			// use a stringstream to get integer values
			float x, y, z, w;

			//first line just says the cubenumber
			getline(myInputFile, s);

			// read in position
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> x >> y >> z;
			glm::vec3 pos(x, y, z);

			// read in orientation
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> w >> x >> y >> z;
			glm::quat orient(w, x, y, z);

			// read in scale
			getline(myInputFile, s);
			ss.clear();
			ss.str(s);
			ss >> x >> y >> z;
			glm::vec3 scale(x, y, z);

			m_currentScene->v_gameObjects[i]->addComponent(new TransformComponent(pos, orient, scale));

		}
	}
	else
	{
		std::cout << "Unable to open level file!\n";
	}
}