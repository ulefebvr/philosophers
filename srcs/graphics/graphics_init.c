/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:23:28 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:23:29 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errors.h"
#include "graphics.h"

int			graphic_init_philo(t_philo *philo)
{
	int			i;
	int			count;
	sfSprite	*tmp;

	count = NUMBER_PHILOS;
	while (count-- > 0)
	{
		i = -1;
		while (++i < 4)
		{
			philo->sprites[i] = sfSprite_create();
			tmp = philo->sprites[i];
			if (tmp == 0)
			{
				ft_fdprint(2, ERR_SPRITES_INIT);
				return (0);
			}
			sfSprite_setTexture(tmp, g_graphic.texture, sfTrue);
			sfSprite_setScale(tmp, (sfVector2f){0.42758, 0.4255});
			sfSprite_setPosition(tmp, (sfVector2f){185 * philo->number, 0});
			sfSprite_setTextureRect(tmp, (sfIntRect){433 * i, 0, 433, 650});
		}
		philo = philo->next;
	}
	return (1);
}

int				graphic_init(void)
{
	g_graphic.window = sfRenderWindow_create(
		(sfVideoMode){1296, 277, 32}, "Philosophers",
		sfResize | sfClose, NULL);
	if (!g_graphic.window)
	{
		ft_fdprint(2, ERR_WINDOW_INIT);
		return (0);
	}
	g_graphic.texture = sfTexture_createFromFile(
		"img/frame_philo_plus.jpg", &(sfIntRect){0, 0, 0, 650});
	if (!g_graphic.texture)
	{
		sfRenderWindow_destroy(g_graphic.window);
		ft_fdprint(2, ERR_TEXTURE_INIT);
		return (0);
	}
	if (pthread_mutex_init(&g_graphic.mutex, 0))
	{
		sfTexture_destroy(g_graphic.texture);
		sfRenderWindow_destroy(g_graphic.window);
		ft_fdprint(2, ERR_MUTEX_INIT);
		return (0);
	}
	return (1);
}
