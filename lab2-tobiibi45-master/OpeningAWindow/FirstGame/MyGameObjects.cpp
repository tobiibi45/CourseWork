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
