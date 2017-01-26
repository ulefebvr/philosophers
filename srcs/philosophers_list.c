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

static t_philo	*create_list(int number, t_philo *prev)
{
	t_philo		*philo;

	if (number <= 0)
		return (0);
	if ((philo = (t_philo *)ft_memalloc(sizeof(t_philo))))
	{
		philo->life = MAX_LIFE;
		philo->stick = 1;
		philo->s = THINK;
		pthread_mutex_init(&philo->lock, 0);
		philo->prev = prev;
		if (!(philo->next = initiate_philos(--number, philo)) && number != 0)
		{
			free(philo);
			return (0);
		}
	}
	return (philo);
}

t_philo			*initiate_philos(int number, t_philo *prev)
{
	return (make_it_circular(create_list(number, prev)));
}

static void		free_philos(t_philo *philos)
{
	if (philos != 0)
	{
		free_philos(philos->next);
		pthread_mutex_destroy(&philos->lock);
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
