#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "SDL.h"
# include "philosophers.h"

typedef struct		s_graphic
{
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Window		*window;
	SDL_mutex		*mutex;
}					t_graphic;

extern t_graphic	g_graphic;

SDL_Window			*graphic_create_windows(void);
int					graphic_init(void);
int					graphic_put_state(t_philo *philo);

#endif
