/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:13:21 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/17 20:21:19 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void		ft_exit()
{
	exit(1);
}

static int		ft_calc_x(char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i])
		{
			x++;
			while (str[i] != ' ' && str[i])
				i++;
		}
		i++;
	}
	return (x);
}

static void		ft_parsefdf(t_windata *t_fdf, int fd)
{
	char	*line;
	int		i;
	int		j;

	t_fdf->ymax = 0;
	t_fdf->map = ft_strnew(BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		if (!t_fdf->xmax)
			t_fdf->xmax = ft_calc_x(line);
		t_fdf->map = ft_strjoinfree(t_fdf->map, line);
		t_fdf->map = ft_strjoinfree(t_fdf->map, "\n");
		t_fdf->ymax++;
		free(line);
	}
	if (!(t_fdf->tab = (char***)ft_memalloc(sizeof(char**) * (t_fdf->ymax + 1))))
		ft_exit();
	//	printf("map = %s\n", t_fdf->map);
	t_fdf->split = ft_strsplit(t_fdf->map, '\n');
//	i = -1;
//	while (++i < t_fdf->ymax)
//		printf("strsplit[i] = %s\n", t_fdf->split[i]);
	i = -1;
	while (t_fdf->split[++i])
	{
		t_fdf->tab[i] = ft_strsplit(t_fdf->split[i], ' ');
		free(t_fdf->split[i]);
	}
	free(t_fdf->split);
//	i = -1;
//	while (t_fdf->tab[++i])
//	{
//		j = -1;
//		while (t_fdf->tab[i][++j])
//			printf("tab[%d][%d] = %s\n", i, j, t_fdf->tab[i][j]);
//	}
}

static void		write_data_pixel(t_windata *t_fdf)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	int			colortmp;

	colortmp = 255;
	b = (colortmp & 0xFF0000) >> 16;
	g = (colortmp & 0xFF00) >> 8;
	r = (colortmp & 0xFF);
	DATA[t_fdf->y1 * t_fdf->size_line + t_fdf->x1 * (BPP / 8)] = r;
	DATA[t_fdf->y1 * t_fdf->size_line + t_fdf->x1 * (BPP / 8) + 1] = g;
	DATA[t_fdf->y1 * t_fdf->size_line + t_fdf->x1 * (BPP / 8) + 2] = b;
}

static	void	bressenham(t_windata *t_fdf)
{
	int i;

	i = -1;
	while (++i <= t_fdf->longest)
	{
		write_data_pixel(t_fdf);
		t_fdf->numerator += t_fdf->shortest;
		if (!(t_fdf->numerator < t_fdf->longest))
		{
			t_fdf->numerator -= t_fdf->longest;
			t_fdf->x1 += DX1;
			t_fdf->y1 += DY1;
		}
		else
		{
			t_fdf->x1 += DX2;
			t_fdf->y1 += DY2;
		}
	}
}

static void		launch_algo(t_windata *t_fdf)
{
	DX1 = 0;
	DY1 = 0;
	DX2 = 0;
	DY2 = 0;
	DX1 = ((t_fdf->x2 - t_fdf->x1) < 0) ? -1 : 1;
	DY1 = ((t_fdf->y2 - t_fdf->y1) < 0) ? -1 : 1;
	DX2 = ((t_fdf->x2 - t_fdf->x1) < 0) ? -1 : 1;
	t_fdf->longest = abs(t_fdf->x2 - t_fdf->x1);
	t_fdf->shortest = abs(t_fdf->y2 - t_fdf->y1);
	if (!(t_fdf->longest > t_fdf->shortest))
	{
		t_fdf->longest = abs(t_fdf->y2 - t_fdf->y1);
		t_fdf->shortest = abs(t_fdf->x2 - t_fdf->x1);
		DY2 = ((t_fdf->y2 - t_fdf->y1) < 0) ? -1 : 1;
		DX2 = 0;
	}
	t_fdf->numerator = t_fdf->longest >> 1;
	bressenham(t_fdf);
}

static void		ft_algo(t_windata *t_fdf)
{
	t_fdf->x1 = ZOOM * (J - I) + (WIDTH / 2);
	t_fdf->y1 = ZOOM * ((J + I) - Z1 / 10) + (HEIGHT / 4);
	t_fdf->x2 = ZOOM * (L - K) + (WIDTH / 2);
	t_fdf->y2 = ZOOM * ((L + K) - Z2 / 10) + (HEIGHT / 4);
	launch_algo(t_fdf);
}

static int		ft_display(t_windata *t_fdf)
{
	I = -1;
	while (t_fdf->tab[++I])
	{
		K = I;
		L = 0;
		while (t_fdf->tab[I][++L])
		{
			J = L - 1;
			t_fdf->z2 = ft_atoi(t_fdf->tab[I][L]);
			t_fdf->z1 = ft_atoi(t_fdf->tab[I][J]);
			ft_algo(t_fdf);
		}
	}
	K = 0;
	while (t_fdf->tab[++K])
	{
		I = K - 1;
		J = -1;
		while (t_fdf->tab[K][++J])
		{
			L = J;
			t_fdf->z2 = ft_atoi(t_fdf->tab[K][J]);
			t_fdf->z1 = ft_atoi(t_fdf->tab[I][J]);
			ft_algo(t_fdf);
		}
	}
	mlx_put_image_to_window(t_fdf->mlx, t_fdf->win, t_fdf->img, 0, 0);
	return (0);
}

static void		ft_init_image(t_windata *t_fdf)
{
	ZOOM = 15;
	t_fdf->mlx = mlx_init();
	t_fdf->win = mlx_new_window(t_fdf->mlx, HEIGHT, WIDTH, "mlx");
	t_fdf->img = mlx_new_image(t_fdf->mlx, HEIGHT, WIDTH);
	t_fdf->data = mlx_get_data_addr(t_fdf->img, &t_fdf->bpp, &t_fdf->size_line,
			&t_fdf->endian);
}

static void		ft_f5(t_windata *t_fdf)
{
	mlx_destroy_image(t_fdf->mlx, t_fdf->img);
	t_fdf->img = mlx_new_image(t_fdf->mlx, HEIGHT, WIDTH);
	t_fdf->data = mlx_get_data_addr(t_fdf->img, &t_fdf->bpp, &t_fdf->size_line,
			&t_fdf->endian);
}

static int		ft_hookevent(int keycode, t_windata *t_fdf)
{
	if (keycode == 53)
		exit(0);
	ft_f5(t_fdf);
	if (keycode == 24 || keycode == 69)
		ZOOM += (ZOOM < 200) ? 2 : 0;
	if (keycode == 27 || keycode == 78)
		ZOOM -= (ZOOM > 0) ? 2 : 0;
	return (0);
}

static void		ft_create_struct(int fd, char *map)
{
	t_windata		*t_fdf;

	if (!(t_fdf = (t_windata*)ft_memalloc(sizeof(t_windata))))
		ft_exit();
	ft_parsefdf(t_fdf, fd);
	ft_init_image(t_fdf);
	mlx_loop_hook(t_fdf->mlx, ft_display, t_fdf);
	mlx_hook(t_fdf->win, KeyPress, KeyPressMask, ft_hookevent, t_fdf);
	mlx_loop(t_fdf->mlx);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;

	if (ac != 2)
		ft_putstr("erreur\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
			ft_create_struct(fd, av[1]);
		else
			ft_putstr("erreur\n");
		close(fd);
	}
	return (0);
}
