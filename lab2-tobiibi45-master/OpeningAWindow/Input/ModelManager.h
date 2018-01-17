#pragma once
#include "Model.h"
#include <map>
class ModelManager 
{
public:

	ModelManager();
	~ModelManager();
	bool addModel(const std::string filePath);
	Model getModel(const std::string name);

	std::string loadPath = "assets/models";
	std::map<string, Model> loadModels;
};

