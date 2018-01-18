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
	load_models[file_path] = Model(load_path + file_path);
	std::cout << "Not Found, Adding!!  " << file_path << '\n';
	return false;
}

Model ModelManager::get_model(const std::string name)
{
	Model* model;
	try
	{

		if (load_models.find(name) != load_models.end())
		{
			load_model(name);
			auto model = new Model(name);
		}
		throw "Model not Found";
	}
	catch (const char e)
	{
		std::cout << " exception occured, Model with name  " << name <<" is not loaded " << endl << e;
	}

	return load_models.at(load_path + name);
}
