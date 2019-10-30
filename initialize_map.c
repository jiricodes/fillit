/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:57:45 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/30 17:05:08 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	init_map(t_map *map, int size)
{
	int i;

	i = 0;
	map->size = size;
	if (!(map->tile = (t_tile*)malloc(sizeof(t_tile) * size * size)))
		return (-1);
	while (i < size * size)
	{
		map->tile[i].value = '.';
		map->tile[i].loc.x = i / size;
		map->tile[i].loc.y = i % size;
		i = i + 1;
	}
	return (0);
}