/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/04/23 16:27:17 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void		ft_print_list(t_list *list)
{
	int a;

	a = 0;
  if (list->empty == '\0')
    ft_putstr("Map error\n");
//  else if ((!ft_error_test_char(list)) || (!ft_error_check_line(list)))
//		ft_putstr("Map error\n");
	else
	{
		while (list->data[a])
		{
			ft_putstr(list->data[a]);
			ft_putchar('\n');
			++a;
		}
	}
}	
