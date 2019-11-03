/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:03:05 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/03 17:15:42 by jnovotny         ###   ########.fr       */
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

// int	tetro_not_placed(t_tetr **tetrimino, int count)
// {
// 	int i;
// 	int c;

// 	i = 0;
// 	count = 0;
// 	while (i < count)
// 	{
// 		if (tetrimino[i]->placed == 0)
// 			c = c + 1;
// 		i = i + 1;
// 	}
// 	return (c);
// }

// int	speacial_tetro(t_tetr **tetrimino, int count)
// {
// 	int i;
// 	int c;

// 	i = 0;
// 	count = 0;
// 	while (i < count)
// 	{
// 		if (tetrimino[i]->spec == 1)
// 			c = c + 1;
// 		i = i + 1;
// 	}
// 	return (c);
// }

// t_map		place_tetriminos(t_map *map, t_tetr **tetrimino, int count)
// {
// 	t_map	best;
// 	int		i;
// 	int		ret;
// 	t_map	res;
// 	int		c;
// 	init_map(&best, MS);
// 	init_map(&res, MS);
// 	c = 0;
// 	while (c < count)
// 	{
// 		while (tetrimino[c]->placed == 1)
// 			c = c + 1;
// 		i = 0;
// 		while (i < MS * MS)
// 		{
// 			ret = check_space(map, i, tetrimino[c], 1);
// 			if (ret == 0)
// 			{
// 				tetr_to_map(map, tetrimino[c], MX, MY);
// 				res = place_tetriminos(map, tetrimino, count);
// 				break ;
// 			}
// 			i = i + 1;
// 		}
// 		best = compare_map(map, res); /* Create map compare */
// 		free (res.tile);
// 		c = c + 1;
		
// 	}
// 	return (best);
// }

int 	tetr_to_bmap(t_bmap *map, t_tetr *tetrimino, int position)
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

int		place_tetr_bmap(t_bmap *map, t_tetr *tetrimino)
{
	int i;
	t_bmap res;
	int best;
	int besti;
	int ret;

	i = 0;
	best = 0;
	while (i < MS * MS)
	{
		printf("i = %d | ",i);
		ret = check_space(map, i,tetrimino);
		printf("ret = %D\n", ret);
		if (ret)
		{
			init_bmap(&res, map->size);
			copy_bmap(&res, map);
			tetr_to_bmap(&res, tetrimino, i);
			printf("Evaluating %d\n", i);
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
			printf("Best (%d) @ %d\n", best, besti);
			print_bmap(&res);
			printf("\n");
			del_bmap(&res);
		}
		i = i + 1;
	}
	return(besti); /*if besti == MS*MS then the tetrimino cannot be placed! */
}
