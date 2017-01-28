#include "philosophers.h"
#include "graphics.h"

char			g_dead = 0;
char			g_timeout = 0;
t_graphic		g_graphic;

int				main(void)
{
	t_philo		*philos;

	graphic_init();
	philos = initiate_philos(NUMBER_PHILOS);
	launch_timer();
	launch_threads(philos, NUMBER_PHILOS);
	wait_threads(philos, NUMBER_PHILOS);
	free_philosophers(philos);
	return (0);
}
