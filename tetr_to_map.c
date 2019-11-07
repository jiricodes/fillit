/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:03:05 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/07 11:29:29 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Places all tetriminos to the result map
*/

int		tetr_to_map(t_map *map, t_tetr **tetrimino)
{
	int i;
	int j;
	int ti;

	ti = 0;
	while (tetrimino[ti] != NULL)
	{
		j = 0;
		i = 0;
		while (j < 4)
		{
			while (!(MX == MTX + TIX && MY == MTY + TIY))
				i = i + 1;
			MV = TIN;
			j = j + 1;
		}
		ti++;
	}
	print_map(map);
	return (0);
}

/*
** Places a given tetrimino to i position on BitMap
*/

int		tetr_to_bmap(t_bmap *map, t_tetr *tetrimino, int position)
{
	int i;
	int j;
	int k;

	i = position / MS;
	k = position % MS;
	j = 0;
	while (j < 4)
	{
		map->lines[i + TX] = clear_bit(map->lines[i + TX], k + TY);
		j = j + 1;
	}
	tetrimino->placed = position;
	return (1);
}

/*
** Recursive function to test all permutations
*/

int		place_tetr_bmap(t_bmap *map, t_tetr **tetrimino)
{
	int		i;
	int		ti;

	ti = 0;
	while (tetrimino[ti] != NULL)
	{
		if (TIP != -1)
		{
			ti = ti + 1;
			continue ;
		}
		if (is_skip(map, tetrimino))
			return (-1);
		i = check_index(map, tetrimino, ti);
		if (i == MS * MS)
		{
			TIP = -1;
			ti = ti + 1;
			continue ;
		}
		TIP = i;
		return (1);
	}
	return ((not_placed_tetr(tetrimino) == 0) ? 1 : -2);
}

/*
** Part of main recursive solver - Logical to next tetrimino
*/

int		check_index(t_bmap *map, t_tetr **tetrimino, int ti)
{
	int		i;
	int		ret;
	t_bmap	res;

	i = 0;
	while (i < MS * MS)
	{
		if (check_line(map, i) == 0)
		{
			i = (i / MS) * MS + MS;
			continue ;
		}
		ret = check_space(map, i, tetrimino[ti]);
		if (ret == 1)
		{
			init_cpy_bmap(&res, map, map->size);
			tetr_to_bmap(&res, tetrimino[ti], i);
			if (place_tetr_bmap(&res, tetrimino) == 1)
				break ;
			del_bmap(&res);
		}
		i = i + 1;
	}
	return (i);
}
