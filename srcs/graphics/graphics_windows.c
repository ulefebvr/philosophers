#include "SDL.h"

SDL_Window			*graphic_create_windows(void)
{
	SDL_Window*		pWindow;

	pWindow = NULL;
	if ((SDL_Init(SDL_INIT_VIDEO)) != 0)
		return (0);
	pWindow = SDL_CreateWindow(
		"Philosophers",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480, SDL_WINDOW_SHOWN
	);
	if (pWindow == 0)
		return (0);
	return (pWindow);
}
