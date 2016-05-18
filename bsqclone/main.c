/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/05/18 18:47:23 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

/*
 ** Main file role is to create lists and permit next operations then solve it
 */

void	ft_run(t_list *list)
{
	int max_side;
	int	check;

	max_side = ft_max_length(list, max_side);
	if (max_side > ft_max_width(list, max_side))
		max_side = ft_max_width(list, max_side);
	check = 0;
	while (max_side >= 0 && !check)
	{
		check = ft_find_square(list, max_side, list->lines - 1,
				list->columns - 1);
		--max_side;
	}
	if (!check)
		ft_print_list(list);
}

t_list	*ft_stdin()
{
	int		ret;
	t_list	*list;
	char	buf[BUF_SIZE + 1];
	char	*str;

	list = NULL;

	while ((ret = read(0, buf, BUF_SIZE)))
	{
		if (!str)
			str = strdup(buf);
		else
			str = ft_strjoin(str, buf);
	}
	if (errno == ENOENT)
		return (0);
	else
	{
		if (ft_error_first_line(str))
		{
			list = ft_create_elem(str);
		}
		else
		{
			list = ft_create_elem(NULL);
		}
	}
	return (list);
}

int		main(int ac, char **av)
{
	t_list	*list;

	//	if (ac < 2)
	//		return (0);
	//	else
	//	{
	list = ft_make_list(ac, av);
	while (list)
	{
		if (!list->data)
			ft_print_list(list);
		else
			ft_run(list);
		list = list->next;
	}
	return (1);
	//	}
}
