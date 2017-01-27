#ifndef PHILO_H
# define PHILO_H

# include "philosophers.h"

# define BOTH	1
# define LEFT	-1
# define RIGHT	2

void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo, int side);
void		philo_rest(t_philo *philo);
int			everything_safe(t_philo *philo);

#endif
