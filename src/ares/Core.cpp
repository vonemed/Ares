#include "Core.h"

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
}