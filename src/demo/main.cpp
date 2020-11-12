#include <ares/ares.h>
#include <iostream>

using namespace ares;

int main()
{
	// Initialization of engine
	std::shared_ptr<Core> core = Core::initialize();

	// Creating a single in-game object
	std::shared_ptr<Entity> pe = core->addEntity();

	// Add a component 
	std::shared_ptr<Component> pc = pe->addComponent<Component>();

	core->Start();

	const GLfloat positions[] = {
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	return 0;
}