/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 19:07:44 by aoudin            #+#    #+#             */
/*   Updated: 2016/06/21 14:18:22 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
//	char	*str;
	char			*buf;
	int				i;
	int				ret;
	int				line_read;
	static t_data	*gnl = NULL;

	i = 0;
	if (!gnl)
	{
		if (!(gnl = (t_data*)malloc(sizeof(t_data))))
			return (-1);
	}
	if (fd < 0 || !line)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	read(fd, buf, BUFF_SIZE);
	printf("fd == %d\n", fd);
	line_read = 0;
//	printf("buf = %s\n", buf);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		line_read = 1;
	}
	if (ret == -1)
		return (-1);
	if (line_read == 1)
	{
		line_read = 0;
//		if (strcmp("", *line) != 0)
//			return (1);
	}
	return (1);
}

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
				printf("ret = %d\n", ret);
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
