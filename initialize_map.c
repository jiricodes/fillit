/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:57:45 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/03 15:58:26 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	init_map(t_map *map, int size)
{
	int i;

	i = 0;
	MS = size;
	if (!(map->tile = (t_tile*)malloc(sizeof(t_tile) * size * size)))
		return (-1);
	while (i < size * size)
	{
		MV = '.';
		MX = i / size;
		MY = i % size;
		i = i + 1;
	}
	return (0);
}

int init_bmap(t_bmap *map, int size)
{
	int i;
	int one;

	i = 0;
	MS = size;
	if (!(map->lines = (int*)malloc(sizeof(int) * size)))
		return (-1);
	while (i < size)
	{
		one = set_bit(one, i);
		i = i + 1;
	}
	i = 0;
	while (i < size)
	{
		map->lines[i] = one;
		i = i + 1;
	}
	return (0);
}

int	copy_bmap(t_bmap *dst, t_bmap *src)
{
	int		i;

	i = 0;
	if (!dst)
		init_bmap(dst, src->size);
	else if (src->size != dst->size)
		return (-1);
	while (i < dst->size)
	{
		dst->lines[i] = src->lines[i];
		i = i + 1;
	}
	return (0);
}

void del_bmap(t_bmap *map)
{
	free(map->lines);
	map = NULL;
}
