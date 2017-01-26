#include "philosophers.h"

static t_philo	*make_it_circular(t_philo *philos)
{
	t_philos	*tmp;

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

t_philo			*initiate_philos(int number, t_philo *prev)
{
	t_philo		*philo;

	if (number <= 0)
		return (0);
	philo = (t_philo *)ft_memalloc(sizeof(t_philo));
	philo->life = MAX_LIFE;
	philo->stick = 1;
	philo->s = THINK;
	pthread_mutex_init(&philo->lock, 0);
	philo->prev = prev;
	philo->next = initiate_philos(--number, philo);
	return (make_it_circular(philo));
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
	if (philos)
	{
		philos->prev->next = 0;
		free_philos(philos);
	}
}
