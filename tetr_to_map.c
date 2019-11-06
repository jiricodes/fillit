/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:03:05 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/06 10:01:41 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Maybe change to receive index instad of coords
*/

int		tetr_to_map(t_map *map, t_tetr *tetrimino, int x, int y)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < 4)
	{
		while (!(MX == x + TX && MY == y + TY))
			i = i + 1;
		MV = TN;
		j = j + 1;
	}
	tetrimino->placed = 1;
	return (0);
}

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
	return (1);
}

int		place_tetr_bmap(t_bmap *map, t_tetr **tetrimino, int ti, int org)
{
	int		i;
	t_bmap	res;
	int		best;
	int		besti;
	int		ret;

	i = 0;
	best = 0;
	besti = -1;
	while (i < MS * MS)
	{
		ret = check_space(map, i, tetrimino[ti]);
		if (ret == 1)
		{
			init_bmap(&res, map->size);
			copy_bmap(&res, map);
			tetr_to_bmap(&res, tetrimino[ti], i);
			if (tetrimino[ti + 1] != NULL && ti + 1 < org + 4)
			{
				ret = place_tetr_bmap(&res, tetrimino, ti + 1, org);
				if (ret == -1)
				{
					i = i + 1;
					del_bmap(&res);
					continue ;
				}
				tetr_to_bmap(&res, tetrimino[ti + 1], ret);
			}
			if (best == 0)
			{
				best = map_score(&res);
				besti = i;
			}
			else if (best > map_score(&res))
			{
				best = map_score(&res);
				besti = i;
			}
			del_bmap(&res);
		}
		i = i + 1;
	}
	return (besti);
}
