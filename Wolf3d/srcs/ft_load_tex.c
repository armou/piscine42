/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:43:41 by aoudin            #+#    #+#             */
/*   Updated: 2017/03/10 17:10:36 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
/*
void	ft_add_sprite(t_env *v, int sprite, double x, double y)
{
	SPRITEX = x;
	SPRITEY = y;
	SPRITETEX = sprite;
}

void	ft_init_sprite(t_env *v)
{
	ft_add_sprite(v, RABBITSP, 10, 5);
}*/

void	ft_sprite_tex(t_env *v)
{
	RABBIT = mlx_xpm_file_to_image(MLX, "tex/RabbitSpriteTex.xpm", &SPTEXW, &SPTEXH);
}

void	ft_floor_tex(t_env *v)
{
	GRASS = mlx_xpm_file_to_image(MLX, "tex/GrassTex2.xpm", &FTEX, &FTEX);
	MARBLE = mlx_xpm_file_to_image(MLX, "tex/MarbleTileTex.xpm", &FTEX, &FTEX);
	CEIL = mlx_xpm_file_to_image(MLX, "tex/CeilTex.xpm", &FTEX, &FTEX);
	SKYBOX = mlx_xpm_file_to_image(MLX, "tex/skyboxtexcopy.xpm", &STEXW, &STEXH);
}

void	ft_init_tex(t_env *v)
{
	ft_floor_tex(v);
	ft_sprite_tex(v);
//	ft_init_sprite(v);
	WALL = mlx_xpm_file_to_image(MLX, "tex/StoneWallTex_1.xpm", &TEX, &TEX);
	WINDOW = mlx_xpm_file_to_image(MLX, "tex/WindowTex.xpm", &TEX, &TEX);
	DOOR = mlx_xpm_file_to_image(MLX, "tex/DoorTex.xpm", &TEX, &TEX);
}
