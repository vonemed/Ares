#include <ares/Core.h>
#include <iostream>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 640;
#define WINDOW_HEIGHT 480;

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // If initialization of SDL failed throw an exception
	{
		throw std::exception();
	}

	SDL_Window* window = NULL; //null pointer, so later it can be assigned any pointer

	SDL_Surface* screenSurface = NULL; //a 2D image displayed inside the window

	// Create window(
	window = SDL_CreateWindow("DEMO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	screenSurface = SDL_GetWindowSurface(window); // getting window surface so we can draw on it

	//Fill the surface white	
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Wait for 2 seconds
	SDL_Delay(2000);

	std::cout << "Hello World" << std::endl;
	
	Core core;
	core.dummy();
	
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}