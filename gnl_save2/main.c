/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:05:37 by aoudin            #+#    #+#             */
/*   Updated: 2016/07/26 17:08:05 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	fd = 0;
	ret = 0;
	if (ac > 1)
	{
		if ((fd = open(av[1], O_RDONLY)) > 0)
		{
			while ((ret = get_next_line(fd, &line)) > 0)
			{
				printf("ret2 = %d\n", ret);
				printf("line = %s\n", line);
			}
			if (ret < 0)
			{
				printf("error reading\n");
			}
			close(fd);
		}
		else
		{
			printf("fd = %d\n", fd);
			printf("error opening\n");
		}
	}
	else
		while ((ret = get_next_line(0, &line)) > 0)
		{
			printf("toto\n");
		}
	return (0);
}
