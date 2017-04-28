/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_ft2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:22:02 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/01 16:50:14 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_green(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	G += (keycode == 84) ? -50 : 50;
}

void	ft_blue(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	B += (keycode == 85) ? -50 : 50;
}

void	ft_red(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	R += (keycode == 83) ? -50 : 50;
}

void	ft_zoomkey(void *arg, int keycode)
{
	t_f		*t_fol;

	t_fol = arg;
	if ((keycode == 69 || keycode == 24))
	{
		ZOOM *= 1.1;
		ZOOMX = (ZOOMX + (400 / 10)) * 1.1;
		ZOOMY = (ZOOMY + (400 / 10)) * 1.1;
	}
	if ((keycode == 78 || keycode == 27) && ZOOM > 10)
	{
		ZOOM /= 1.1;
		ZOOMX = (ZOOMX - (400 / 11)) / 1.1;
		ZOOMY = (ZOOMY - (400 / 11)) / 1.1;
	}
}

void	ft_zoommouse(int button, int x, int y, void *arg)
{
	t_f		*t_fol;

	t_fol = arg;
	if ((button == 2 || button == 5) && ZOOM > 10)
	{
		ZOOM /= 1.1;
		ZOOMX = (ZOOMX - (x / 11)) / 1.1;
		ZOOMY = (ZOOMY - (y / 11)) / 1.1;
	}
	if (button == 1 || button == 4)
	{
		ZOOM *= 1.1;
		ZOOMX = (ZOOMX + (x / 11)) * 1.1;
		ZOOMY = (ZOOMY + (y / 11)) * 1.1;
	}
}
