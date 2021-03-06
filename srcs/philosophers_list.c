/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:25:24 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:25:26 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errors.h"
#include "philosophers.h"

#include <stdlib.h>

static t_stick	*make_it_circular_stick(t_stick *sticks)
{
	t_stick		*tmp;

	tmp = sticks;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp != 0 && (void *)tmp != (void *)sticks)
	{
		tmp->next = sticks;
		sticks->prev = tmp;
	}
	return (sticks);
}

static t_philo	*make_it_circular(t_philo *philos)
{
	t_philo		*tmp;

	tmp = philos;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp != 0 && (void *)tmp != (void *)philos)
	{
		tmp->next = philos;
		philos->prev = tmp;
	}
	return (philos);
}

static t_stick	*create_sticks_list(int number, t_stick *prev)
{
	t_stick		*stick;

	if (number <= 0)
		return (0);
	if ((stick = (t_stick *)ft_memalloc(sizeof(t_stick))))
	{
		--number;
		stick->stick = 1;
		stick->prev = prev;
		if (pthread_mutex_init(&stick->lock, 0)
			|| (!(stick->next = create_sticks_list(number, stick))
			&& number != 0))
		{
			pthread_mutex_destroy(&stick->lock);
			free(stick);
			return (0);
		}
	}
	return (stick);
}

static t_philo	*create_list(int number, t_philo *prev, t_stick *sticks)
{
	t_philo		*philo;

	if (number <= 0)
		return (0);
	if ((philo = (t_philo *)ft_memalloc(sizeof(t_philo))))
	{
		philo->number = --number;
		philo->life = g_option.max_life;
		philo->lstick = sticks;
		philo->rstick = sticks->next;
		philo->state = THINK;
		ft_bzero(philo->sprites, sizeof(sfSprite *) * 4);
		philo->prev = prev;
		if (!(philo->next = create_list(number, philo, sticks->next))
			&& number != 0)
		{
			free(philo);
			return (0);
		}
	}
	return (philo);
}

t_philo			*initiate_philos(int number)
{
	t_stick	*sticks;
	t_philo *philos;

	sticks = make_it_circular_stick(create_sticks_list(number, 0));
	if (sticks == 0)
	{
		ft_fdprint(2, ERR_STICKS_INIT);
		return (0);
	}
	philos = make_it_circular(create_list(number, 0, sticks));
	if (philos == 0)
		ft_fdprint(2, ERR_PHILOS_INIT);
	return (philos);
}
