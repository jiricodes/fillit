/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:53:35 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/01 17:33:03 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	check_tetrimino(t_tetr *tetrimino, t_map *map, int i)
{
	int j;

	j = 0;
	if (TT[1].y == -2 && MT[i - 1].value == '.' && MT[i - 2].value == '.')
	{
		tetrimino->spec = 1;
		return (-1);
	}
	if ((TT[1].y == -1 || TT[2].y == -1) && MT[i - 1].value == '.' \
		&& MT[i - 1 + MS].value == '.')
	{
		tetrimino->spec = 1;
		return (-1);
	}
	tetrimino->spec = 0;
	return (1);
}

int	check_space(t_map *map, int org, t_tetr *tetrimino, int skip)
{
	int i;
	int j;

	i = org;
	j = 0;
	while (j < 4)
	{
		while (!(MX == map->tile[org].loc.x + TX && MY == map->tile[org].loc.y + TY))
		{
			i = i + 1;
			if (i >= MS * MS)
			{
				if (map->tile[org].loc.x + TX < 0 || map->tile[org].loc.y + TY < 0)
					return (-1);
				return (-3);
			}
		}
		if (MV != '.')
			return (-1);
		j = j + 1;
	}
	if (skip == 0 && check_tetrimino(tetrimino, map, org) == -1)
			return (-2);
	return (0);
}