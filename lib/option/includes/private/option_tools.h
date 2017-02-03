/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 18:51:51 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/26 18:51:51 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_TOOLS_H
# define OPTION_TOOLS_H

int				ft_fdprint(int fd, const char *fmt, ...);
char			*ft_strchr(const char *str, char c);
unsigned int	ft_strlen(const char *str);
int				ft_strcmp(char *p1, char *p2);
int				ft_strncmp(const char *p1, const char *p2, int size);

#endif
