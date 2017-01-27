/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:55:21 by zipo              #+#    #+#             */
/*   Updated: 2017/01/27 01:26:43 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

int g_i = 0; // ***************** DEBUG ***************

/*
*	Dans le cas ou un philosophe sort de l'etat repos et que ses deux voisins
*	mangent, il se retrouve a devoir faire la seule action disponible pour lui : se reposer.
*	Pour le temps de reflexion, c'est un temps qu'il doit effectuer entièrement
*	a part si un autre philosophe a besoin de sa baguette
*/


/*
*	Un philosophe ne peut se saisir d’une baguette que si elle se trouve
*	adjacente à lui	(droite ou gauche).
*	Deux philosophes ne peuvent pas utiliser la même baguette au même moment.
*/
void	unlock_stick(t_stick *left, t_stick *right)
{
	if (left)
	{
		left->stick = 1;
		pthread_mutex_unlock(&left->lock);
	}
	if (right)
	{
		right->stick = 1;
		pthread_mutex_unlock(&right->lock);
	}
}

int		check_stick(t_philo *philo)
{
	int	stick;

	stick = 0;
	if (philo->lstick->stick && !pthread_mutex_trylock(&philo->lstick->lock))
	{
		philo->lstick->stick = 0;
		++stick;
		// pthread_mutex_unlock(&philo->lstick->lock);
	}
	if (philo->rstick->stick && !pthread_mutex_trylock(&philo->rstick->lock))
	{
		philo->rstick->stick = 0;
		++stick;
		// pthread_mutex_unlock(&philo->rstick->lock);
	}
	return(stick);
}

void	philo_eat(t_philo *philo)
{
	philo->state = EAT;
	usleep(SECONDS(EAT_T));
	philo->life = MAX_LIFE;
	unlock_stick(philo->lstick, philo->rstick);
}

/*
*	Problème: Comment savoir quand un voisin récupère la baguette ? (pour arrêter de réfléchir)
*/
void	philo_think(t_philo *philo)
{
	t_stick *stick;

	stick = (!pthread_mutex_unlock(&philo->lstick->lock) ? philo->lstick : philo->rstick);
	philo->state = THINK;
	usleep(SECONDS(THINK_T));
	stick->stick = 1;
}

void	philo_rest(t_philo *philo)
{
	philo->state = REST;
	usleep(SECONDS(REST_T));
}

/*
*	Ne pas oublier de faire perdre 1 pt de vie par seconde (quand il ne mange pas)
*/
#include <stdio.h> // ***************** DEBUG ***************
void	*start_philo(void *philo)
{
	t_philo	*p;
	int		stick;
	int		process = g_i++;

	p = (t_philo *)philo;
	while ((p->life > 0) && !g_dead && !g_timeout)
	{
		printf("P: %d, life: %d, state: %d\n", process, p->life, p->state); // ***************** DEBUG ***************
		if ((stick = check_stick(p)) == 2)
			philo_eat(p);
		else if (stick == 1)
			philo_think(p);
		philo_rest(p);
		p->life -= 4; // ***************** DEBUG ***************
	}
	if (p->life <= 0)
		g_dead = 1;
	return (0);
}
