#include <SDL2/SDL.h>
#include <rend/rend.h>

#include <memory>
#include <vector>

namespace ares
{

struct Renderer;
struct Entity;
struct Screen;
struct Keyboard;
struct Camera;

struct Core
{
  friend struct ares::Renderer;
  friend struct ares::Camera;

  static std::shared_ptr<Core> initialize(); // Static - To initialize the core only once

  std::shared_ptr<Entity> addEntity(); // To create an entity and add it to the list
  std::shared_ptr<Keyboard> getKeyboard(); // To access the keyboard values
  std::shared_ptr<Camera> getCamera(); // TO access main camera

  void start(); 

private:

  std::vector<std::shared_ptr<Entity>> entities; // A list of entities
  std::weak_ptr<Core> self; // So that components could access core

  //Graphics
  SDL_Window* window; 
  SDL_GLContext glContext; 
  std::shared_ptr<rend::Context> context;
  std::shared_ptr<Keyboard> keyboard; 
  std::weak_ptr<Camera> camera;
};

}
