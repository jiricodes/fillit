/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:53:35 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/03 18:05:40 by jnovotny         ###   ########.fr       */
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

int	check_space(t_bmap *map, int org, t_tetr *tetrimino)
{
	int i;
	int j;
	int k;
	i = org / MS;
	k = org % MS;
	j = 0;
	// if (!is_bit_set(map->lines[i], k))
	// 		return (0);
	printf("org = %d, ms = %d | i = %d | k = %d | ",org, MS, i, k);
	while (j < 4)
	{
		if (i + TX >= MS || k + TY >= MS || k + TY < 0)
			return (0);
		if (!is_bit_set(map->lines[i + TX], k + TY))
			return (0);
		j = j + 1;
	}
	return (1);
}