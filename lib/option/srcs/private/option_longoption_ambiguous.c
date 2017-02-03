/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_longoption_ambiguous.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 18:51:22 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/26 18:51:22 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include "option_private.h"
#include "option_longoption.h"
#include "option_tools.h"

#include <stdlib.h>

int		option_treat_longoption_ambiguous(
			char **argv, t_treat_longoption *info, t_option_data *d)
{
	t_option_list *tmp;

	if (d->opterr)
	{
		ft_fdprint(2, "%s: option '%s' is ambiguous; possibilities: '--%s'",
			argv[0], argv[d->optind], info->pfound->name);
		while (info->ambig_list != 0)
		{
			ft_fdprint(2, " '--%s'", info->ambig_list->p->name);
			tmp = info->ambig_list;
			info->ambig_list = info->ambig_list->next;
			free(tmp);
		}
		ft_fdprint(2, "\n");
	}
	d->private_nextchar += ft_strlen(d->private_nextchar);
	d->optind++;
	d->optopt = 0;
	return ('?');
}
