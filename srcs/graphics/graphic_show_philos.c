/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_put_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:57:29 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/03 11:57:31 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "graphics.h"
#include "libft.h"

static void	console_put_state(t_philo *philo)
{
	ft_print("Philo number: %d", philo->number);
	if (philo->state == REST)
		ft_print(", state: REST,  life: %d\n", philo->life);
	else if (philo->state == THINK)
		ft_print(", state: THINK, life: %d\n", philo->life);
	else if (philo->state == EAT)
		ft_print(", state: EAT,   life: %d\n", philo->life);
	else if (philo->state == DEAD)
		ft_print(", state: DEAD,  life: %d\n", philo->life);
}

static int	graphic_put_life(t_philo *philo)
{
	sfColor	color;
	int		life;


	life = MAX_LIFE ? (philo->life * 145) / MAX_LIFE : 0;
	if (life <= 50)
		color = sfRed;
	else if (life < 100)
		color = sfYellow;
	else
		color = sfGreen;
	sfRenderWindow_drawRectangleShape(
		g_graphic.window, philo->graphic_life[0], NULL);
	sfRectangleShape_setSize(philo->graphic_life[1], (sfVector2f){life, 20});
	sfRectangleShape_setFillColor(philo->graphic_life[1], color);
	sfRenderWindow_drawRectangleShape(
		g_graphic.window, philo->graphic_life[1], NULL);
	return (1);
}

static int	graphic_put_state(t_philo *philo)
{
	sfSprite	*sprite;

	sprite = philo->sprites[philo->state];
	sfRenderWindow_drawSprite(g_graphic.window, sprite, NULL);
	return (1);
}

void		graphic_show_philos(t_philo *philos)
{
	int	i;

	i = philos->number;
	while (1)
	{
		console_put_state(philos);
		if (!g_option.no_graphic)
		{
			graphic_put_state(philos);
			graphic_put_life(philos);
		}
		philos = philos->next;
		if (i == philos->number)
			break ;
	}
	if (!g_option.no_graphic)
		sfRenderWindow_display(g_graphic.window);
	usleep(500000);
	ft_print("-------------------------\n");
}
