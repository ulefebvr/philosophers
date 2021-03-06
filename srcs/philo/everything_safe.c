/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   everything_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:30:36 by zipo              #+#    #+#             */
/*   Updated: 2017/01/27 15:32:47 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	everything_safe(t_philo *philo)
{
	return ((!g_dead && !g_timeout && philo->life > 0));
}
