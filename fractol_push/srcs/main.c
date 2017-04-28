/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:13:21 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 12:52:09 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				ft_get_fractol(t_f *t_fol, char *av)
{
	FINDEX = -1;
	FINDEX = (ft_strcmp(av, "mandelbrot") == 0) ? 0 : FINDEX;
	FINDEX = (ft_strcmp(av, "julia") == 0) ? 1 : FINDEX;
	FINDEX = (ft_strcmp(av, "burningship") == 0) ? 2 : FINDEX;
	FINDEX = (ft_strcmp(av, "cauliflower") == 0) ? 3 : FINDEX;
	FINDEX = (ft_strcmp(av, "trichorn") == 0) ? 4 : FINDEX;
	FINDEX = (ft_strcmp(av, "crownbrot") == 0) ? 5 : FINDEX;
	FINDEX = (ft_strcmp(av, "custom") == 0) ? 6 : FINDEX;
	if (FINDEX == -1)
		ft_exit(-1);
}

void				*ft_fractol(void *arg)
{
	t_th		*th;
	t_f			*t_fol;

	th = (t_th*)arg;
	t_fol = th->fol;
	th->y = (th->i * (HEIGHT / 5)) - 1;
	while (++th->y < (HEIGHT / 5) * (th->i + 1))
	{
		th->x = -1;
		while (++th->x < WIDTH)
			t_fol->pfonct_fal[FINDEX](t_fol, th);
	}
	pthread_exit(0);
}

int					ft_thread(t_f *t_fol)
{
	int			i;
	pthread_t	thread[5];
	t_th		**th;

	if (!(th = (t_th**)ft_memalloc(sizeof(t_th*) * 5)))
		exit(0);
	i = -1;
	while (++i < 5)
	{
		if (!(th[i] = (t_th*)ft_memalloc(sizeof(t_th))))
			exit(0);
		th[i]->i = i;
		th[i]->fol = t_fol;
		pthread_create(&thread[i], NULL, &ft_fractol, th[i]);
	}
	i = -1;
	while (++i < 5)
	{
		(void)pthread_join(thread[i], NULL);
		free(th[i]);
	}
	free(th);
	mlx_put_image_to_window(t_fol->mlx, t_fol->win, t_fol->img, 0, 0);
	UI = (UI == 1) ? ft_ui(t_fol) : 0;
	return (0);
}

t_f					*ft_create_struct(char *av)
{
	t_f		*t_fol;

	if (!(t_fol = (t_f*)ft_memalloc(sizeof(t_f))))
		exit(0);
	ft_init(t_fol, 0);
	ft_ptr_ft(t_fol);
	ft_get_fractol(t_fol, av);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 800, 500, WIDTH, HEIGHT, "Fract'ol");
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	return (t_fol);
}

int					main(int ac, char **av)
{
	t_f		*t_fol;

	if (ac != 2)
		ft_putendl("Usage : ./Fractol <fractol>");
	else
	{
		if (!(t_fol = ft_create_struct(av[1])))
			exit(0);
		mlx_loop_hook(MLX, ft_thread, t_fol);
		mlx_hook(WIN, KeyPress, KeyPressMask, ft_keypress, t_fol);
		mlx_hook(WIN, MotionNotify, ButtonMotionMask, ft_move_mouse, t_fol);
		mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_button, t_fol);
		mlx_hook(WIN, DestroyNotify, Button1MotionMask, ft_exitprog, t_fol);
		mlx_loop(MLX);
	}
	return (0);
}
