/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:51:27 by aoudin            #+#    #+#             */
/*   Updated: 2016/06/03 19:53:18 by aoudin           ###   ########.fr       */
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
# define MAX_INT 2147483647
# define MAP_SIZE 20

typedef struct		s_lista
{
	struct s_lista	*next;
	int				rank;
	int				tetri[4];
	int				spot;
	int				height;
}					t_lista;

typedef struct		s_datastore
{
	int				count;
	int				sq_size;
	int				bin_value;
}					t_datastore;

void				ft_read(int fd, char *file);
int					ft_checkerror(char *buf, int ret);
int					ft_valid_tminos(char *str);
void				ft_error(int a);
int					ft_count_tminos(char *buf, int len, t_lista **lst);
void				ft_list(int *nb, t_lista **lst, int count);
void				ft_store(char *buf, t_lista **lst, int count);
int					*ft_map(int *map);
void				ft_move_top(t_lista *list);
void				ft_move_right(t_lista *list);
int					ft_sqroot(int nb);
int					ft_power(int nb, int power);
void				ft_setmap(int *map, t_datastore *vault);
int					ft_init(char *buf, int len);
int					ft_mapsize(int *map, t_lista *lst, t_datastore *vault);
int					ft_fillmap(int *map, t_lista *lst, t_datastore *vault);
char				*strbin(const unsigned int n, const short nb_bits);

#endif
