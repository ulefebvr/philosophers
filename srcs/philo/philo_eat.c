#include "philo.h"
#include <unistd.h>

static void	unlock_sticks(t_philo *philo)
{
	philo->lstick->stick = 1;
	pthread_mutex_unlock(&philo->lstick->lock);
	philo->rstick->stick = 1;
	pthread_mutex_unlock(&philo->rstick->lock);
}

void		philo_eat(t_philo *philo)
{
	int		time;

	time = 0;
	philo->state = EAT;
	while (everything_safe(philo))
	{
		usleep(SECONDS(1));
		if (++time == EAT_T)
		{
			philo->life = MAX_LIFE;
			break ;
		}
	}
	unlock_sticks(philo);
}
