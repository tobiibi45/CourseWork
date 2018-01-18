#pragma once
#include "Components.h"
#include "Model.h"



class ModelComponent : public Components
{

public:
	
	void OnUpdate(float dt) override {}
	void OnMessage(const std::string m) override {}
	Model* themodel;
};

