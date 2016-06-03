/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:42:09 by aoudin            #+#    #+#             */
/*   Updated: 2016/06/03 19:54:01 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_valid_tminos(char *str)
{
	int		i;
	int		touch;

	i = 0;
	touch = 0;
	while ((!(str[i] == '\n' && str[i + 1] == '\n')) && str[i])
	{
		if ((str[i + 1] == '#') && (str[i] == '#'))
			touch++;
		if ((str[i - 1] == '#') && (str[i] == '#'))
			touch++;
		if ((str[i + 5] == '#') && (str[i] == '#'))
			touch++;
		if ((str[i - 5] == '#') && (str[i] == '#'))
			touch++;
		i++;
	}
	printf("touch == %d\n", touch);
	if (touch < 6)
		return (0);
	else
		return (1);
}

int			ft_height(t_lista *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (lst->tetri[i] != 0)
			j++;
		i++;
	}
	return (j);
}

t_lista		*ft_create_elem(t_lista **list, int *nb, int count)
{
	t_lista	*elem;
	int		i;
	int		rank;

	i = 0;
	rank = 0;
	elem = *list;
	if (!(elem = (t_lista*)malloc(sizeof(t_lista))))
		return (0);
	while (i < 4)
	{
		elem->tetri[i] = nb[i];
		i++;
	}
	while (rank <= count)
	{
		elem->rank = rank;
		rank++;
	}
	elem->spot = 0;
	elem->height = ft_height(elem);
	elem->next = NULL;
	return (elem);
}

void	ft_store(char *buf, t_lista **lst, int count)
{
	int		i;
	int		j;
	int		nb[4];

	i = 0;
	j = 0;
	while (i < 20)
	{
		nb[j] = 0;
		while (((i + 1) % 5) != 0)
		{
			if (buf[i] == '#')
			{
				nb[j] = nb[j] + (1 << (4 - (i + 1) % 5));
			}
			i++;
		}
		i++;
		j++;
	}
	j = 0;
	while (j < 4)
	{
		printf("nb[%d] == %d\n", j, nb[j]);
		j++;
	}
	ft_list(nb, lst, count);
//	return (ft_list(nb, lst, count));
}

void	ft_list(int *nb, t_lista **lst, int count)
{
	t_lista	*tmp;

	if (lst && *lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(lst, nb, count);
	}
	else
	{
		tmp = *lst;
		*lst = ft_create_elem(lst, nb, count);
	}
/*	while (count > 0)
	{
		*lst = ft_create_elem(lst, nb);
		count--;
	}
//	return (*lst); */
}
