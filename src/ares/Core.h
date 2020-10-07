#include <memory>

namespace ares
{
	struct Core
	{
		static std::shared_ptr<Core> initialize();

		void Start();

	private:
		Core();
	};
}