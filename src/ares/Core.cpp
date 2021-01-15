#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Transform.h"
#include "Keyboard.h"

#include <iostream>

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

  if(!rtn->window)
  {
    throw Exception("Failed to create window");
  }

  rtn->glContext = SDL_GL_CreateContext(rtn->window);

  if(!rtn->glContext)
  {
    throw Exception("Failed to create OpenGL context");
  }

  rtn->context = rend::Context::initialize();
  rtn->keyboard = std::make_shared <Keyboard>();

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

std::shared_ptr<Keyboard> Core::getKeyboard()
{
    return keyboard;
}

std::shared_ptr<Camera> Core::getCamera()
{
    return camera.lock();
}

// Starts the game loop
void Core::start() 
{
  bool running = true;
  SDL_Event e = {0};

  while(running)
  {
    while(SDL_PollEvent(&e) != 0)
    {
      if(e.type == SDL_QUIT)
      {
        running = false;
      }
      else if (e.type == SDL_KEYDOWN)
      {
          keyboard->keys.push_back(e.key.keysym.sym); // Adding keys to the list
          std::cout << "Key pressed" << std::endl;
          keyboard->downKeys.push_back(e.key.keysym.sym);
      }
      else if (e.type == SDL_KEYUP)
      { // Removes keys from the list once they have been released
          keyboard->upKeys.push_back(e.key.keysym.sym);
          for (std::vector<int>::iterator it = keyboard->keys.begin();
              it != keyboard->keys.end();)
          {
              if (*it == e.key.keysym.sym) it = keyboard->keys.erase(it);
              else it++;
          }
      }
    }

    for(size_t ei = 0; ei < entities.size(); ei++) // Activating entities
    {
      entities.at(ei)->tick();
    }

    glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(size_t ei = 0; ei < entities.size(); ei++) // Rendering entities
    {
      entities.at(ei)->render();
    }

    SDL_GL_SwapWindow(window);
    keyboard->downKeys.clear();
    keyboard->upKeys.clear();
  }
}


}

