/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:53:35 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/30 19:42:12 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	check_space(t_map *map, int org, t_tetr *tetrimino)
{
	int i;
	int j;

	i = org;
	j = 0;
	while (j < 4)
	{
		if ((MX + TX) < 0 || (MX + TX) > MS || (MY + TY) < 0 || (MY + TY) > MS)
			return (-2);
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