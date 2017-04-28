/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:00:23 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 12:55:43 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_exit(int a)
{
	if (a == -1)
	{
		ft_putendl("Usage : ./fractol <name>");
		ft_putendl("-mandelbrot");
		ft_putendl("-julia");
		ft_putendl("-burningship");
		ft_putendl("-cauliflower");
		ft_putendl("-trichorn");
		ft_putendl("-crownbrot");
		ft_putendl("-custom");
	}
	exit(0);
}

int				ft_exitprog(t_f *t_fol)
{
	(void)t_fol;
	exit(0);
	return (0);
}

int				ft_keypress(int keycode, t_f *t_fol)
{
	t_fol->pfonct_key[keycode](t_fol, keycode);
	return (0);
}

int				ft_button(int button, int x, int y, t_f *t_fol)
{
	t_fol->pfonct_mouse[button](button, x, y, t_fol);
	return (0);
}

void			ft_init(void *arg, int keycode)
{
	t_f		*t_fol;

	(void)keycode;
	t_fol = arg;
	R = 555;
	G = 100;
	B = 100;
	ITMAX = 51;
	ZOOM = 100;
	MOVLR = 0;
	MOVUD = 0;
	ROT = 0;
	UI = 0;
	ZOOMX = 0;
	ZOOMY = 0;
	VARX = 0;
	VARY = 0;
	VAR = 0;
}
