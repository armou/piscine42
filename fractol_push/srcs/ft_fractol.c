/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:55:08 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 12:00:25 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_mandelbrot(void *arg, void *arg2)
{
	t_f			*t_fol;
	t_th		*th;
	long double	tmp;

	t_fol = arg;
	th = arg2;
	CR = (ROT == 0) ? (((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR :
		(((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD;
	CI = (ROT == 0) ? (((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD :
		(((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR;
	ZR = 0 + VARX;
	ZI = 0 + VARY;
	IT = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++IT < ITMAX))
	{
		tmp = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * tmp + CI;
	}
	if (VARC == 1)
		IT = IT != ITMAX ? 0 : IT;
	else if (IT == ITMAX)
		IT = 0;
	ft_write_data(t_fol, th);
}

void			ft_julia(void *arg, void *arg2)
{
	t_f			*t_fol;
	t_th		*th;
	long double tmp;

	t_fol = arg;
	th = arg2;
	ZR = (ROT == 0) ? (((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR :
		(((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD;
	ZI = (ROT == 0) ? (((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD :
		(((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR;
	CR = 0.285 + VARX;
	CI = 0.01 + VARY;
	IT = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++IT < ITMAX))
	{
		tmp = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * tmp + CI;
	}
	if (VARC == 1)
		IT = IT != ITMAX ? 0 : IT;
	else if (IT == ITMAX)
		IT = 0;
	ft_write_data(t_fol, th);
}

void			ft_burningship(void *arg, void *arg2)
{
	t_f			*t_fol;
	t_th		*th;
	long double	tmp;

	t_fol = arg;
	th = arg2;
	CR = (ROT == 0) ? (((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR :
		(((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD;
	CI = (ROT == 0) ? (((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD :
		(((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR;
	ZR = 0 + VARX;
	ZI = 0 + VARY;
	IT = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++IT < ITMAX))
	{
		tmp = ZR;
		ZR = (fabs)((double)(ZR * ZR - ZI * ZI)) + CR;
		ZI = 2 * (fabs)((double)(ZI * tmp)) + CI;
	}
	if (VARC == 1)
		IT = IT != ITMAX ? 0 : IT;
	else if (IT == ITMAX)
		IT = 0;
	ft_write_data(t_fol, th);
}

void			ft_cauliflower(void *arg, void *arg2)
{
	t_f			*t_fol;
	t_th		*th;
	long double	tmp;

	t_fol = arg;
	th = arg2;
	ZR = (ROT == 0) ? (((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR :
		(((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD;
	ZI = (ROT == 0) ? (((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD :
		(((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR;
	CR = -0.90 + VARX;
	CI = 0.1 + VARY;
	IT = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++IT < ITMAX))
	{
		tmp = ZR;
		ZR = (fabs)((double)(ZR * ZR - ZI * ZI)) + CR;
		ZI = 2 * (fabs)((double)(ZI * tmp)) + CI;
	}
	if (VARC == 1)
		IT = IT != ITMAX ? 0 : IT;
	else if (IT == ITMAX)
		IT = 0;
	ft_write_data(t_fol, th);
}

void			ft_trichorn(void *arg, void *arg2)
{
	t_f			*t_fol;
	t_th		*th;
	long double	tmp;

	t_fol = arg;
	th = arg2;
	CR = (ROT == 0) ? (((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR :
			(((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD;
	CI = (ROT == 0) ? (((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD :
			(((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR;
	ZR = 0 + VARX;
	ZI = 0 + VARY;
	IT = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++IT < ITMAX))
	{
		tmp = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = -2 * ZI * tmp + CI;
	}
	if (VARC == 1)
		IT = IT != ITMAX ? 0 : IT;
	else if (IT == ITMAX)
		IT = 0;
	ft_write_data(t_fol, th);
}
