#include "philo.h"
#include <unistd.h>

static void	wait(t_philo *philo)
{
	usleep(SECONDS(1));
	philo->life--;
}

void		philo_rest(t_philo *philo)
{
	int		time;

	time = 0;
	if (philo->state == REST)
		return (wait(philo));
	philo->state = REST;
	while (everything_safe(philo))
	{
		usleep(SECONDS(1));
		philo->life--;
		if (++time == REST_T)
			break ;
	}
}
