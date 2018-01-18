#include "ModelManager.h"
#include "iostream"
#include "Model.h"



ModelManager::ModelManager()
{

}

bool ModelManager::load_model(const std::string file_path)
{
	it = load_models.find(file_path);
	if (it != load_models.end())
	{
		std::cout << "Already in map " << file_path << '\n';
		return true;
	}
	load_models[file_path] = load_path + file_path;
	std::cout << "Not Found, Adding!!  " << file_path << ":" << load_path + file_path << '\n';
	return false;
}

Model* ModelManager::get_model(const std::string model_name)
{
	try
	{
		if (load_models.find(model_name) != load_models.end())
		{
			std::cout << "Found Model  " << model_name << '\n';
		
		}
	}
	catch (const char e)
	{
		std::cout << " exception occured, Model with name  " << model_name <<" is not loaded " << endl << e;
	}

	return new Model(load_models.at(model_name));
}
