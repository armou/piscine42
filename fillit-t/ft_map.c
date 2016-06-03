/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:09:34 by aoudin            #+#    #+#             */
/*   Updated: 2016/06/03 19:54:44 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_move_top(t_lista *list)
{
	while (list->tetri[0] == 0)
	{
		list->tetri[0] = list->tetri[1];
		list->tetri[1] = list->tetri[2];
		list->tetri[2] = list->tetri[3];
		list->tetri[3] = 0;
	}
}

void	ft_move_right(t_lista *list)
{
	while (list->tetri[0] % 2 == 0 && list->tetri[1] % 2 == 0 &&
			list->tetri[2] % 2 == 0 && list->tetri[3] % 2 == 0)
	{
		list->tetri[0] = list->tetri[0] >> 1;
		list->tetri[1] = list->tetri[1] >> 1;
		list->tetri[2] = list->tetri[2] >> 1;
		list->tetri[3] = list->tetri[3] >> 1;
	}
}

int		*ft_map(int *map)
{
	int		i;

	i = 0;
	while (i < MAP_SIZE - 1)
	{
		map[i] = MAX_INT;
		i++;
	}
	return (map);
}

int		ft_mapsize(int *map, t_lista *lst, t_datastore *vault)
{
	if (vault->sq_size == 0)
		ft_setmap(map, vault);
	if (ft_fillmap(map, lst, vault) == 0)
	{
		ft_setmap(map, vault);
		ft_mapsize(map, lst, vault);
	}
	printf("vault->sq_size == %d\n", vault->sq_size);
	return (0);
}

int		ft_put_tetri(int *map, t_lista *lst, t_datastore *vault)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j < vault->sq_size)
	{
		if ((map[lst->spot + j] & lst->tetri[j]) == 0)
			j++;
	}
	printf("j == %d\n", j);
	if (j != vault->sq_size)
		return (0);
	while (i < vault->sq_size)
	{
		map[lst->spot + i] = map[lst->spot + i] + lst->tetri[i];
		i++;
	}
	return (1);
}

int		ft_move_tetri(int *map, t_lista *lst, t_datastore *vault)
{
	int		i;

	i = 0;
	while (i < vault->sq_size)
	{
		i++;
	}
	(void)map;
	(void)lst;
	return (0);
}

int		ft_fillmap(int *map, t_lista *lst, t_datastore *vault)
{
	if (ft_put_tetri(map, lst, vault) == 1)
		return (1);
	else
		ft_move_tetri(map, lst, vault);
		return (0);
}

void	ft_setmap(int *map, t_datastore *vault)
{
	int		i;

	i = 0;
	ft_map(map);
	if (vault->sq_size == 0)
		vault->sq_size = ft_sqroot(vault->count * 4);
	else
		vault->sq_size++;
	vault->bin_value = MAX_INT - ft_power(2, vault->sq_size) + 1;
	while (vault->sq_size > i)
	{
		map[i] = vault->bin_value;
		i++;
	}
}
