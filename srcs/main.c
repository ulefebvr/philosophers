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
t_options		g_option;

int				main(int ac, char **av)
{
	t_philo		*philos;
	int			status;

	status = 0;
	g_option = get_option(ac, av);
	if (g_option.no_graphic || graphic_init() || (status = 0))
	{
		philos = initiate_philos(7);
		if (philos || (status = 0))
		{
			if (g_option.no_graphic
				|| graphic_init_philo(philos) || (status = 0))
			{
				if (!g_option.no_graphic && g_option.audio)
					sfMusic_play(g_graphic.music);
				launch_timer();
				launch_threads(philos, 7);
				graphic_loop(philos);
				wait_threads(philos, 7);
				graphic_destroy_windows();
			}
			free_philosophers(philos);
		}
	}
	return (status);
}
