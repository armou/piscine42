/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:53:33 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/17 19:02:58 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	str = ft_strdup(s);
	if (!s || !f || !str)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		str[i] = f(str[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
