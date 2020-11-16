#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Exception.h"

namespace ares
{
    
    // Initializing the core
    std::shared_ptr<Core> Core::initialize()
    {
        std::shared_ptr<Core> rtn = std::make_shared<Core>(); // Creating it and reserving memory on the heap
        rtn->self = rtn; // A weak pointer to itself

        rtn->window = SDL_CreateWindow("myengine",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            800, 600,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

        if (!rtn->window)
        {
            throw Exception("Failed to create window");
        }

        rtn->glContext = SDL_GL_CreateContext(rtn->window);

        if (!rtn->glContext)
        {
            throw Exception("Failed to create OpenGL context");
        }

        rtn->context = rend::Context::initialize();

        return rtn;
    }

    //Just creating an entity and then adding it to the list of entities to keep track of
    std::shared_ptr<Entity> Core::addEntity() // Returns an Entity type, and accessed by core class
    {
        std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
        rtn->addComponent<Transform>();
        rtn->core = self;
        rtn->self = rtn;

        entities.push_back(rtn);

        return rtn;
    }

    // Starts the game loop
    void Core::start()
    {
        bool running = true;
        SDL_Event e = { 0 };

        while (running)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    running = false;
                }
            }

            for (size_t ei = 0; ei < entities.size(); ei++) // activating entities
            {
                entities.at(ei)->tick();
            }

            glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            for (size_t ei = 0; ei < entities.size(); ei++) // rendering entities
            {
                entities.at(ei)->render();
            }

            SDL_GL_SwapWindow(window);
        }
    }


}

