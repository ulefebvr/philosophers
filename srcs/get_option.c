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
		{"lifebar", NO_ARGUMENT, &g_option.show_life, 'l'},
		{"maxlife", REQUIRED_ARGUMENT, 0, 'm'},
		{"eat", REQUIRED_ARGUMENT, 0, 'e'},
		{"rest", REQUIRED_ARGUMENT, 0, 'r'},
		{"think", REQUIRED_ARGUMENT, 0, 't'},
		{"timeout", REQUIRED_ARGUMENT, 0, 'o'},
		{"help", NO_ARGUMENT, 0, 'h'},
		{0, 0, 0, 0}
	};
	static t_option_arguments	params = {"vs:h", option_info, 0};

	return (&params);
}

static void						show_help(void)
{
	ft_fdprint(2, "%s\n",
	"usage : ./philo [-vh] [-s spritename]\n\n"
	"-v --verbose                                   "
	"display only in verbose mode, no graphics\n"
	"-s --sprite [philo|coco|nyangoroge|panpaka]    "
	"change sprite. philo is the default one\n"
	"--audio                                        "
	"activate music\n"
	"--lifebar                                      "
	"display life on the screen\n"
	"--maxlife=n                                    "
	"modify maxlife value set to 10 by default\n"
	"--eat=n                                        "
	"modify eat time value set to 4 by default\n"
	"--rest=n                                       "
	"modify rest time value set to 3 by default\n"
	"--think=n                                      "
	"modify think time value set to 3 by default\n"
	"--timeout=n                                    "
	"modify timeout value set to 60 by default\n"
	"-h --help                                      "
	"diplay this help message\n");
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
		exit(1);
	}
}

static void						handle_option(int c, char **av)
{
	static int	*time[5] = {&g_option.max_life, &g_option.eat, &g_option.think,
		&g_option.rest, &g_option.timeout};
	static char	*time_str = "metro";
	static int	*opt[3] = {
		&g_option.audio, &g_option.no_graphic, &g_option.show_life};
	static char	*opt_str = "avl";

	if (c == 'h')
		show_help();
	else if (c == 's')
		option_sprite(av);
	else if (ft_strchr(opt_str, c))
		*(opt[ft_strchr(opt_str, c) - opt_str]) = 1;
	else if (ft_strchr(time_str, c))
		*(time[ft_strchr(time_str, c) - time_str]) = ft_atoi(g_option_optarg);
	else if (c == '?')
		exit(1);
	if (((g_option.max_life <= 0) || (g_option.eat <= 0) || (g_option.rest <= 0)
		|| (g_option.think <= 0) || (g_option.timeout <= 0))
		&& ft_fdprint(2, "%s\n", "Time value cannot be set to negative value"))
		exit(1);
}

t_options						get_option(int ac, char **av)
{
	int					c;
	int					option_index;
	t_option_arguments	*opt_param;

	option_index = 0;
	ft_bzero(&g_option, sizeof(t_options));
	g_option.max_life = MAX_LIFE;
	g_option.eat = EAT_T;
	g_option.rest = REST_T;
	g_option.think = THINK_T;
	g_option.timeout = TIMEOUT;
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
