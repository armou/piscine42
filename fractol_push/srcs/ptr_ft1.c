/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_ft1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:49:37 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 13:04:29 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_ptrexit(void *arg, int keycode)
{
	(void)arg;
	(void)keycode;
	exit(0);
}

void			ft_movud(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	MOVUD += (keycode == 126) ? -10 / ZOOM : 10 / ZOOM;
}

void			ft_movlr(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	MOVLR += (keycode == 123) ? -10 / ZOOM : 10 / ZOOM;
}

void			ft_modif_itmax(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	ITMAX += (keycode == 67) ? 10 : 0;
	ITMAX -= ((keycode == 75) && (ITMAX >= 10)) ? 10 : 0;
}

void			ft_modif_rotation(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	(void)keycode;
	ROT = (ROT == 1) ? 0 : 1;
}
