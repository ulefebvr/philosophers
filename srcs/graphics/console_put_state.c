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
#include "libft.h"

void			console_put_state(t_philo *philo)
{
	ft_print("Philo number: %d", philo->number);
	if (philo->state == REST)
		ft_print(", state: REST, life: %d\n", philo->life);
	else if (philo->state == THINK)
		ft_print(", state: THINK, life: %d\n", philo->life);
	else if (philo->state == EAT)
		ft_print(", state: EAT, life: %d\n", philo->life);
	else if (philo->state == DEAD)
		ft_print(", state: DEAD, life: %d\n", philo->life);
}
