/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 17:06:04 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/14 14:30:37 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;
	if (str)
	{
		i = 0;
		len = ft_strlen(str);
		while (i < len / 2)
		{
			tmp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = tmp;
			i++;
		}
	}
	return (str);
}
