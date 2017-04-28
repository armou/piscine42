/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_ft3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:56:09 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 12:26:43 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_toggle_ui(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	(void)keycode;
	UI = (UI == 1) ? 0 : 1;
}

void		ft_mousevar(int button, int x, int y, void *arg)
{
	t_f		*t_fol;

	t_fol = arg;
	(void)button;
	(void)x;
	(void)y;
	if (VAR == 0)
		VAR = 1;
	else
		VAR = 0;
}

void		ft_keyvar(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	(void)keycode;
	if (VAR == 0)
		VAR = 1;
	else
		VAR = 0;
}

void		ft_key_varcol(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	(void)keycode;
	if (VARC == 0)
		VARC = 1;
	else
		VARC = 0;
}

void		ft_change_fol(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	FINDEX = keycode == 18 ? 0 : FINDEX;
	FINDEX = keycode == 19 ? 1 : FINDEX;
	FINDEX = keycode == 20 ? 2 : FINDEX;
	FINDEX = keycode == 21 ? 3 : FINDEX;
	FINDEX = keycode == 23 ? 4 : FINDEX;
	FINDEX = keycode == 22 ? 5 : FINDEX;
	FINDEX = keycode == 26 ? 6 : FINDEX;
	ft_init(arg, keycode);
}
