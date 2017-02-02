/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:27:13 by rclanget          #+#    #+#             */
/*   Updated: 2017/02/02 22:27:13 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void				graphic_destroy_windows(void)
{
	pthread_mutex_destroy(&g_graphic.mutex);
	sfTexture_destroy(g_graphic.texture);
	sfRenderWindow_destroy(g_graphic.window);
}
