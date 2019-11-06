/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:06:41 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/06 09:59:14 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Rule 1: Applies to an empty cell right of column with the empty block
** on the same or lower level
*/

int		rule_one(t_bmap *map)
{
	int i;
	int j;
	int res;

	i = 0;
	res = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if ((j > 0) && is_bit_set(map->lines[i], j) \
				&& (!is_bit_set(map->lines[i], j - 1)))
				res = res + ((MS - i) * (MS - i));
			j = j + 1;
		}
		i = i + 1;
	}
	return (res);
}

/*
** Rule 2: Applies to an empty cell above the bottom most filled
** cell in the same column
*/

int		rule_two(t_bmap *map)
{
	int i;
	int j;
	int k;
	int res;

	i = 0;
	res = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			k = 0;
			while (k + i < map->size)
			{
				if (is_bit_set(map->lines[i], j) \
					&& (!is_bit_set(map->lines[i + k], j)))
				{
					res = res + ((MS - i) * (MS - i) * (MS - i));
					break ;
				}
				k = k + 1;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return (res);
}

/*
** Rule 3: Applies to an empty cell left of column with the empty block
** on the same or lower level
*/

int		rule_three(t_bmap *map)
{
	int i;
	int j;
	int res;

	i = 0;
	res = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size - 1)
		{
			if (is_bit_set(map->lines[i], j) \
				&& (!is_bit_set(map->lines[i], j + 1)))
				res = res + ((MS - i + 1) * (MS - i + 1));
			j = j + 1;
		}
		i = i + 1;
	}
	return (res);
}
