#include "Keyboard.h"

namespace ares
{
	bool Keyboard::getKey(int _key)
	{
		for (size_t ki = 0; ki < keys.size(); ki++)
		{
			if (keys.at(ki) == _key) // If the pressed key is inside the list, return true
			{
				return true;
			}
		}

		return false; // Else return false
	}
}