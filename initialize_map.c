/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:57:45 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/30 18:07:44 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	init_map(t_map *map, int size)
{
	int i;

	i = 0;
	MS = size;
	if (!(map->tile = (t_tile*)malloc(sizeof(t_tile) * size * size)))
		return (-1);
	while (i < size * size)
	{
		MV = '.';
		MX = i / size;
		MY = i % size;
		i = i + 1;
	}
	return (0);
}