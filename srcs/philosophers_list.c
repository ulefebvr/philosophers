#include "libft.h"
#include "philosophers.h"

#include <stdlib.h>

static t_stick	*make_it_circular_stick(t_stick *sticks)
{
	t_stick		*tmp;

	tmp = sticks;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp != 0 && (void *)tmp != (void *)sticks)
	{
		tmp->next = sticks;
		sticks->prev = tmp;
	}
	return (sticks);
}

static t_philo	*make_it_circular(t_philo *philos)
{
	t_philo		*tmp;

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

static t_stick	*create_sticks_list(int number, t_stick *prev)
{
	t_stick		*stick;

	if (number <= 0)
		return (0);
	if ((stick = (t_stick *)ft_memalloc(sizeof(t_stick))))
	{
		--number;
		stick->stick = 1;
		pthread_mutex_init(&stick->lock, 0);
		stick->prev = prev;
		if (!(stick->next = create_sticks_list(number, stick))
			&& number != 0)
		{
			free(stick);
			return (0);
		}
	}
	return (stick);
}

static t_philo	*create_list(int number, t_philo *prev, t_stick *sticks)
{
	t_philo		*philo;

	if (number <= 0)
		return (0);
	if ((philo = (t_philo *)ft_memalloc(sizeof(t_philo))))
	{
		--number;
		philo->life = MAX_LIFE;
		philo->lstick = sticks;
		philo->rstick = sticks->next;
		philo->state = THINK;
		philo->prev = prev;
		if (!(philo->next = create_list(number, philo, sticks->next))
			&& number != 0)
		{
			free(philo);
			return (0);
		}
	}
	return (philo);
}

t_philo			*initiate_philos(int number)
{
	t_stick	*sticks;

	sticks = make_it_circular_stick(create_sticks_list(number, 0));
	return (make_it_circular(create_list(number, 0, sticks)));
}
