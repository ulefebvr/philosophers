/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:25:00 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:25:01 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static void	swait(t_philo *philo)
{
	usleep(SECONDS(1));
	philo->life--;
}

void		philo_rest(t_philo *philo)
{
	int		time;

	time = 0;
	if (philo->state == REST)
		return (swait(philo));
	philo->state = REST;
	while (everything_safe(philo))
	{
		usleep(SECONDS(1));
		philo->life--;
		if (++time == REST_T)
			break ;
	}
}
