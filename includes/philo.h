/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:31:33 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:31:34 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philosophers.h"

# define BOTH	1
# define LEFT	-1
# define RIGHT	2

void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo, int side);
void		philo_rest(t_philo *philo);
int			everything_safe(t_philo *philo);

#endif
