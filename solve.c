/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:53:35 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/07 10:27:57 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		check_space(t_bmap *map, int org, t_tetr *tetrimino)
{
	int i;
	int j;
	int k;

	i = org / MS;
	k = org % MS;
	j = 0;
	while (j < 4)
	{
		if (i + TX >= MS || k + TY >= MS || k + TY < 0)
			return (0);
		if (!IBS(ML[i + TX], k + TY))
			return (0);
		j = j + 1;
	}
	return (1);
}

/*
** Checks the whole line and returns 0 if full
*/

int		check_line(t_bmap *map, int i)
{
	int mask;
	int line;

	mask = 0;
	line = ML[i / MS];
	return (mask | line);
}

/*
** Checks if a given empty is singled out
*/

int		check_neighb(t_bmap *map)
{
	int i;
	int res;
	int empty;

	i = 0;
	res = 0;
	empty = 0;
	while (i < MS * MS)
	{
		if (IBS(ML[i / MS], i % MS) && i / MS + 1 < MS)
		{
			if (!IBS(ML[i / MS + 1], i % MS) && !IBS(ML[i / MS], i % MS - 1)\
				&& !IBS(ML[i / MS], i % MS + 1))
				res = res + 1;
			empty = empty + 1;
		}
		if (IBS(ML[i / MS], i % MS) && i / MS + 1 == MS)
		{
			if (!IBS(ML[i / MS], i % MS - 1) && !IBS(ML[i / MS], i % MS - 1))
				res = res + 1;
			empty = empty + 1;
		}
		i = i + 1;
	}
	return (empty - res);
}

/*
**	Neighbours vs LeftTetrimminos logical function
*/

int		is_skip(t_bmap *map, t_tetr **tetrimino)
{
	if (MS > 5)
		if (not_placed_tetr(tetrimino) * 4 > check_neighb(map))
			return (1);
	return (0);
}
