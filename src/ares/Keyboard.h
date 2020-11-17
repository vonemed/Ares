#include <vector>

namespace ares
{
	struct Core; // forward declaration

	struct Keyboard
	{
		bool getKey(int key);

	private:
		//variables should always be private
		friend struct ares::Core; // so the core could add it directly
		std::vector<int> keys; // A vector to store all keys
	};
}