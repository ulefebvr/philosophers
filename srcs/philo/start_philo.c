/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:55:21 by zipo              #+#    #+#             */
/*   Updated: 2017/02/02 22:25:15 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int		check_stick(t_philo *philo)
{
	int	stick;

	stick = 0;
	if (philo->life <= philo->prev->life &&
		philo->lstick->stick && !pthread_mutex_trylock(&philo->lstick->lock))
	{
		philo->lstick->stick = 0;
		stick = LEFT;
	}
	if (philo->life <= philo->next->life &&
		philo->rstick->stick && !pthread_mutex_trylock(&philo->rstick->lock))
	{
		philo->rstick->stick = 0;
		stick += RIGHT;
	}
	return (stick);
}

void	*start_philo(void *philosopher)
{
	int		stick;
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	while (!g_dead && !g_timeout && philo->life > 0)
	{
		stick = check_stick(philo);
		if (stick == BOTH)
			philo_eat(philo);
		else if (stick == LEFT || stick == RIGHT)
			philo_think(philo, stick);
		else
			philo_rest(philo);
	}
	if (!g_dead && philo->life <= 0)
	{
		philo->state = DEAD;
		g_dead = 1;
	}
	return (0);
}
