/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/05/18 17:51:50 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

/*
** This function tests if every line has same number of chars
** Return 0 if not
*/

int	ft_error_check_line(char *buf)
{
	int a;
	int size;
	int temp_size;

	a = 0;
	size = 0;
	temp_size = 0;
	while (buf[a] != '\n')
		++a;
	++a;
	while (buf[a])
	{
		++temp_size;
		if (buf[a] == '\n')
		{
			if (size == 0)
				size = temp_size;
			if (temp_size != size)
				return (0);
			temp_size = 0;
		}
		++a;
	}
	return (1);
}

/*
** Test if list->lines (entered by user) corresponds to real lines number
** Return 0 if not
*/

int	ft_error_compare_lines(char *buf, t_list *list)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (buf && buf[a])
	{
		if (buf[a] == '\n')
			++count;
		++a;
	}
	if (count - 1 == list->lines)
		return (1);
	else
		return (0);
}

/*
** Test if first line has errors
** If yes, we nitialize list->data with NULL
*/

int	ft_error_first_line(char *buf)
{
	int a;
	int error;

	a = 0;
	error = 1;
	while (buf[a] >= '0' && buf[a] <= '9')
		++a;
	if (a == 0)
		error = 0;
	if (!buf[a] || !buf[a + 1] || !buf[a + 2] || buf[a + 3] != '\n' ||
		!buf[a + 4])
		error = 0;
	return (error);
}

int	ft_error_test_content(t_list *list, char *buf, int a)
{
	while (buf[a] != '\0')
	{
		if (buf[a] != list->empty && buf[a] != list->obs && buf[a] != '\n')
			return (0);
		++a;
	}
	return (1);
}
