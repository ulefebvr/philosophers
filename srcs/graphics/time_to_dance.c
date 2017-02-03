/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_dance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:53:23 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/03 12:53:24 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "libft.h"

int	time_to_dance(void)
{
	sfText	*mytext;
	sfFont	*myfont;

	ft_print("Now, it is time... To DAAAAAAAANCE!!!\n");
	if (g_option.no_graphic)
		return (1);
	if (!(mytext = sfText_create()))
		return (0);
	if (!(myfont = sfFont_createFromFile("ressources/font/alloCharlie.ttf")))
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
