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

static t_option_arguments		*get_option_params(void)
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

static void						show_help(void)
{
	ft_fdprint(2, "%s\n",
	"usage : ./philo [-valh] [-s spritename]\n\n"
	"-v --verbose                                   "
	"display only in verbose mode, no graphics\n"
	"-s --sprite [philo|coco|nyangoroge|panpaka]    "
	"change sprite. philo is the default one\n"
	"-a --audio                                     "
	"activate music\n"
	"-l --life                                      "
	"display life on the screen\n"
	"-h --help                                      "
	"diplay this help message\n"
	);
	exit(1);
}

void							option_sprite(char **av)
{
	(void)av;
	if (!ft_strcmp("philo", g_option_optarg))
		g_option.spritenbr = 0;
	else if (!ft_strcmp("nyangoroge", g_option_optarg))
		g_option.spritenbr = 1;		
	else if (!ft_strcmp("panpaka", g_option_optarg))
		g_option.spritenbr = 2;
	else if (!ft_strcmp("coco", g_option_optarg))
		g_option.spritenbr = 3;
	else
	{
		ft_fdprint(2, "%s\n", "Invalid sprite argument :"
		"-s --sprite [philo|coco|nyangoroge|panpaka]");
		exit (1);
	}	
}

static void						handle_option(int c, char **av)
{
	if (c == 'h')
		show_help();
	else if (c == 's')
		option_sprite(av);
	else if (c == 'a')
		g_option.audio = 1;
	else if (c == 'v')
		g_option.no_graphic = 1;
	else if (c == 'l')
		g_option.show_life = 1;
	else if (c == '?')
		exit(1);
}

t_options						get_option(int ac, char **av)
{
	int					c;
	int					option_index;
	t_option_arguments	*opt_param;

	option_index = 0;
	ft_bzero(&g_option, sizeof(t_options));
	opt_param = get_option_params();
	opt_param->longind = &option_index;
	while (1)
	{
		if (!(c = option_getopt_long(&(t_arguments){ac, av, 0}, opt_param)))
			c = opt_param->longopts[option_index].val;
		else if (c == -1)
			break ;
		handle_option(c, av);
	}
	return (g_option);
}
