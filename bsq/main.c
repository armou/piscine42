/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:59:30 by rfulop            #+#    #+#             */
/*   Updated: 2016/04/23 16:52:16 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

/* Main file role is to create main lists and permit next operations then solve it*/

/* This function had to create a char** from readed file in argument
   'lines' and 'column' are both iterators for build 'result', table with two sides
   Not sure about size of malloc there ---- MAKE TESTS ----*/

char	**ft_data(char *buf, t_list *list, int a)
{
  printf("enter ft data\n");
  int	line;
  int	column;
  char	 **result;

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
  result[line] = '\0';
  line = 0;
  //	result = ft_error_test_n(result, list);
  return (result);
}

/* Read argument then return list after call creations lists functions
   File descriptor which return -1 are is closed*/

t_list	*ft_fd(char *str)
{
  int	fd;
  int	ret;
  t_list	*list;
  char	buf[BUF_SIZE + 1];

  list = NULL;
  fd = open(str, O_RDONLY);
  if (errno == ENOENT)
    return (0);
  else
  {
    ret = read(fd, buf, BUF_SIZE);
    buf[ret] = '\0';
    if (ft_test_buf(buf, list) && ft_error_test_n(buf))
    {
      printf("Zero error\n");
      list = ft_create_elem(buf);
    }
else
      list = ft_create_elem(NULL);
  }	
  close(fd);
  return (list);
}

/* Main creation list function, fill each elements of main t_list structure
   with 'a' iterate on 'lines' for recuperate number of lines in the map before being turned
   to an int by ft_atoi
   Also, we do a secure malloc there with + 20*/

t_list		*ft_create_elem(char *buf)
{
  int	a;
  int	columns;
  char	*lines;
  t_list	*new_elem;

  a = 0;
  new_elem = (t_list*)malloc(sizeof(new_elem) + 20);
  if (!buf)
    new_elem->empty = '\0';
  else
  {
    printf("else\n");
    lines = (char*)malloc(sizeof(lines) * 5);
    while (buf[a] >= '0' && buf[a] <= '9')
    {
      lines[a] = buf[a];
      ++a;
    }
    lines[a] = '\0';
    columns = 0;
    while (buf[a + 4 + columns] != '\n')
      ++columns;
    new_elem->next = NULL;
    new_elem->lines = ft_atoi(lines);
    new_elem->columns = columns;
    new_elem->empty = buf[a];
    new_elem->obs = buf[a + 1];
    new_elem->full = buf[a + 2];
    new_elem->data = ft_data(buf, new_elem, a + 4);
  }
  return (new_elem);
}

/* This function is the creation of main list with arguments
   we return the 'first_elem' there for make next operations easilier*/

t_list		*ft_make_list(int ac, char **av)
{
  int a;
  t_list	*first_elem;
  t_list	*elem;

  a = 1;
  first_elem = ft_fd(av[a]);
  ++a;
  elem = first_elem;
  while (a < ac)
  {
    elem->next = ft_fd(av[a]);
    elem = elem->next;
    ++a;
  }
  return (first_elem);
}

int		main(int ac, char **av)
{
  int	max_side;
  int	check;
  t_list	*list;

  if (ac < 2)
    return (0);
  else
  {
    list = ft_make_list(ac, av);
    while (list)
    {
      if (!list->data)
        ft_print_list(list);
      else
      {
        max_side = 0;
        max_side = ft_max_length(list, max_side);
        if (max_side > ft_max_width(list, max_side))
          max_side = ft_max_width(list, max_side);
        check = 0;
        while (max_side >= 0 && !check)
        {
          check = ft_find_square(list, max_side, list->lines - 1, list->columns - 1);
          --max_side;
        }
      }
      list = list->next;
    }
    return (1);
  }
}
