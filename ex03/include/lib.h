/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:38:22 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/23 19:08:50 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

# define BUF_SIZE 512
# define BASE "0123456789"
# define HEX "0123456789abcdef"

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_power(int nb, int pow);
char	*ft_strrev(char *str);
int		ft_strlen(char *str);
char	*ft_convert_base(int nbr, char *base_from, char *base_to);
char	*ft_hexdump(char *file);
void	ft_printhexdump(char *str, int option);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int nb);
void	ft_putnbr_base(int nb, char *base);
void	ft_putnbr(int n);

#endif
