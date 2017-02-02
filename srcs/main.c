/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:25:30 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:25:31 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "graphics.h"

char			g_dead = 0;
char			g_timeout = 0;
t_graphic		g_graphic;

int				main(void)
{
	t_philo		*philos;

	if (!graphic_init())
		return (1);
	if (!(philos = initiate_philos(NUMBER_PHILOS)))
	{
		graphic_destroy_windows();
		return (1);
	}
	graphic_init_philo(philos);
	launch_timer();
	launch_threads(philos, NUMBER_PHILOS);
	graphic_loop(philos);
	wait_threads(philos, NUMBER_PHILOS);
	free_philosophers(philos);
	graphic_destroy_windows();
	return (0);
}
