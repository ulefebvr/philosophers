/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:23:33 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:24:11 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "graphics.h"
#include "libft.h"

static int		graphic_put_state(t_philo *philo)
{
	sfSprite *sprite;

	sprite = philo->sprites[philo->state];
	sfRenderWindow_drawSprite(g_graphic.window, sprite, NULL);
	sfRenderWindow_display(g_graphic.window);
	return (1);
}

static void		graphic_show_philos(t_philo *philos)
{
	int i;

	i = philos->number;
	while (1)
	{
		graphic_put_state(philos);
		console_put_state(philos);
		philos = philos->next;
		if (i == philos->number)
			break ;
	}
	ft_print("-------------------------\n");
}

static int		handle_event(sfEvent event, int *exit_now)
{
	if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
		|| event.type == sfEvtClosed)
	{
		*exit_now = 1;
		g_dead = 1;
	}
	return (g_dead);
}

static void		wait_for_exit(void)
{
	sfEvent	event;

	while (sfRenderWindow_waitEvent(g_graphic.window, &event))
	{
		if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
			|| event.type == sfEvtClosed)
			break ;
	}
}

void			graphic_loop(t_philo *philo)
{
	sfEvent		event;
	int			exit_now;

	exit_now = 0;
	while (!g_dead && !g_timeout)
	{
		if (sfRenderWindow_pollEvent(g_graphic.window, &event)
			&& handle_event(event, &exit_now))
			break ;
		graphic_show_philos(philo);
	}
	if (!exit_now)
	{
		if (g_dead)
			graphic_show_philos(philo);
		else if (g_timeout)
			time_to_dance();
		wait_for_exit();
	}
}
