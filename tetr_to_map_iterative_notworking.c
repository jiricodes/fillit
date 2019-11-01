/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_to_map_iterative_notworking.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:03:05 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/01 17:35:58 by jnovotny         ###   ########.fr       */
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

int	tetro_not_placed(t_tetr **tetrimino, int count)
{
	int i;
	int c;

	i = 0;
	count = 0;
	while (i < count)
	{
		if (tetrimino[i]->placed == 0)
			c = c + 1;
		i = i + 1;
	}
	return (c);
}

int	speacial_tetro(t_tetr **tetrimino, int count)
{
	int i;
	int c;

	i = 0;
	count = 0;
	while (i < count)
	{
		if (tetrimino[i]->spec == 1)
			c = c + 1;
		i = i + 1;
	}
	return (c);
}

int		place_tetriminos(t_map *map, t_tetr **tetrimino, int count)
{
	int	res;
	int c;
	int	i;
	int ret;
	int spec;
	int skip;

	res = 0;
	c = 0;
	spec = 0;
	skip = 0;
	while (c < count)
	{
		if (tetrimino[c]->placed == 0)
		{
			i = 0;
			while (i < MS * MS)
			{
				ret = check_space(map, i, tetrimino[c], 1);
				if (ret == -2)
				{
					break;
				}
				else if (ret == 0)
				{
					tetr_to_map(map, tetrimino[c], MX, MY);
					res = res + 1;
					c = -1;
					spec = 0;
					print_map(map);
					printf("\n---------------------------------------->\n");
					break ;
				}
				i = i + 1;
			}
		}
		c = c + 1;
		if (speacial_tetro(tetrimino, count) == tetro_not_placed(tetrimino, count) && ret != -3)
		{
			skip = 1;
			c = 0;
		}
	}
	return (res);
}