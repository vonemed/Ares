#include "Component.h"
#include <vector>

#include <rend/rend.h>

namespace myengine
{
	struct Transform : public Component
	{
		void onInitialize(); // To set scale to 1,1,1 by default
		glm::mat4 getModel();

		void setPosition(glm::vec3 _position);
		void setRotation(glm::vec3 _rotation);
		void setScale();


	private:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};
}