/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:58:31 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/06 17:03:01 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Copies tetrimino t2 to t1. Currently not in use.
*/

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

/*
** Places given tetrimino on 4x4 map and sends it to the print function
*/

void	print_tetrimino_bmap(t_tetr *tetrimino)
{
	t_bmap	map;
	int		i;
	int		ret;

	i = 0;
	init_bmap(&map, 4);
	while (i < 16)
	{
		ret = check_space(&map, i, tetrimino);
		if (ret)
		{
			tetr_to_bmap(&map, tetrimino, i);
			break ;
		}
		i = i + 1;
	}
	print_bmap(&map);
	free(map.lines);
}

/*
** Resets tetriminos' placement value
*/

void	reset_tetriminos(t_tetr **tetrimino, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		tetrimino[i]->placed = -1;
		i = i + 1;
	}
}

/*
** Counts amount of NOT placed tetriminos
*/

int		not_placed_tetr(t_tetr **tetrimino)
{
	int ti;
	int res;

	ti = 0;
	res = 0;
	while (tetrimino[ti] != NULL)
	{
		if (TIP == -1)
			res++;
		ti++;
	}
	return (res);
}
