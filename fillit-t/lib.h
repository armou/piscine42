/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:51:27 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/26 16:39:06 by aoudin           ###   ########.fr       */
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
# include <fcntl.h>
# include "libft/libft.h"

# define BUF 1

typedef struct		s_lista
{
	struct s_lista	*next;
	char			**data;
}					t_lista;

static void			ft_read(int fd, char *file);
static int			ft_checkerror(char *buf, int ret);

#endif
