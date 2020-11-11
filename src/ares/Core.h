#include <SDL2/SDL.h>
#include <rend/rend.h>

#include <memory>
#include <vector>

namespace ares
{
	struct Renderer;
	struct Entity;
	struct Screen;


	struct Core
	{
		friend struct myengine::Renderer;

		static std::shared_ptr<Core> initialize(); // Static - To initialize the core only once

		std::shared_ptr<Entity> addEntity(); // To create an entity and add it to the list

		void start();

	private:

		std::vector<std::shared_ptr<Entity>> entities; // A list of entities
		std::weak_ptr<Core> self; // so that components could access core

		//Graphics
		SDL_Window* window; // The SDL window
		SDL_GLContext glContext;
		std::shared_ptr<rend::Context> context;

	};

}
