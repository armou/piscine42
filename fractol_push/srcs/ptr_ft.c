/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:49:49 by aoudin            #+#    #+#             */
/*   Updated: 2017/02/02 12:56:05 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		ft_addr_pfonct_mouse(t_f *t_fol)
{
	t_fol->pfonct_mouse[1] = &ft_zoommouse;
	t_fol->pfonct_mouse[2] = &ft_zoommouse;
	t_fol->pfonct_mouse[5] = &ft_zoommouse;
	t_fol->pfonct_mouse[4] = &ft_zoommouse;
	t_fol->pfonct_mouse[5] = &ft_mousevar;
}

static void		ft_addr_pfonct_cfal(t_f *t_fol)
{
	t_fol->pfonct_key[18] = &ft_change_fol;
	t_fol->pfonct_key[19] = &ft_change_fol;
	t_fol->pfonct_key[20] = &ft_change_fol;
	t_fol->pfonct_key[21] = &ft_change_fol;
	t_fol->pfonct_key[23] = &ft_change_fol;
	t_fol->pfonct_key[22] = &ft_change_fol;
	t_fol->pfonct_key[26] = &ft_change_fol;
}

static void		ft_addr_pfonct_key(t_f *t_fol)
{
	t_fol->pfonct_key[53] = &ft_ptrexit;
	t_fol->pfonct_key[49] = &ft_init;
	t_fol->pfonct_key[123] = &ft_movlr;
	t_fol->pfonct_key[124] = &ft_movlr;
	t_fol->pfonct_key[126] = &ft_movud;
	t_fol->pfonct_key[125] = &ft_movud;
	t_fol->pfonct_key[67] = &ft_modif_itmax;
	t_fol->pfonct_key[75] = &ft_modif_itmax;
	t_fol->pfonct_key[81] = &ft_modif_rotation;
	t_fol->pfonct_key[27] = &ft_zoomkey;
	t_fol->pfonct_key[24] = &ft_zoomkey;
	t_fol->pfonct_key[69] = &ft_zoomkey;
	t_fol->pfonct_key[78] = &ft_zoomkey;
	t_fol->pfonct_key[48] = &ft_toggle_ui;
	t_fol->pfonct_key[83] = &ft_red;
	t_fol->pfonct_key[86] = &ft_red;
	t_fol->pfonct_key[84] = &ft_green;
	t_fol->pfonct_key[87] = &ft_green;
	t_fol->pfonct_key[85] = &ft_blue;
	t_fol->pfonct_key[88] = &ft_blue;
	t_fol->pfonct_key[50] = &ft_keyvar;
	t_fol->pfonct_key[8] = &ft_key_varcol;
	t_fol->pfonct_key[6] = &ft_rand_var;
	t_fol->pfonct_key[7] = &ft_rand_col;
}

static void		ft_addr_pfonct_fal(t_f *t_fol)
{
	t_fol->pfonct_fal[0] = &ft_mandelbrot;
	t_fol->pfonct_fal[1] = &ft_julia;
	t_fol->pfonct_fal[2] = &ft_burningship;
	t_fol->pfonct_fal[3] = &ft_cauliflower;
	t_fol->pfonct_fal[4] = &ft_trichorn;
	t_fol->pfonct_fal[5] = &ft_crownbrot;
	t_fol->pfonct_fal[6] = &ft_custom;
}

void			ft_ptr_ft(t_f *t_fol)
{
	int		i;

	i = -1;
	while (++i < 280)
		t_fol->pfonct_key[i] = ft_initkey;
	i = -1;
	while (++i < 10)
		t_fol->pfonct_mouse[i] = ft_initmouse;
	ft_addr_pfonct_fal(t_fol);
	ft_addr_pfonct_key(t_fol);
	ft_addr_pfonct_cfal(t_fol);
	ft_addr_pfonct_mouse(t_fol);
}
