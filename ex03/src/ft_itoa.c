/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:58:22 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/16 18:52:05 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_itoanext(int nb, char *str, int i)
{
	while (nb)
	{
		str[--i] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	int		i;
	int		tmp;
	char	*str;

	i = 0;
	tmp = nb;
	while (tmp)
	{
		tmp = tmp / 10;
		i++;
	}
	if (nb < 0)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	if (nb < 0)
		str[0] = '-';
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		str[0] = '0';
	return (ft_itoanext(nb, str, i));
}
