/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:03:05 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/01 10:23:03 by jnovotny         ###   ########.fr       */
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
	return (0);
}

int		place_tetriminos(t_map *map, t_tetr **tetrimino, int count)
{
	int	res;
	int c;
	int	i;
	int ret;

	res = 0;
	c = 0;
	while (c < count)
	{
		i = 0;
		while (i < MS * MS)
		{
			ret = check_space(map, i, tetrimino[c]);
			if (ret == 0)
			{
				tetr_to_map(map, tetrimino[c], MX, MY);
				res = res + 1;
				break ;
			}
			i = i + 1;
		}
	c = c + 1;
	}
	return (res);
}