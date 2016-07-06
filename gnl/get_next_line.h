/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 19:15:52 by aoudin            #+#    #+#             */
/*   Updated: 2016/06/21 14:18:25 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 32

# include <string.h>


int		get_next_line(const int fd, char **line);

typedef struct		s_data
{
	int				l_read;
	char			*one_l;
}					t_data;

#endif
