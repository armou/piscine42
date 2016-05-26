/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:51:27 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/26 12:56:16 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include "libft.h"

# define BUF 512

typedef struct		s_list
{
	struct s_list	*next;
	char			**data;
}					t_list;

void				ft_putstr(char *str);
static void			ft_read(int fd);

#endif
