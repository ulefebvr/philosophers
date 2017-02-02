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

#include "graphics.h"

t_philo			*graphic_init_philo(t_philo *philo)
{
	int		i;
	int		count;

	count = NUMBER_PHILOS;
	while (count-- > 0)
	{
		i = -1;
		while (++i < 4)
		{
			philo->sprites[i] = sfSprite_create();
			sfSprite_setTexture(
				philo->sprites[i], g_graphic.texture, sfTrue);
			sfSprite_setScale(
				philo->sprites[i], (sfVector2f){0.42758, 0.4255});
			sfSprite_setPosition(
				philo->sprites[i], (sfVector2f){185 * philo->number, 0});
			sfSprite_setTextureRect(
				philo->sprites[i], (sfIntRect){433 * i, 0, 433, 650});
		}
		philo = philo->next;
	}
	return (philo);
}

int				graphic_init(void)
{
	g_graphic.window = sfRenderWindow_create(
		(sfVideoMode){1296, 277, 32}, "SFML window", sfResize | sfClose, NULL);
	g_graphic.texture = sfTexture_createFromFile(
		"img/frame_philo_plus.jpg", &(sfIntRect){0, 0, 0, 650});
	return (g_graphic.window && g_graphic.texture
		&& !pthread_mutex_init(&g_graphic.mutex, 0));
}
