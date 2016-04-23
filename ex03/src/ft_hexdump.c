/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 14:41:06 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/23 15:34:36 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_fileerror(char *file)
{
		ft_putstr("\nhexdump: ");
		ft_putstr(file);
		ft_putstr(": No such file or directory\n");
		
		ft_putstr("hexdump: ");
		ft_putstr(file);
		ft_putstr(": Bad file descriptor\n");
}

char	*ft_hexdump(char *file)
{
	int		fd;
	int		len;
	char	buf[BUF_SIZE];
	char	*str;

	len = 0;
	fd = open(file, O_RDONLY);
	
	if (fd < 0)
		ft_fileerror(file);
	while (read(fd, buf, 1))
		len++;
//	buf[len] = 0;
	close(fd);
	fd = open(file, O_RDONLY);
//	printf("len==%d\n", len);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	read(fd, str, len);
	str[len] = '\0';
	close(fd);
	return (str);
}
