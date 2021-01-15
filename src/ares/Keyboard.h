#include <vector>

//To convert keys between platforms
#ifdef USE_SDL	
#define KEY_A 'a'
#else
#define KEY_A 223
#endif

namespace ares
{
	struct Core; 

	struct Keyboard
	{
		bool getKey(int key);
	
	private:

		friend struct ares::Core; 
		std::vector<int> keys; // A vector to store all keys
		std::vector<int> downKeys; // To store all pressed keys
		std::vector<int> upKeys; // To store all up keys
	};
}