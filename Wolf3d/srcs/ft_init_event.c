/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:00:26 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/14 19:16:26 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int			ft_exitprog(t_env *v)
{
	(void)v;
	exit(0);
	return(0);
}

void		ft_exit(int i)
{
	if (i == 1)
		ft_putendl("map error");
	if (i == 2)
		ft_putendl("Thanks for playing !");
	exit(0);
}

int			ft_calc_x(char *line)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void		ft_parse_wolf(t_env *v, int fd)
{
	char	*line;
//	int		i;

	YMAX = 0;
	line = NULL;
	MAP = ft_strnew(BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		!XMAX ? XMAX = ft_calc_x(line) : 0;
//		if (xmax != ft_calc_x(line) || !xmax)
//			ft_exit(1);
		MAP = ft_strjoinfree(MAP, line);
		MAP = ft_strjoinfree(MAP, "\n");
		YMAX++;
//		dprintf(1, "%s\n", line);
		free(line);
	}
	TAB = ft_strsplit(MAP, '\n');
//	dprintf(1, "tab ll = %s\n", TAB[XMAX - 1]);
//	i = -1;
//	while (TAB[++i])
//		dprintf(1, "tab[%d] = %s\n", i, TAB[i]);
	ft_init_var(v);
}
