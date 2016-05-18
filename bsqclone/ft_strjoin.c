/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:02:07 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/18 17:27:24 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	
	i = 0;
	if (*src)
	{
		while (src && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	str = NULL;
	if (s1 && s2)
	{
		if (!(str = (char*)malloc(sizeof(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
}
