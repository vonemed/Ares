#include "Core.h"
#include "Entity.h"

namespace ares
{
	std::shared_ptr<Core> Core::initialize()
	{
		//std::shared_ptr<Core> rtn = std::make_shared<Core>();
		std::shared_ptr<Core> rtn (new Core());
		return rtn;
	}

	Core::Core() {}

	void Core::Start()
	{
		//Todo
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared <Entity>();

		entities.push_back(rtn);

		return rtn;
	}
}