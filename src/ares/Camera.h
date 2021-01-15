#include "Component.h"

#include <rend/rend.h>

namespace ares
{
	struct Camera : public Component
	{
		void onInitialize();

		glm::mat4 getView();
	};
}