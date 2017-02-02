/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:25:22 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:25:23 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	launch_threads(t_philo *philos, int count)
{
	while (count)
	{
		pthread_create(&philos->thread, 0,
			start_philo, philos);
		philos = philos->next;
		count--;
	}
}

void	wait_threads(t_philo *philos, int count)
{
	while (count)
	{
		pthread_join(philos->thread, 0);
		philos = philos->next;
		count--;
	}
}
