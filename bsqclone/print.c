/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/05/18 18:08:07 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void		ft_print_list(t_list *list)
{
	int a;

	a = 0;
	if (list->empty == '\0' || (list->data == NULL))
		ft_putstr("Map error\n");
	else
	{
		while (list->data[a] != NULL)
		{
			ft_putstr(list->data[a]);
			ft_putchar('\n');
			++a;
		}
	}
}
