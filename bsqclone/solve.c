/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/05/04 20:12:25 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

/*
** Return max length of list->data without obstacle
** If it does not find any obstacle, function returns list->columns
*/

int		ft_max_length(t_list *list, int max_side)
{
	int	a;
	int	b;
	int	max_temp;

	b = 0;
	while (b < list->columns)
	{
		a = 0;
		max_temp = 0;
		while (a < list->lines)
		{
			if (list->data[a][b] == list->obs)
				if (max_temp > max_side)
					max_side = max_temp;
			if (list->data[a][b] == list->obs)
				max_temp = 0;
			else
				++max_temp;
			++a;
		}
		if (max_temp == list->lines)
			return (list->lines);
		++b;
	}
	return (max_side - 1);
}

/*
** Return max width of list->data without osbtacle
** If it does not find any obstacle in one line, function returns list->lines
*/

int		ft_max_width(t_list *list, int max_side)
{
	int	max_temp;
	int	a;
	int	b;

	a = 0;
	while (a < list->lines)
	{
		b = 0;
		max_temp = 0;
		while (b < list->columns)
		{
			if (list->data[a][b] == list->obs)
				if (max_temp > max_side)
					max_side = max_temp;
			if (list->data[a][b] == list->obs)
				max_temp = 0;
			else
				++max_temp;
			++b;
		}
		if (max_temp == list->columns)
			return (list->columns);
		++a;
	}
	return (max_side - 1);
}

int		ft_find_square(t_list *list, int side, int line, int column)
{
	int a;
	int b;
	int solve;

	solve = 0;
	line = list->lines - 1;
	while (line >= side)
	{
		column = list->columns - 1;
		while (column >= side)
		{
			if (ft_solve(list, side, line, column))
			{
				a = line;
				b = column;
				solve = 1;
			}
			--column;
		}
		--line;
	}
	if (solve)
		ft_put_full_char(list, side, a, b);
	return (solve);
}

void	ft_put_full_char(t_list *list, int side, int a, int b)
{
	int temp_b;
	int length;
	int width;

	temp_b = b;
	length = 0;
	while (length <= side)
	{
		width = 0;
		b = temp_b;
		while (width <= side)
		{
			list->data[a][b] = list->full;
			--b;
			++width;
		}
		--a;
		++length;
	}
	ft_print_list(list);
}

int		ft_solve(t_list *list, int side, int a, int b)
{
	int b_temp;
	int length;
	int width;

	b_temp = b;
	length = side;
	while (length >= 0 && a >= 0)
	{
		width = side;
		b = b_temp;
		while (width >= 0 && b >= 0)
		{
			if (list->data[a][b] == list->obs)
				return (0);
			--width;
			--b;
		}
		--a;
		--length;
	}
	return (1);
}
