#include <memory>
#include <vector>

namespace ares
{
	struct Entity;
	struct Core
	{
		static std::shared_ptr<Core> initialize();

		void Start();

	private:
		Core();
		std::vector<std::shared_ptr<Entity>> entities;
	};
}