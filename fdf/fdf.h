/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:42:02 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/17 19:53:36 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "mlx.h"
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/get_next_line.h"
# include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"

# define HEIGHT 1600
# define WIDTH 1080
# define BPP t_fdf->bpp
# define DATA t_fdf->data
# define DX1 t_fdf->dx1
# define DX2 t_fdf->dx2
# define DY1 t_fdf->dy1
# define DY2 t_fdf->dy2
# define I t_fdf->i
# define J t_fdf->j
# define K t_fdf->k
# define L t_fdf->l
# define Z1 t_fdf->z1
# define Z2 t_fdf->z2
# define ZOOM t_fdf->zoom

typedef	struct			s_windata
{
	char				**split;
	int					bpp;
	int					endian;
	int					size_line;
	char				*data;
	void				*img;
	void				*mlx;
	void				*win;
	char				*map;
	char				***tab;
	int					xmax;
	int					ymax;
	int					zoom;
	int					z1;
	int					z2;
	int					x1;
	int					x2;
	int					y1;
	int					y2;
	int					dx1;
	int					dx2;
	int					dy1;
	int					dy2;
	int					longest;
	int					shortest;
	int					numerator;
	int					i;
	int					j;
	int					k;
	int					l;
}						t_windata;

#endif
