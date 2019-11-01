/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:53:35 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/01 11:54:22 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	check_tetrimino(t_tetr *tetrimino, t_map *map, int i)
{
	int j;

	j = 0;
	if (TT[1].y == -2 && MT[i - 1].value == '.' && MT[i - 2].value == '.')
		return (-1);
	if ((TT[1].y == -1 || TT[2].y == -1) && MT[i - 1].value == '.' \
		&& MT[i - 1 + MS].value == '.')
		return (-1);
	return (1);
}

int	check_space(t_map *map, int org, t_tetr *tetrimino)
{
	int i;
	int j;

	i = org;
	j = 0;
	// if (-1 == check_tetrimino(tetrimino, map, org))
	// 	return (-2);
	while (j < 4)
	{
		while (!(MX == map->tile[org].loc.x + TX && MY == map->tile[org].loc.y + TY))
		{
			i = i + 1;
			if (i >= MS * MS)
				return (-3);
		}
		if (MV != '.')
			return (-1);
		j = j + 1;
	}
	return (0);
}