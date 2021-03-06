/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:32:46 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:32:47 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include "SFML/Graphics.h"

/*
** Le nombre de points de vie maximum des philosophes.
*/
# define MAX_LIFE				10

/*
** Le nombre de SECONDES que met un philosophe à manger.
*/
# define EAT_T					1

/*
** Le nombre de SECONDES pendant lesquels un philosophe se repose.
*/
# define REST_T					1

/*
** Le nombre de SECONDES pendant lesquels un philosophe réfléchit.
*/
# define THINK_T				1

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
	DEAD, REST, THINK, EAT
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
	sfSprite			*sprites[4];
	sfRectangleShape	*graphic_life[2];
	struct s_philo		*next;
	struct s_philo		*prev;
}						t_philo;

typedef struct			s_options
{
	int					spritenbr;
	int					no_graphic;
	int					show_life;
	int					audio;
	int					max_life;
	int					eat;
	int					rest;
	int					think;
	int					timeout;
}						t_options;

extern char				g_dead;
extern char				g_timeout;
extern t_options		g_option;

t_options				get_option(int ac, char **av);

t_philo					*initiate_philos(int number);
void					free_philosophers(t_philo *philos);

void					launch_timer(void);
void					launch_threads(t_philo *philos, int count);
void					wait_threads(t_philo *philos, int count);

void					*start_philo(void *philo);

#endif
