#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

/*
** Le nombre de philosophes participant au challenge.
*/
#define NUMBER_PHILOS			7

/*
** Le nombre de points de vie maximum des philosophes.
*/
# define MAX_LIFE				30

/*
** Le nombre de SECONDES que met un philosophe à manger.
*/
# define EAT_T					3

/*
** Le nombre de SECONDES pendant lesquels un philosophe se repose.
*/
# define REST_T					3

/*
** Le nombre de SECONDES pendant lesquels un philosophe réfléchit.
*/
# define THINK_T				3

/*
** Le temps en SECONDES après lesquels la simulation s’interrompt
** en affichant “Now, it is time... To DAAAAAAAANCE ! ! !”
*/
# define TIMEOUT				60

/*
** Convertion seconds to useconds.
*/
# define SECONDS(x)				(x * 1000 * 1000)

typedef enum			e_state
{
	THINK, REST, EAT
}						t_state;

typedef struct			s_philo
{
	unsigned int		life;
	char				stick;
	t_state				state;
	pthread_mutex_t		lock;
	pthread_t			thread;
	struct s_philo		*next;
	struct s_philo		*prev;
}						t_philo;

extern char				g_dead;
extern char				g_timeout;

t_philo					*initiate_philos(int number, t_philo *prev);
void					free_philosophers(t_philo *philos);

void					launch_timer(void);
void					launch_threads(t_philo *philos, int count);
void					wait_threads(t_philo *philos, int count);

#endif
