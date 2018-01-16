#pragma once
#include "Components.h"
#include "Definitions.h"
#include "Model.h"



class ModelComponent : public Components
{

public:
	Model* themodel;
	void OnUpdate(float dt) override {}
	void OnMessage(const std::string m) override {}
};

