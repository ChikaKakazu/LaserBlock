#include "Component.h"
#include "Actor.h"

Component::Component(Actor* owner, int updateOrder) : owner(owner), updateOrder(updateOrder)
{

}

Component::~Component()
{

}

void Component::Update()
{

}