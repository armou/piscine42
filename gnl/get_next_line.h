/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 19:15:52 by aoudin            #+#    #+#             */
/*   Updated: 2016/07/27 15:06:19 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 10
# include <string.h>
# include "./libft/libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_data
{
	int				i_fd;
	int				l_read;
	char			*one_l;
	char			*store_buf;
	t_list			*next;
}					t_data;

#endif
