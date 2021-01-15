#include "Transform.h"


namespace ares
{
	void Transform::onInitialize()
	{
		// Setting default parameters of model
		scale = glm::vec3(1, 1, 1);
		position = glm::vec3(0, -5, -20);
		rotation = glm::vec3(0, 0, 0);
	}

	void Transform::setPosition(glm::vec3 _position)
	{
		this->position = _position;
	}

	void Transform::setRotation(glm::vec3 _rotation)
	{
		this->rotation = _rotation;
	}

	glm::mat4 Transform::getModel()
	{
		glm::mat4 rtn(1.0f); // Identity matrix
		rtn = glm::translate(rtn, position);
		rtn = glm::rotate(rtn, rotation.x, glm::vec3(1, 0, 0));
		rtn = glm::rotate(rtn, rotation.y, glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, rotation.z, glm::vec3(0, 0, 1));
		rtn = glm::scale(rtn, scale);

		return rtn;
	}

	void Transform::translate(float _x, float _y, float _z)
	{
		//Moves the object relative to their respective rotation
		glm::mat4 rtn = getModel(); 

		glm::vec4 fwd = rtn * glm::vec4(_x, _y, _z, 0);

		position += rend::vec3(fwd);
	}

	void Transform::rotate(float _x, float _y, float _z)
	{
		//Rotates the object
		glm::mat4 rtn = getModel();

		glm::vec4 fwd = rtn * glm::vec4(_x, _y, _z, 0);

		rotation += rend::vec3(fwd);
	}
}