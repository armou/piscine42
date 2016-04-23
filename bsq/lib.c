/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/03/29 09:06:00 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int a;

	a = 0;
	if (str)
	{
		while (str[a])
		{
			ft_putchar(str[a]);
			++a;
		}
	}
}

int		ft_atoi(char *str)
{
	int a;
	int nb;
	int negatif;

	a = 0;
	nb = 0;
	negatif = 1;
	while (str[a] == '\n' || str[a] == '\t' || str[a] == '\v' ||
	str[a] == ' ' || str[a] == '\f' || str[a] == '\r')
		a++;
	if (str[a] == 45)
		negatif = -1;
	if ((str[a] == 43) || (str[a] == 45))
		a++;
	while ((str[a]) && ((str[a] >= 48) && (str[a] <= 57)))
	{
		nb = nb * 10 + str[a] - 48;
		a++;
	}
	return (nb * negatif);
}

int		ft_strlen(char *str)
{
	int		a;

	a = 0;
	if (str)
	{
		while (str[a])
			++a;
		return (a);
	}
	else
		return (0);
}
