#include "philosophers.h"

char			g_dead = 0;
char			g_timeout = 0;

int				main(void)
{
	t_philo		*philos;

	philos = initiate_philos(NUMBER_PHILOS, 0);
	launch_timer();
	launch_threads(philos, NUMBER_PHILOS);
	wait_threads(philos, NUMBER_PHILOS);
	free_philosophers(philos);
	return (0);
}
