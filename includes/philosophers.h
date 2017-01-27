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
# define EAT_T					2

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

typedef struct			s_stick
{
	char				stick;
	pthread_mutex_t		lock;
	struct s_stick		*next;
	struct s_stick		*prev;
}						t_stick;

typedef struct			s_philo
{
	int					number;
	int					life;
	t_stick				*lstick;
	t_stick				*rstick;
	t_state				state;
	pthread_t			thread;
	struct s_philo		*next;
	struct s_philo		*prev;
}						t_philo;

extern char				g_dead;
extern char				g_timeout;

t_philo					*initiate_philos(int number);
void					free_philosophers(t_philo *philos);

void					launch_timer(void);
void					launch_threads(t_philo *philos, int count);
void					wait_threads(t_philo *philos, int count);

void					*start_philo(void *philo);

#endif
