#pragma once
#include "Model.h"
#include <map>
class ModelManager 
{
public:

	/**
	 * \brief 
	 */
	ModelManager();

	bool load_model(const std::string file_path);
	Model get_model(const std::string name);

	std::string load_path = "assets/models/";
	std::map<string, Model> load_models;
	std::map<string, Model>::iterator it;
};

