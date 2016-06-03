/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:28:22 by aoudin            #+#    #+#             */
/*   Updated: 2016/06/03 19:54:47 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void		ft_error(int a)
{
	if (a == 1)
		ft_putstr("error\n");
	exit(0);
}

int		ft_init(char *buf, int len)
{
	//	int			i;
	int			map[MAP_SIZE - 1];
	int			j;
	t_datastore	*vault;
	t_lista		*lst;

	lst = NULL;
	if (!(vault = (t_datastore*)malloc(sizeof(*vault))))
		return (0);
	vault->count = ft_count_tminos(buf, len, &lst);
	vault->sq_size = 0;
	vault->bin_value = 0;
	printf("vault->count == %d\n", vault->count);
	j = 0;
	ft_mapsize(map, lst, vault);
	while (lst)
	{
		j = 0;
		while (j < 4)
		{
			ft_move_top(lst);
			ft_move_right(lst);
			ft_putstr(strbin(lst->tetri[j], 4));
			ft_putchar('\n');
		//	printf("lst->tetri[%d] == %d\n", j, lst->tetri[j]);
			j++;
		}
		ft_putchar('\n');
		lst = lst->next;
	}
	j = 0;
	while (map[j])
	{
		ft_putstr(strbin(map[j], MAP_SIZE - 1));
		ft_putchar('\n');
		j++;
	}
	return (0);
}

int		ft_count_tminos(char *buf, int len, t_lista **lst)
{
	int		i;
	int		count;
//	int		map[MAP_SIZE - 1];
//	static int		sq_size = 0;

	i = 0;
	count = len + 1;
	if (count % 21 == 0)
	{
		count = count / 21;
		printf("count == %d\n", count);
	}
	while (i < count)
	{
		if (ft_checkerror((buf + (21 * i)), len) && ft_valid_tminos(buf + (21 * i)))
		{
			ft_store((buf + (21 * i)), lst, count);
			i++;
		}
		else
			ft_error(1);
		printf("i == %d\n", i);
	}
	//ft_setmap(map, &sq_size, count);
	return (count);
}

int		ft_checkerror(char *buf, int ret)
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

void		ft_read(int fd, char *file)
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
	ft_init(str, len);
	//	ft_count_tminos(str, len);


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
