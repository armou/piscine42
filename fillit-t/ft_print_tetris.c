/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 18:25:10 by aoudin            #+#    #+#             */
/*   Updated: 2016/06/03 18:34:10 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*strbin(const unsigned int n, const short nb_bits)
{
	unsigned	bit;
	unsigned	mask;
	char		*buffer;
	int			i;

	bit = 0;
	mask = 1;
	i = -1;
	buffer = malloc(nb_bits + 1);
	while (++i < nb_bits)
	{
		bit = (n & mask) >> i;
		buffer[i] = (char)('0' + bit);
		mask <<= 1;
	}
	buffer[nb_bits] = '\0';
	return (buffer);
}
