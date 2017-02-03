/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:37:39 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/02/03 16:37:40 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include "libft.h"
#include "philosophers.h"

t_option_arguments		*get_option_params(void)
{
	static t_option_info		option_info[] = {
		{"verbose", NO_ARGUMENT, &g_option.no_graphic, 'v'},
		{"sprite", REQUIRED_ARGUMENT, 0, 's'},
		{"audio", NO_ARGUMENT, &g_option.audio, 'a'},
		{"life", NO_ARGUMENT, &g_option.show_life, 'l'},
		{"help", NO_ARGUMENT, 0, 'h'},
		{0, 0, 0, 0}
	};
	static t_option_arguments	params = {"vs:alh", option_info, 0};

	return (&params);
}

t_options				get_option(int ac, char **av)
{
	int					c;
	int					option_index;
	t_option_arguments	*option_params;

	option_index = 0;
	ft_bzero(&g_option, sizeof(t_options));
	option_params = get_option_params();
	option_params->longind = &option_index;
	while (1)
	{
		c = option_getopt_long(&(t_arguments){ac, av, 0}, option_params);
		if (c == -1)
			break ;
	}
	return (g_option);
}
