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

static int	graphic_init_philo_life(t_philo *philo)
{
	if (!(philo->graphic_life[0] = sfRectangleShape_create())
		|| !(philo->graphic_life[1] = sfRectangleShape_create()))
		return (0);
	sfRectangleShape_setSize(philo->graphic_life[0], (sfVector2f){145, 20});
	sfRectangleShape_setPosition(
		philo->graphic_life[0], (sfVector2f){20 + (185 * philo->number), 247});
	sfRectangleShape_setFillColor(philo->graphic_life[0], sfWhite);
	sfRectangleShape_setOutlineThickness(philo->graphic_life[0], 2);
	sfRectangleShape_setOutlineColor(philo->graphic_life[0], sfWhite);
	sfRectangleShape_setPosition(
		philo->graphic_life[1], (sfVector2f){20 + (185 * philo->number), 247});
	return (1);
}

int			graphic_init_philo(t_philo *philo)
{
	int			i;
	int			count;
	sfSprite	*tmp;

	count = 7;
	while (count-- > 0)
	{
		i = -1;
		while (++i < 4)
		{
			philo->sprites[i] = sfSprite_create();
			if (!(tmp = philo->sprites[i]))
				return (!ft_fdprint(2, ERR_SPRITES_INIT));
			sfSprite_setTexture(tmp, g_graphic.texture, sfTrue);
			sfSprite_setScale(tmp, (sfVector2f){0.42758, 0.4255});
			sfSprite_setPosition(tmp, (sfVector2f){185 * philo->number, 0});
			sfSprite_setTextureRect(tmp, (sfIntRect){433 * i, 0, 433, 650});
		}
		if (!graphic_init_philo_life(philo))
			return (0);
		philo = philo->next;
	}
	return (1);
}

int			graphic_init_texture(void)
{
	if (g_option.spritenbr == 0)
		g_graphic.texture = sfTexture_createFromFile(
			"ressources/img/frame_philo_plus.jpg",
			&(sfIntRect){0, 0, 0, 650});
	if (g_option.spritenbr == 1)
		g_graphic.texture = sfTexture_createFromFile(
			"ressources/img/frame_nyangoroge.jpg",
			&(sfIntRect){0, 0, 0, 650});
	if (g_option.spritenbr == 2)
		g_graphic.texture = sfTexture_createFromFile(
			"ressources/img/frame_panpaka.jpg",
			&(sfIntRect){0, 0, 0, 650});
	if (g_option.spritenbr == 3)
		g_graphic.texture = sfTexture_createFromFile(
			"ressources/img/frame_coco.jpg",
			&(sfIntRect){0, 0, 0, 650});
	return (g_graphic.texture ? 1 : 0);
}

int			graphic_init(void)
{
	g_graphic.window = sfRenderWindow_create(
		(sfVideoMode){1295, 276, 32}, "Philosophers", sfClose, NULL);
	if (!g_graphic.window)
	{
		ft_fdprint(2, ERR_WINDOW_INIT);
		return (0);
	}
	if (!graphic_init_texture())
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
	if (!(g_graphic.music = sfMusic_createFromFile(
		"ressources/music/philo_music.ogg")))
		return (0);
	sfMusic_setLoop(g_graphic.music, sfTrue);
	return (1);
}
