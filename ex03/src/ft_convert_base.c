/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:55:19 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/14 19:43:22 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_base_ten(char *nbr, char *base_from)
{
	int		i;
	int		j;
	int		len;
	int		base;

	len = ft_strlen(nbr);
	i = -1;
	base = 0;
	while (nbr[++i])
	{
		j = 0;
		while (nbr[i] != base_from[j])
			j++;
		base += j * ft_power(ft_strlen(base_from), len - i - 1);
	}
	return (base);
}

char	*ft_convert_base(int nbr, char *base_from, char *base_to)
{
	char	*str;
	int		len_b;
	int		i;

	(void)base_from;
	len_b = ft_strlen(base_to);
	str = (char*)malloc(sizeof(char) * (32));
	i = 0;
	while (nbr > 0)
	{
		str[i] = base_to[nbr % len_b];
		nbr /= len_b;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
