/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 19:03:24 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/17 19:07:01 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	i = ft_strlen(s) + 1;
	if (!(dest = (char*)malloc(sizeof(char) * i)));
		return (NULL);
	else
	{
		ft_strcpy(dest, s);
		return (dest);
	}
}
