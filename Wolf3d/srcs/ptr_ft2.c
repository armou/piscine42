/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_ft2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:58:54 by aoudin            #+#    #+#             */
/*   Updated: 2017/03/09 17:52:21 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void			ft_movfb(void *arg, int keycode)
{
	t_env		*v;

	v = arg;
	if (keycode == 126)
	{
		if ((TAB[(int)(POSX + DIRX * MS)][(int)POSY] >= '0') &&
			(TAB[(int)(POSX + DIRX * MS + OFFSET)][(int)POSY] >= '0') &&
			(TAB[(int)(POSX + DIRX * MS - OFFSET)][(int)POSY] >= '0'))
			POSX = POSX + DIRX * MS;
		if ((TAB[(int)POSX][(int)(POSY + DIRY * MS)] >= '0') &&
			(TAB[(int)(POSX + DIRX * MS)][(int)(POSY + OFFSET)] >= '0') &&
			(TAB[(int)(POSX + DIRX * MS)][(int)(POSY - OFFSET)] >= '0'))
			POSY = POSY + DIRY * MS;
	}
	else if (keycode == 125)
	{
		if ((TAB[(int)(POSX - DIRX * MS)][(int)POSY] >= '0') &&
			(TAB[(int)(POSX - DIRX * MS + OFFSET)][(int)POSY] >= '0') &&
			(TAB[(int)(POSX - DIRX * MS - OFFSET)][(int)POSY] >= '0'))
			POSX = POSX - DIRX * MS;
		if ((TAB[(int)POSX][(int)(POSY - DIRY * MS)] >= '0') &&
			(TAB[(int)(POSX + DIRX * MS)][(int)(POSY + OFFSET)] >= '0') &&
			(TAB[(int)(POSX + DIRX * MS)][(int)(POSY - OFFSET)] >= '0'))
			POSY = POSY - DIRY * MS;
	}
}

void			ft_movlr(void *arg, int keycode)
{
	t_env		*v;

	v = arg;
	if (keycode == 124)
	{
		if ((TAB[(int)(POSX + PLANEX * MS)][(int)POSY] >= '0') &&
			 (TAB[(int)(POSX + PLANEX * MS + OFFSET)][(int)POSY] >= '0') &&
			 (TAB[(int)(POSX + PLANEX * MS + OFFSET)][(int)POSY] >= '0'))
			POSX = POSX + PLANEX * MS;
		if ((TAB[(int)POSX][(int)(POSY + PLANEY * MS)] >= '0') &&
			(TAB[(int)POSX][(int)(POSY + PLANEY * MS + OFFSET)] >= '0') &&
			(TAB[(int)POSX][(int)(POSY + PLANEY * MS - OFFSET)] >= '0'))
			POSY = POSY + PLANEY * MS;
	}
	else if (keycode == 123)
	{
		if ((TAB[(int)(POSX - PLANEX * MS)][(int)POSY] >= '0') &&
			 (TAB[(int)(POSX - PLANEX * MS + OFFSET)][(int)POSY] >= '0') &&
			 (TAB[(int)(POSX - PLANEX * MS - OFFSET)][(int)POSY] >= '0'))
			POSX = POSX - PLANEX * MS;
		if ((TAB[(int)POSX][(int)(POSY - PLANEY * MS)] >= '0') &&
			(TAB[(int)POSX][(int)(POSY + PLANEY * MS + OFFSET)] >= '0') &&
			(TAB[(int)POSX][(int)(POSY + PLANEY * MS + OFFSET)] >= '0'))
			POSY = POSY - PLANEY * MS;
	}
}

void			ft_rotright(void *arg, int keycode)
{
	t_env		*v;
	double	dirxtmp;
	double	planextmp;

	(void)keycode;
	v = arg;
	dirxtmp = DIRX;
	DIRX = DIRX * cos(-ROTSPEED) - DIRY * sin(-ROTSPEED);
	DIRY = dirxtmp * sin(-ROTSPEED) + DIRY * cos(-ROTSPEED);
	planextmp = PLANEX;
	PLANEX = PLANEX * cos(-ROTSPEED) - PLANEY * sin(-ROTSPEED);
	PLANEY = planextmp * sin(-ROTSPEED) + PLANEY * cos(-ROTSPEED);
	ROTSPEED = 0.1;
}

void			ft_rotleft(void *arg, int keycode)
{
	t_env		*v;
	double	dirxtmp;
	double	planextmp;

	(void)keycode;
	v = arg;
	dirxtmp = DIRX;
	DIRX = DIRX * cos(ROTSPEED) - DIRY * sin(ROTSPEED);
	DIRY = dirxtmp * sin(ROTSPEED) + DIRY * cos(ROTSPEED);
	planextmp = PLANEX;
	PLANEX = PLANEX * cos(ROTSPEED) - PLANEY * sin(ROTSPEED);
	PLANEY = planextmp * sin(ROTSPEED) + PLANEY * cos(ROTSPEED);
	ROTSPEED = 0.1;
}

void			ft_activate(void *arg, int keycode)
{
	t_env		*v;

	v = arg;
	(void)keycode;
	if (TAB[(int)(POSX + DIRX)][(int)(POSY + DIRY)] == 'D')
		TAB[(int)(POSX + DIRX)][(int)(POSY + DIRY)] = '1';
//	else if (TAB[(int)POSX][(int)POSY + 1] >= '0')
//		TAB[(int)POSX][(int)POSY] = 'D';
}
