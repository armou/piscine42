/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:20:25 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 13:01:09 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_crownbrot(void *arg, void *arg2)
{
	t_f			*t_fol;
	t_th		*th;
	long double	tmp;

	t_fol = arg;
	th = arg2;
	CR = (ROT == 1) ? (((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR :
		(((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD;
	CI = (ROT == 1) ? (((LD)th->y + ZOOMY) / ZOOM) - H_CENTRE + MOVUD :
		(((LD)th->x + ZOOMX) / ZOOM) - W_CENTRE + MOVLR;
	ZR = 0 + VARX;
	ZI = 0 + VARY;
	IT = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++IT < ITMAX))
	{
		tmp = ZR;
		ZR = (fabsl(ZR * ZR - ZI * ZI)) + CR;
		ZI = -2 * (ZI * fabsl(tmp)) + CI;
	}
	if (VARC == 1)
		IT = IT != ITMAX ? 0 : IT;
	else if (IT == ITMAX)
		IT = 0;
	ft_write_data(t_fol, th);
}

void			ft_custom(void *arg, void *arg2)
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
	CR = -1.28 + VARX;
	CI = 0.0 + VARY;
	IT = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++IT < ITMAX))
	{
		tmp = ZR;
		ZR = (fabsl(ZR * ZR) - fabsl(ZI * ZI)) + CR;
		ZI = 3 * (ZI * tmp) + CI;
	}
	if (VARC == 1)
		IT = IT != ITMAX ? 0 : IT;
	else if (IT == ITMAX)
		IT = 0;
	ft_write_data(t_fol, th);
}
