#include "SDL.h"
#include "graphics.h"

SDL_Window			*graphic_create_windows(void)
{
	SDL_Window*		pWindow;

	pWindow = NULL;
	if ((SDL_Init(SDL_INIT_VIDEO)) != 0)
		return (0);
	pWindow = SDL_CreateWindow(
		"Philosophers",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1296, 277, SDL_WINDOW_SHOWN
	);
	if (pWindow == 0)
		return (0);
	return (pWindow);
}

void				graphic_destroy_windows(void)
{
	SDL_Event		event;

	SDL_DestroyRenderer(g_graphic.renderer);
	SDL_DestroyTexture(g_graphic.texture);
	while (SDL_WaitEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
			break ;
	}
	SDL_DestroyWindow(g_graphic.window);
	SDL_Quit();
}
