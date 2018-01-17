#include "ModelManager.h"



ModelManager::ModelManager()
{


}

bool ModelManager::addModel(const std::string filePath)
{
	if (loadModels.find(filePath) == loadModels.end())
	{
		return false;
	}
	else
	{
		loadModels[filePath] = Model(loadPath + filePath);
	}

}

Model ModelManager::getModel(const std::string name)
{
	//Model* model;


	return loadModels.at(loadPath + name);

}


ModelManager::~ModelManager()
{

}

