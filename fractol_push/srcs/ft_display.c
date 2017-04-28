/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:42:38 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 11:59:29 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_ui(t_f *t_fol)
{
	mlx_string_put(MLX, WIN, 50, 50, 0x000000, "MOVE WITH ARROWS");
	mlx_string_put(MLX, WIN, 49, 49, 0xFFFFFF, "MOVE WITH ARROWS");
	mlx_string_put(MLX, WIN, 50, 70, 0x000000, "ZOOM [+] [-]");
	mlx_string_put(MLX, WIN, 49, 69, 0xFFFFFF, "ZOOM [+] [-]");
	mlx_string_put(MLX, WIN, 50, 90, 0x000000, "ROTATION [=]");
	mlx_string_put(MLX, WIN, 49, 89, 0xFFFFFF, "ROTATION [=]");
	mlx_string_put(MLX, WIN, 50, 110, 0x000000, "RESET POSITION [SPACE]");
	mlx_string_put(MLX, WIN, 49, 109, 0xFFFFFF, "RESET POSITION [SPACE]");
	mlx_string_put(MLX, WIN, 50, 130, 0x000000, "+/- ITERATION [*] [/]");
	mlx_string_put(MLX, WIN, 49, 129, 0xFFFFFF, "+/- ITERATION [*] [/]");
	mlx_string_put(MLX, WIN, 50, 150, 0x000000, "ACTIVE MOUSE VARIATION [~]");
	mlx_string_put(MLX, WIN, 49, 149, 0xFFFFFF, "ACTIVE MOUSE VARIATION [~]");
	mlx_string_put(MLX, WIN, 50, 170, 0x000000, "RANDOM COLOR [X]");
	mlx_string_put(MLX, WIN, 49, 169, 0xFFFFFF, "RANDOM COLOR [X]");
	mlx_string_put(MLX, WIN, 50, 190, 0x000000, "RANDOM VARIATION [Z]");
	mlx_string_put(MLX, WIN, 49, 189, 0xFFFFFF, "RANDOM VARIATION [Z]");
	mlx_string_put(MLX, WIN, 50, 210, 0x000000, "+/- R/G/B [1/4] [2/5] [3/6]");
	mlx_string_put(MLX, WIN, 49, 209, 0xFFFFFF, "+/- R/G/B [1/4] [2/5] [3/6]");
	mlx_string_put(MLX, WIN, 50, 230, 0x000000, "CHANGE FRACTALE [1-9]");
	mlx_string_put(MLX, WIN, 49, 229, 0xFFFFFF, "CHANGE FRACTALE [1-9]");
	mlx_string_put(MLX, WIN, 50, 250, 0x000000, "QUIT [ESC]");
	mlx_string_put(MLX, WIN, 49, 249, 0xFFFFFF, "QUIT [ESC]");
	return (1);
}

int				ft_color(int a, int r, int g, int b)
{
	return (((a & 0xff) << 24) + ((r & 0xff) << 16) + ((g & 0xff) << 8) +
			(b & 0xff));
}

void			ft_write_data(t_f *t_fol, t_th *th)
{
	int		color;

	if (X < 0 || X >= WIDTH || Y < 0 || Y >= HEIGHT)
		return ;
	color = ft_color(0, (R * IT) / ITMAX, (G * IT) / ITMAX, (B * IT) / ITMAX);
	if (IT == -1)
		color = 0;
	*(int*)&DATA[(Y * SIZELINE + X * (BPP / 8))] = color;
}
