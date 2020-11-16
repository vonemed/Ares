#include "Transform.h"


namespace myengine
{
	void Transform::onInitialize()
	{
		scale = glm::vec3(1, 1, 1);
	}

	void Transform::setPosition(glm::vec3 _position)
	{
		position = _position;
	}

	void Transform::setRotation(glm::vec3 _rotation)
	{
		rotation = _rotation;
	}

	glm::mat4 Transform::getModel()
	{
		glm::mat4 rtn(1.0f); // Identity matrix
		rtn = glm::translate(rtn, position);
		rtn = glm::rotate(rtn, rotation.x, glm::vec3(1, 0, 1));
		rtn = glm::rotate(rtn, rotation.y, glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, rotation.z, glm::vec3(0, 0, 1));
		rtn = glm::scale(rtn, scale);

		return rtn;
	}
}