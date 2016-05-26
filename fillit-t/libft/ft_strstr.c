/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:33:18 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/25 16:48:58 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (*big)
	{
		if (*big == *little)
		{
			while (big[i] == little[i] && little[i] && big[i])
				i++;
		}
		if (little[i] == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
