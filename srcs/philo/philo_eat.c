#include "philosophers.h"

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
}
