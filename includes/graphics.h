/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:31:37 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:31:38 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "SFML/Graphics.h"
# include "philosophers.h"

typedef struct		s_graphic
{
	pthread_mutex_t	mutex;
	sfTexture		*texture;
	sfRenderWindow	*window;
}					t_graphic;

extern t_graphic	g_graphic;

void				graphic_destroy_windows(void);

int					graphic_init_philo(t_philo *philo);
int					graphic_init(void);

void				graphic_loop(t_philo *philo);

#endif
