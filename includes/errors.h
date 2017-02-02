/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 00:32:49 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/02/03 00:32:50 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR_OCCURED "An error occurred in "

# define ERR_SPRITES_INIT (ERROR_OCCURED "initialisation of sprites\n")
# define ERR_WINDOW_INIT (ERROR_OCCURED "initialisation of CSFML Window\n")
# define ERR_TEXTURE_INIT (ERROR_OCCURED "initialisation of CSFML Texture\n")
# define ERR_MUTEX_INIT (ERROR_OCCURED "initialisation Graphical Mutex\n")
# define ERR_STICKS_INIT (ERROR_OCCURED "intialisation of Sticks List\n")
# define ERR_PHILOS_INIT (ERROR_OCCURED "intialisation of Philosophers List\n")

#endif
