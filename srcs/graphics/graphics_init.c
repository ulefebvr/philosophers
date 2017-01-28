#include "graphics.h"

int				graphic_init(void)
{
	SDL_Surface* sprite;

	if (!(g_graphic.window = graphic_create_windows()))
		return (0);
	if (!(g_graphic.renderer = SDL_CreateRenderer(g_graphic.window, -1,
		SDL_RENDERER_ACCELERATED)))
		return (0);
	if (!(sprite = SDL_LoadBMP("./img/frame_philo_plus.bmp")))
		return (0);
	if (!(g_graphic.texture = SDL_CreateTextureFromSurface(g_graphic.renderer,
		sprite)))
	{
		SDL_FreeSurface(sprite);
		return (0);
	}
	SDL_FreeSurface(sprite);
	return (1);
}
