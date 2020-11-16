#ifndef ARES_COMPONENT_H // If not defined by compiler
#define ARES_COMPONENT_H

#include <memory>

namespace ares
{
	struct Entity;
	struct Core;

	struct Component
	{
		friend struct ares::Entity;

		virtual void onInitialize();

		void tick();
		virtual void onTick();

		void render();
		virtual void onRender();

		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();

	private:
		std::weak_ptr<Entity> entity;
	};
}

#endif