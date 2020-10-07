#include <ares/ares.h>
#include <iostream>

using namespace ares;

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> pe = core->addEntity();
	//std::shared_ptr<Component> pc = pe->addComponent<Component>();

	core->initialize();

	return 0;
}