#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

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
# define SECONDS(x)				(x * 1000)

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
	struct s_philo		*next;
	struct s_philo		*prev;
}						t_philo;

char					g_dead = 0;

#endif
