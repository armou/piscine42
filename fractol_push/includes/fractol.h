/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:51:54 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 12:51:40 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "../libs/minilibx_macos/mlx.h"
# include "../libs/libft/libft.h"
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# include <pthread.h>

# define WIDTH 800
# define HEIGHT 800
# define W_CENTRE ((WIDTH / 100) / 1.98)
# define H_CENTRE ((HEIGHT / 100) / 1.98)

# define LD long double

# define MLX t_fol->mlx
# define IMG t_fol->img
# define WIN t_fol->win
# define DATA t_fol->data
# define BPP t_fol->bpp
# define ZOOM t_fol->zoom
# define ENDIAN t_fol->endian
# define SIZELINE t_fol->size_line
# define FINDEX t_fol->findex
# define R t_fol->r
# define G t_fol->g
# define B t_fol->b
# define ITMAX t_fol->itmax
# define ZOOM t_fol->zoom
# define ZOOMX t_fol->zoomx
# define ZOOMY t_fol->zoomy
# define MOVLR t_fol->movlr
# define MOVUD t_fol->movud
# define ROT t_fol->rot
# define VAR t_fol->var
# define VARX t_fol->varx
# define VARY t_fol->vary
# define UI t_fol->ui
# define VARC t_fol->var_col

# define ZI th->zi
# define ZR th->zr
# define CI th->ci
# define CR th->cr
# define IT th->it
# define X th->x
# define Y th->y

typedef struct			s_f
{
	int					bpp;
	int					endian;
	int					size_line;
	char				*data;
	void				*img;
	void				*mlx;
	void				*win;
	int					width;
	int					height;
	long				r;
	long				g;
	long				b;
	int					findex;
	int					itmax;
	long double			zoom;
	long double			zoomx;
	long double			zoomy;
	long double			movlr;
	long double			movud;
	int					rot;
	int					ui;
	int					var;
	long double			varx;
	long double			vary;
	int					var_col;
	void				(*pfonct_fal[7])(void *, void *);
	void				(*pfonct_key[279])(void *, int);
	void				(*pfonct_mouse[10])(int, int, int, void *);
}						t_f;

typedef struct			s_th
{
	int					i;
	int					x;
	int					y;
	long double			zi;
	long double			zr;
	long double			cr;
	long double			ci;
	long				it;
	void				*fol;
}						t_th;

void					ft_ptr_ft(t_f *t_fol);
void					ft_mandelbrot(void *arg, void *arg2);
void					ft_julia(void *arg, void *arg2);
void					ft_cauliflower(void *arg, void *arg2);
void					ft_trichorn(void *arg, void *arg2);
void					ft_burningship(void *arg, void *arg2);
void					ft_crownbrot(void *arg, void *arg2);
void					ft_custom(void *arg, void *arg2);
void					ft_write_data(t_f *t_fol, t_th *th);
void					ft_init(void *arg, int keycode);
int						ft_exitprog(t_f *t_fol);
void					ft_exit(int a);
int						ft_ui(t_f *t_fol);

void					ft_initkey(void *arg, int keycode);
void					ft_initmouse(int button, int x, int y, void *arg);
int						ft_keypress(int keycode, t_f *t_fol);
int						ft_move_mouse(int x, int y, t_f *t_fol);
int						ft_button(int button, int x, int y, t_f *t_fol);
int						ft_keypress(int keycode, t_f *t_fol);
void					ft_movud(void *arg, int keycode);
void					ft_movlr(void *arg, int keycode);
void					ft_modif_itmax(void *arg, int keycode);
void					ft_modif_rotation(void *arg, int keycode);
void					ft_green(void *arg, int keycode);
void					ft_blue(void *arg, int keycode);
void					ft_red(void *arg, int keycode);
void					ft_ptrexit(void *arg, int keycode);
void					ft_zoomkey(void *arg, int keycode);
void					ft_rand_col(void *arg, int keycode);
void					ft_rand_var(void *arg, int keycode);
void					ft_toggle_ui(void *arg, int keycode);
void					ft_key_varcol(void *arg, int keycode);
void					ft_keyvar(void *arg, int keycode);
void					ft_change_fol(void *arg, int keycode);
void					ft_zoommouse(int button, int x, int y, void *arg);
void					ft_mousevar(int button, int x, int y, void *arg);

#endif
