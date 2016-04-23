/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexdump.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:02:35 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/23 19:23:02 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_print_oct(int lu)
{
	char	*oct;
	int		i;
	int		j;

	oct = ft_itoa(lu);
//	printf("\noct == %s\n", oct);
//	oct = ft_convert_base(ft_putnbr_base(lu), BASE, HEX);
	i = 6;
	j = 0;
//	ft_putchar('\n');
	while (lu < ft_power(16, i))
	{
		i--;
		ft_putchar('0');
	}
//	while (j < (7 - i))
//	{
//		ft_putchar('0');
//		j++;
//	}
	ft_putnbr_base(lu, HEX);
/*	if ((fmt % 16) == 0)
	{
		if (fmt)
			ft_putchar('\n');
		tmp = ft_convert_base(fmt, BASE, HEX);
		ft_putstr(tmp);
	} */
//	printf("oct = %s\n", oct);
}

void	ft_printit(char str)
{
	int		i;
	char	*tmp;

	ft_putstr(" ");
	tmp = ft_convert_base(str, BASE, HEX);
	i = 2 - ft_strlen(tmp);
	while (i--)
		ft_putchar('0');
	ft_putstr(tmp);
}

void	ft_putoption(char *str, int option, int i)
{
	if (option == 1)
	{
		ft_putchar('X');
		while (i % 16 != 0)
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

void	ft_lastline(char *str, int fmt, int i)
{
	int tmp;

	tmp = fmt - 1;
	if (str[i] == '\0')
	{
		while (fmt % 16 != 0)
			fmt++;
		ft_putchar('\n');
		ft_print_oct(tmp);
	}
}
void	ft_printhexdump(char *str, int option)
{
	int		i;
	int		fmt;
//	int		lu;

	i = 0;
	fmt = 1;
//	lu = 0;
//	ft_printit(str[i]);
	while (str[i] != '\0')
	{
		if (fmt == 1)
		{
			ft_putstr("0000000");
//			ft_putchar('Y');
		}
		if (fmt % 16 == 1 && fmt > 2)
		{
			ft_print_oct(fmt - 1);
//			lu+=16;
		}
		ft_printit(str[i]);
		if ((fmt) % 16 == 0 && fmt > 1)
		{
			ft_putoption(str, option, i - 16);
//			ft_putnbr(i);
//			ft_putnbr(fmt);
			ft_putchar('\n');
		}
		i++;
		fmt++;
	//	printf("\nfmt = %d\n", fmt);
	}
	ft_lastline(str, fmt, i);
	ft_putchar('\n');
}
