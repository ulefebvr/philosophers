#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "SDL.h"

typedef struct		s_graphic
{
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Window		*window;
}					t_graphic;

extern t_graphic	g_graphic;

SDL_Window			*graphic_create_windows(void);
void				graphic_destroy_windows(void);

int					graphic_init(void);

#endif
