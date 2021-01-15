#include "Camera.h"
#include "Transform.h"
#include "Entity.h"
#include "Core.h"

namespace ares
{
	void Camera::onInitialize()
	{
		std::shared_ptr<Camera> cam = getEntity()->getComponent<Camera>();
		getCore()->camera = cam;
	}

	// Returning the view matrix
	glm::mat4 Camera::getView()
	{
		// Inverse the model matrix of camera and return it
		glm::mat4 rtn = glm::inverse(getTransform()->getModel()); 

		return rtn;
	}
}