#include "graphics.h"
#include "libft.h"

int	time_to_dance(void)
{
	sfText	*mytext;
	sfFont	*myfont;

	ft_print("Now, it is time... To DAAAAAAAANCE!!!\n");
	if (!(mytext = sfText_create()))
		return (0);
	if (!(myfont = sfFont_createFromFile("font/alloCharlie.ttf")))
		return (0);
	sfText_setString(mytext, "Now, it is time... To DAAAAAAAANCE!!!");
	sfText_setCharacterSize(mytext, 110);
	sfText_setColor(mytext, sfYellow);
	sfText_setFont(mytext, myfont);
	sfRenderWindow_clear(g_graphic.window, sfRed);
	sfRenderWindow_drawText(g_graphic.window, mytext, NULL);
	sfRenderWindow_display(g_graphic.window);
	sfFont_destroy(myfont);	
	sfText_destroy(mytext);
	return (1);
}