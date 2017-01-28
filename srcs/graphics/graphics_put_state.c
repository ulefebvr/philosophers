#include "philosophers.h"
#include "graphics.h"

static int	get_x_state(t_state state)
{
	if (state == THINK)
		return (866);
	else if (state == EAT)
		return (1299);
	else if (state == REST)
		return (433);
	else
		return (0);
}

int			graphic_put_state(t_philo *philo)
{
	SDL_Rect src;
	SDL_Rect dst;

	src.x = get_x_state(philo->state);
	src.y = 0;
	src.w = 433;
	src.h = 650;
	dst.x = (philo->number - 1) * 185;
	dst.y = 0;
	dst.w = 185;
	dst.h = 278;
	SDL_LockMutex(g_graphic.mutex);
	SDL_RenderCopy(g_graphic.renderer, g_graphic.texture, &src, &dst);
	SDL_RenderPresent(g_graphic.renderer);
	SDL_UnlockMutex(g_graphic.mutex);
	return (1);
}
