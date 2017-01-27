#include "philosophers.h"

void		philo_think(t_philo *philo)
{
	int		time;

	time = 0;
	philo->state = THINK;
	while (everything_safe(philo))
	{
		usleep(SECONDS(1));
		philo->life--;
		if (++time == THINK_T)
			break ;
	}
}
