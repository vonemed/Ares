#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace ares
{

void Entity::tick()
{
  for(size_t ci = 0; ci < components.size(); ci++) // Activating components
  {
    components.at(ci)->tick();
  }
}

void Entity::render()
{
  for(size_t ci = 0; ci < components.size(); ci++) // Rendering components
  {
    components.at(ci)->render();
  }
}

std::shared_ptr<Core> Entity::getCore() // To access the core
{
  return core.lock(); // Returning a shared pointer
}

std::shared_ptr<Transform> Entity::getTransform() // To access the transform
{
    return getComponent<Transform>();
}

}

