#include <ares/Core.h>
#include <iostream>

#define WINDOW_WIDTH 640;
#define WINDOW_HEIGHT 480;

using namespace ares;

int main()
{
	std::cout << "Hello World" << std::endl;
	
	std::shared_ptr<Core> core = Core::initialize();

	core->initialize();

	return 0;
}