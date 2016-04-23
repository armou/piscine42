/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/03/31 19:21:01 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDE_H
# define FT_INCLUDE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BIN "01"
# define HEX "0123456789abcdef"
# define BUF_SIZE 16296

typedef struct		s_list
{
	struct s_list	*next;
	char		**data;
	int		lines;
	int		columns;
	char		empty;
	char		obs;
	char		full;
}			t_list;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int			ft_strlen(char *str);
char			*ft_strrev(char *str);
char			*ft_strcat(char *dest, char *src);
int			ft_recursive_power(int nb, int power);
t_list			*ft_fd(char *str);
char			*ft_strcpy(char *dest, char *src);
t_list			*ft_create_elem(char *buf);
char			**ft_data(char *buf, t_list *list, int a);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
void			ft_print_list(t_list *list);
void			ft_print_list_bis(t_list *list);
t_list			*ft_make_list(int ac, char **av);
int			ft_max_length(t_list *list, int max_side);
int			ft_max_width(t_list *list, int max_side);
int			ft_find_square(t_list *list, int side, int line, int column);
int			ft_solve(t_list *list, int side, int a, int b);
void			ft_put_full_char(t_list *list, int side, int a, int b);
int			ft_error_check_line(t_list *list);
int			ft_error_test_n(char *str);
int			ft_error_test_char(t_list *list);
int     ft_test_buf(char *buf, t_list *list);

#endif
