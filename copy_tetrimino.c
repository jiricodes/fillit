/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:58:31 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/03 17:32:39 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	copy_tetrimino(t_tetr *t1, t_tetr *t2)
{
	int i;

	i = 0;
	t1->name = t2->name;
	t1->placed = t2->placed;
	while (i < 4)
	{
		t1->tile[i].x = t2->tile[i].x;
		t1->tile[i].y = t2->tile[i].y;
		i = i + 1;
	}
}

void	print_tetrimino_bmap(t_tetr *tetrimino)
{
	t_bmap	map;
	int		i;
	int ret;

	i = 0;
	init_bmap(&map, 4);
	while (i < 16)
	{
		ret = check_space(&map, i, tetrimino);
		if (ret)
		{
			tetr_to_bmap(&map, tetrimino, i);
			break;
		}
		i = i + 1;
	}
	print_bmap(&map);
	free(map.lines);
}

// void	print_tetrimino(t_tetr *tetrimino)
// {
// 	t_map	map;
// 	int		i;
// 	int 	ret;

// 	i = 0;
// 	init_map(&map, 4);
// 	while (i < 16)
// 	{
// 		ret = check_space(&map, i, tetrimino, 1);
// 		if (0 == ret)
// 		{
// 			tetr_to_map(&map, tetrimino, map.tile[i].loc.x, map.tile[i].loc.y);
// 			break;
// 		}
// 		i = i + 1;
// 	}
// 	print_map(&map);
// 	free(map.tile);
// }

void	reset_tetriminos(t_tetr **tetrimino, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		tetrimino[i]->placed = 0;
		i = i + 1;
	}
}