/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:25:28 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:25:28 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#include <stdlib.h>

static void		free_philos_sprite(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < 4)
		sfSprite_destroy(philos->sprites[i]);
}

static void		free_sticks(t_stick *sticks)
{
	if (sticks != 0)
	{
		free_sticks(sticks->next);
		pthread_mutex_destroy(&sticks->lock);
		free(sticks);
	}
}

static void		free_philos(t_philo *philos)
{
	if (philos != 0)
	{
		free_philos(philos->next);
		free_philos_sprite(philos);
		free(philos);
	}
}

void			free_philosophers(t_philo *philos)
{
	t_stick		*sticks;

	sticks = philos->lstick;
	if (sticks)
	{
		sticks->prev->next = 0;
		free_sticks(sticks);
	}
	if (philos)
	{
		philos->prev->next = 0;
		free_philos(philos);
	}
}
