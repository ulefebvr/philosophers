#include "philosophers.h"

int				main(void)
{
	t_philo		*philos;

	philos = initiate_philos(0);
	free_philosophers(philos);
}
