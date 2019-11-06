/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:03:05 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/06 18:34:54 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Maybe change to receive index instad of coords
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
			while (!(MX == map->tile[TIP].loc.x + TIX && MY == map->tile[TIP].loc.y + TIY))
				i = i + 1;
			MV = TIN;
			j = j + 1;
		}
		ti++;
	}
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

// int		place_tetr_bmap(t_bmap *map, t_tetr **tetrimino, int ti, int org)
// {
// 	int		i;
// 	t_bmap	res;
// 	int		best;
// 	int		besti;
// 	int		ret;
// 	int		k = 0;

// 	i = 0;
// 	best = 0;
// 	besti = -1;
// 	while (i < MS * MS)
// 	{
// 		ret = check_space(map, i, tetrimino[ti]);
// 		if (ret == 1)
// 		{
// 			init_bmap(&res, map->size);
// 			copy_bmap(&res, map);
// 			tetr_to_bmap(&res, tetrimino[ti], i);
// 			if (tetrimino[ti + 1] != NULL)
// 			{
// 				ret = place_tetr_bmap(&res, tetrimino, ti + 1, org);
// 				if (ret == -1)
// 				{
// 					i = i + 1;
// 					del_bmap(&res);
// 					continue ;
// 				}
// 				tetr_to_bmap(&res, tetrimino[ti + 1], ret);
// 			}
// 			if (best == 0)
// 			{
// 				best = map_score(&res);
// 				besti = i;
// 			}
// 			else if (best > map_score(&res))
// 			{
// 				best = map_score(&res);
// 				besti = i;
// 			}
// 			del_bmap(&res);
// 		}
// 		i = i + 1;
// 	}
// 	return (besti);
// }

int		place_tetr_bmap(t_bmap *map, t_tetr **tetrimino)
{
	int		i;
	t_bmap	res;
	int		ret;
	int		retn;
	int		j;

	j = 0;
	while (tetrimino[j] != NULL)
	{
		if (tetrimino[j]->placed != -1)
		{
			j = j + 1;
			continue ;
		}
		i = 0;
		while (i < MS * MS)
		{
			if (check_line(map, i) == 0)
			{
				i = (i / MS) * MS + MS;
				continue ;
			}
			ret = check_space(map, i, tetrimino[j]);
			if (ret == 1)
			{
				init_bmap(&res, map->size);
				copy_bmap(&res, map);
				tetr_to_bmap(&res, tetrimino[j], i);
				tetrimino[j]->placed = i;
				retn = place_tetr_bmap(&res, tetrimino);
				if (retn == 1)
					break ;
				del_bmap(&res);
			}
			i = i + 1;
		}
		if (i == MS * MS)
		{
			tetrimino[j]->placed = -1;
			j = j + 1;
			continue ;
		}
		tetrimino[j]->placed = i;
		return (1);
	}
	if (not_placed_tetr(tetrimino) == 0)
		return (1);
	return (-2);
}
