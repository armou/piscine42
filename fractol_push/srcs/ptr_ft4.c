/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_ft4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:57:59 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 13:04:49 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_initkey(void *arg, int keycode)
{
	(void)arg;
	(void)keycode;
}

void			ft_initmouse(int button, int x, int y, void *arg)
{
	(void)arg;
	(void)button;
	(void)x;
	(void)y;
}

int				ft_move_mouse(int x, int y, t_f *t_fol)
{
	if (VAR == 1)
	{
		VARX = (((LD)x - WIDTH / 2) / 150);
		VARY = (((LD)y - HEIGHT / 2) / 150);
	}
	return (0);
}

void			ft_rand_var(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	(void)keycode;
	VARX = ((LD)(rand() % 100)) / 1000;
	VARY = ((LD)(rand() % 100)) / 1000;
}

void			ft_rand_col(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	(void)keycode;
	R = rand() % 1000;
	G = rand() % 1000;
	B = rand() % 1000;
}
