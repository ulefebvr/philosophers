#include "philosophers.h"

#include <stdlib.h>

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
