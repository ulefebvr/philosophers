#include "philo.h"
#include <unistd.h>

void		philo_rest(t_philo *philo)
{
	int		time;

	time = 0;
	philo->state = REST;
	while (everything_safe(philo))
	{
		usleep(SECONDS(1));
		philo->life--;
		if (++time == REST_T)
			break ;
	}
}
