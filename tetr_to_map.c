/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:03:05 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/30 17:13:08 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
// int		assign_tetr_coord(t_tetr *tetrimino, int x, int y)
// {
// 	tetrimino->tile[0].x = x;
// 	tetrimino->tile[0].y = y;
// }

int		tetr_to_map(t_map *map, t_tetr *tetrimino, int x, int y)
{
	int i;
	int j;

	
	j = 0;
	i = 0;
	while (j < 4)
	{
		if ((x + tetrimino->tile[j].x) < 0 || (x + tetrimino->tile[j].x) \
			> map->size || (y + tetrimino->tile[j].y) < 0 || \
			(y + tetrimino->tile[j].y) > map->size)
			return (-1);
		while (!(map->tile[i].loc.x == x + tetrimino->tile[j].x && \
		map->tile[i].loc.y == y + tetrimino->tile[j].y))
			i = i + 1;
		map->tile[i].value = tetrimino->name;
		j = j + 1;
	}
	return (0);
}