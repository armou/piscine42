/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:28:22 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/26 17:08:44 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void		ft_error(int a)
{
	if (a == 1)
		ft_putstr("error\n");
	exit(0);
}

static int		ft_count_tminos(char *buf, int len)
{
	int		i;
	int		nb;
	int		count;

	i = 0;
	nb = len + 1;
	if (nb % 21 == 0)
	{
		nb = nb / 21;
		printf("nb == %d\n", nb);
	}
	count = nb;
	while (i < count)
	{
		if (ft_checkerror((buf + (21 * i)), len))
			i++;
		else
			ft_error(1);
		printf("i == %d\n", i);
	}
	return (count);
}

static int		ft_checkerror(char *buf, int ret)
{
	int		i;
	int		n;
	int		tab[3];

	i = 0;
	n = ret + 1;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	printf("n == %d\n", n);
	while ((!(buf[i] == '\n' && buf[i + 1] == '\n')) && buf[i])
	{
//		printf("test1");
		if (buf[i] == '.' && buf[i])
			tab[0]++;
		if (buf[i] == '#' && buf[i])
			tab[1]++;
		if (buf[i] == '\n' && buf[i])
			tab[2]++;
		if (buf[i + 1] == '\0')
			tab[2]--;
		i++;
	}
	printf("tab[0] == %d\ntab[1] == %d\ntab[2] == %d\n", tab[0], tab[1], tab[2]);
	if (tab[0] != 12 || tab[1] != 4 || tab[2] != 3)
		return (0);
	else
		return (1);
}

static void		ft_read(int fd, char *file)
{
//	int		ret;
	char	buf[BUF];
	char	*str;
	int		len;

	len = 0;
	while (read(fd, buf, 1))
		len++;
	close (fd);
	fd = open(file, O_RDONLY);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		ft_error(1);
	read(fd, str, len);
	str[len] = '\0';
	ft_count_tminos(str, len);
/*	if ((ret = read(fd, buf, BUF)))
	{
		printf("ret == %d\n", ret);
		if ((ret + 1) % 21 == 0)
		{
			buf[ret] = '\0';
			close(fd);
			ft_count_tminos(buf, ret);
			ft_checkerror(buf, ret);
		}
	}
*/
	close(fd);
}

int				main(int ac, char **av)
{
	int		fd;


	if (ac != 2)
	{
		ft_putstr("usage: missing input file\n");
		return (0);
	}
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) > 0)
		{
			printf("fd == %d\n", fd);
			ft_read(fd, av[1]);
		}
	}
	return (0);
}
