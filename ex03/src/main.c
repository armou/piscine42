/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 14:34:30 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/23 19:34:11 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		main(int ac, char **av)
{
	int		option;
	char	*tmp;
//	int		end_arg;

	option = 0;
	if (ac > 1)
	{
		if (ft_strcmp(av[1], "-C") == 0)
			option = 1;
		else
			option = 0;
		tmp = ft_hexdump(av[option + 1]);
//		ft_putstr(tmp);
		ft_printhexdump(tmp, option);
	}
	return (0);
}
