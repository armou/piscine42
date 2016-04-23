/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/04/23 16:30:37 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

/*This function tests if every line has same number of chars
Return 0 if not*/

int	ft_error_check_line(t_list *list)
{
	int a;
	int b;
	int size;
	int temp_size;

	a = 0;
	size = 0;
	while (list->data[a])
	{
		b = 0;
		temp_size = 0;
		while (list->data[a][b])
		{
			++b;
			++temp_size;
		}
		if (size == 0)
			size = temp_size;
		if (temp_size != size)
			return (0);
		++a;
	}
	return (1);
}

/*Test if map is made up by the three chars determinated by the first line of each file
Return 0 if not*/

int	ft_error_test_char(t_list *list)
{
	int a;
	int b;

	a = 0;
	while (list->data[a])
	{
		b = 0;
		while (list->data[a][b])
		{
			if (list->data[a][b] != list->empty && list->data[a][b] != list->obs &&
				list->data[a][b] != list->full)
					return (0);
			++b;
		}
		++a;
	}
	return (1);
}
/*Test if the last char of every lines of a file is '\n'
Return 0 if not*/

int ft_error_test_n(char *buf)
{
/*  printf("error test n\n");
	int	a;
  int b;
  char *lines;

  a = 0;
  lines = (char*)malloc(sizeof(lines) * 5);
  while (buf[a] >= '0' && buf[a] <= '9')
  {
    lines[a] = buf[a];
    ++a;
  }
  lines[a] = '\0';
  a = 0;
  b = 0;
  while (buf[a])
  {
    if (buf[a] == '\n')
      ++b;
    ++a;
  }
  if (b == ft_atoi(lines) - 1)
  {
    printf("Number of lines is egual\n");
    return (1);
  }
  else
{
  printf("Number of lines is egual\n");
    return (0);
}*/
	return (1);
}

/*Test if first line has errors
 * If yes, we nitialize list->data with NULL*/

int ft_test_buf(char *buf, t_list *list)
{
  int a;
  int error;

  a = 0;
  error = 1;
  while (buf[a] >= '0' && buf[a] <= '9')
    ++a;
  if (a == 0)
    error = 0;
  if (!buf[a] || !buf[a + 1] || !buf[a + 2] || buf[a + 3] != '\n' || !buf[a + 4])
      error = 0;
  return (error);
}
