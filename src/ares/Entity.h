#include <memory>
#include <vector>

namespace ares
{
	struct Component;
	struct Entity
	{
		std::vector<std::shared_ptr<Component>> component;
	};
}