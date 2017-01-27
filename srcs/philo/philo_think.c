#include "philo.h"
#include <unistd.h>

static t_stick	*get_stick(t_philo *philo, int side)
{
	t_stick		*stick;

	stick = (side == LEFT ? philo->lstick : philo->rstick);
	stick->stick = 1;
	pthread_mutex_unlock(&stick->lock);
	return (stick);
}

void			philo_think(t_philo *philo, int side)
{
	int			time;
	t_stick		*stick;

	time = 0;
	philo->state = THINK;
	stick = get_stick(philo, side);
	while (stick->stick && everything_safe(philo))
	{
		usleep(SECONDS(1));
		philo->life--;
		if (++time == THINK_T)
			break ;
	}
}
