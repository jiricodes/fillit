/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:03:05 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/30 18:59:14 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if ((x + TX) < 0 || (x + TX) > MS || (y + TY) < 0 || (y + TY) > MS)
			return (-1);
		while (!(MX == x + TX && MY == y + TY))
			i = i + 1;
		MV = TN;
		j = j + 1;
	}
	return (0);
}