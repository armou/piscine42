/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/05/18 19:54:19 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

/*
 ** This function had to create a char** from readed file in argument
 ** 'lines' and 'column' are both iterators for build 'result', tab with 2 sides
 **  Not sure about size of malloc there ---- MAKE TESTS ----
 */

char	**ft_data(char *buf, t_list *list, int a)
{
	int		line;
	int		column;
	char	**result;

	line = 0;
	result = (char**)malloc(sizeof(result) * list->lines + 10);
	while (buf[a] != '\0')
	{
		result[line] = (char*)malloc(sizeof(result[line]) * list->columns);
		column = 0;
		while (buf[a] != '\n')
		{
			result[line][column] = buf[a];
			a++;
			column++;
		}
		a++;
		result[line][column] = '\0';
		line++;
	}
	result[line] = NULL;
	return (result);
}

/*
 ** Read argument then return list after call creations list functions
 ** File descriptor which return -1 are is closed
 */

t_list	*ft_fd(char *str)
{
	int		fd;
	int		ret;
	t_list	*list;
	char	buf[BUF_SIZE + 1];

	list = NULL;
	fd = open(str, O_RDONLY);
	if (errno == ENOENT)
	{
		close(fd);
		return (0);
	}
	else
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		if (ft_error_first_line(buf))
			list = ft_create_elem(buf);
		else
			list = ft_create_elem(NULL);
	}
	close(fd);
	return (list);
}

/*
 ** Main creation list functions, fill each elements of main t_list structure
 ** with 'a' iterate on 'lines' for recuperate number of lines in the map before
 ** being turned to an int by ft_atoi
 ** Also, we do a secure malloc there with + 20
 */

t_list	*ft_build_list(t_list *list, char *buf, int a)
{
	int	columns;

	columns = 0;
	while (buf[a + 4 + columns] != '\n')
		++columns;
	list->columns = columns;
	list->next = NULL;
	list->empty = buf[a];
	list->obs = buf[a + 1];
	list->full = buf[a + 2];
	if (ft_error_check_line(buf) && ft_error_compare_lines(buf, list) &&
			ft_error_test_content(list, buf, a + 4))
		list->data = ft_data(buf, list, a + 4);
	else
		list->data = NULL;
	return (list);
}

t_list	*ft_create_elem(char *buf)
{
	int		a;
	char	*lines;
	t_list	*new_elem;

	a = 0;
	new_elem = (t_list*)malloc(sizeof(new_elem) + 20);
	if (!buf)
		new_elem->empty = '\0';
	else
	{
		lines = (char*)malloc(sizeof(lines) * 5);
		while (buf[a] >= '0' && buf[a] <= '9')
		{
			lines[a] = buf[a];
			++a;
		}
		lines[a] = '\0';
		new_elem->lines = ft_atoi(lines);
		new_elem = ft_build_list(new_elem, buf, a);
	}
	return (new_elem);
}

/*
 ** This function is the creation of main list with arguments
 ** we return the 'first_elem' there for make next operations easilier
 */

t_list	*ft_make_list(int ac, char **av)
{
	int		a;
	t_list	*first_elem;
	t_list	*elem;

	a = 1;
	if (ac == a)
	{
		first_elem = ft_stdin();
		elem = first_elem;
	}
	else
	{
		while (!(ft_fd(av[a])))
		{
			a++;
			if (a >= ac)
				return (0);
		}
		first_elem = ft_fd(av[a]);
		elem = first_elem;
		++a;
		while (a < ac)
		{
			if (ft_fd(av[a]))
			{
				elem->next = ft_fd(av[a]);
				elem = elem->next;
			}
			++a;
		}
	}
	return (first_elem);
}
