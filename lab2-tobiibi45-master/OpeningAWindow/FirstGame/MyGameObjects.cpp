#include "MyGameObjects.h"

StaticEnvironmentObject::StaticEnvironmentObject()
{
	addComponent(new TransformComponent);
	addComponent(new ModelComponent);
}

void StaticEnvironmentObject::OnUpdate(float dt)
{

}

void StaticEnvironmentObject::OnMessage(const std::string msg)
{

}

StaticEnvironmentObject::~StaticEnvironmentObject()
{
}

DynamicEnvironmentObject::DynamicEnvironmentObject()
{
	addComponent(new TransformComponent);
	addComponent(new ModelComponent);
}

DynamicEnvironmentObject::~DynamicEnvironmentObject()
{
}

void DynamicEnvironmentObject::OnUpdate(float dt)
{
}

void DynamicEnvironmentObject::OnMessage(const std::string msg)
{
}
