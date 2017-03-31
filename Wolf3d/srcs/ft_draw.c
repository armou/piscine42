/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:26:07 by aoudin            #+#    #+#             */
/*   Updated: 2017/03/31 18:22:56 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		ft_color(int a, int r, int g, int b)
{
	return (((a & 0xff) << 24) + ((r & 0xff) << 16) + ((g & 0xff) << 8) +
			(b & 0xff));
}


int     ft_add_color(int old_clr, int add_clr, double alpha)
{
    int r;
    int g;
    int b;

    r = floor((double)(((old_clr >> 16) & 0xFF) * alpha) - (double)(((add_clr >> 16) & 0xFF) * alpha));
    g = floor((double)(((old_clr >> 8) & 0xFF) * alpha) - (double)(((add_clr >> 8) & 0xFF) * alpha));
    b = floor((double)(((old_clr) & 0xFF) * alpha) - (double)(((add_clr) & 0xFF) * alpha));
	return (((0 & 0xff) << 24)  + ((r & 0xff) << 16) + ((g & 0xff) << 8)  + (b & 0xff));
}

void	ft_color_floor_tex(t_env *v, int x, int y)
{
	if (TAB[(int)F_XDRAW][(int)F_YDRAW] == '0')
	{
		COLOR = mlx_get_pixel_clr(GRASS, x, y);
		EXT = 1;
	}
//		COLOR = GRASSDATA[PX] + GRASSDATA[PX + 1] * 256 + GRASSDATA[PX + 2] * (256 * 256);
	else
	{
		COLOR = mlx_get_pixel_clr(MARBLE, x, y);
		EXT = 0;
//		ft_floorcasting(v, y, 0);
	}
}

void	ft_color_tex(t_env *v, int y, int x)
{
	if (TAB[MAPX][MAPY] == 'A')
		COLOR = mlx_get_pixel_clr(WALL, x, y);
	else if (TAB[MAPX][MAPY] == 'W')
		COLOR = mlx_get_pixel_clr(WINDOW, x, y);
	else if (TAB[MAPX][MAPY] == 'D')
		COLOR = mlx_get_pixel_clr(DOOR, x, y);
	else
		COLOR = 0;
	if (SIDE == 1)
	{
		if ((RAYDIRX >= 0 && RAYDIRY < 0) || (RAYDIRX < 0 && RAYDIRY < 0))
			COLOR = (COLOR >> 1) & 8355711;
	}
}

void	ft_print_tex(t_env *v, int y)
{
	int		i;
	int		texw;
	int		texh;

	i = y * 256 -  HEIGHT * 128 + LINEHEIGHT * 128;
	if (SIDE == 0)
		WALLX = RAYPOSY + D_PERPWALL * RAYDIRY;
	else
		WALLX = RAYPOSX + D_PERPWALL * RAYDIRX;
	WALLX -= floor(WALLX);
	texw = (int)(WALLX * (double)(TEX));
	if ((SIDE == 0 && RAYDIRX > 0) || (SIDE == 1 && RAYDIRY < 0))
		texw = (TEX - texw - 1);
	texh = ((i * TEX) / LINEHEIGHT) / 256;
	//	if (SIDE == 1)
	//		COLOR = (COLOR >> 1);
	ft_color_tex(v, texh, texw);
}

void	ft_print_wall(t_env *v, int x)
{
	int		y;

	y = -1;
	EXT = 0;
	//	dprintf(1, "x = %d ds= %d, de = %d lh = %d pw = %lf, mapx = %d, mapy = %d, rposx = %lf, rpy = %lf, stx=%d, sty=%d, rdx = %lf, rdy = %lf\n", x, DRAWSTART, DRAWEND, LINEHEIGHT, D_PERPWALL, MAPX, MAPY, RAYPOSX, RAYPOSY, STEPX, STEPY, RAYDIRX, RAYDIRY);
	//	dprintf(1, "dirx = %lfdiry = %lf\n", DIRX, DIRY);

	while (++y < HEIGHT)
	{
		if (y <= DRAWEND && y >= DRAWSTART)
		{
			ft_print_tex(v, y);
			*(int*)&DATA[(y * SIZELINE + x * (BPP / 8))] = COLOR;
		}
		else if (y > DRAWEND)
		{
			ft_floorcasting(v, y, 1);
			*(int*)&DATA[(y * SIZELINE + x * (BPP / 8))] = COLOR;
		}
		else
		{
			ft_skybox(v, x, y);
//			if (EXT == 0)
//			{
				ft_floorcasting(v, y , 0);
				*(int*)&DATA[(y * SIZELINE + x * (BPP / 8))] = COLOR;
//			}
//			if (EXT == 1)
		}
		//ft_create_sprites(v);
	}
}
