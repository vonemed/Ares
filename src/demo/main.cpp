#include <ares/ares.h>

#include <iostream>

struct Player : public Component
{
	void onInitialize()
	{

	}

	void onTick()
	{
		//Keyboard event

		//Moving forward
		if (getCore()->getKeyboard()->getKey('w'))
		{
			getTransform()->translate(0, 0, -0.1f);
		}

		//Moving back
		if (getCore()->getKeyboard()->getKey('s'))
		{
			getTransform()->translate(0, 0, 0.1f);
		}

		//Rotate right
		if (getCore()->getKeyboard()->getKey('a'))
		{
			getTransform()->rotate(0, 0.1f, 0);
		}

		//Rotate left
		if (getCore()->getKeyboard()->getKey('d'))
		{
			getTransform()->rotate(0, -0.1f, 0);
		}
	}
};


int main()
{
  std::shared_ptr<Core> core = Core::initialize();

  std::shared_ptr<Entity> coreEntity = core->addEntity();
  std::shared_ptr<Renderer> rendererComponent = coreEntity->addComponent<Renderer>();
  std::shared_ptr<Player> playerComponent = coreEntity->addComponent<Player>();

  std::shared_ptr<Entity> cameraEntity = core->addEntity();
  std::shared_ptr<Camera> cameraComponent = cameraEntity->addComponent<Camera>();
  cameraEntity->getTransform()->setPosition(glm::vec3(0, 0, 10));

  core->start();

  return 0;
}
