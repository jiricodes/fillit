/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:53:35 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/30 18:10:53 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_space(t_map *map, int i, t_tetr *tetrimino)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if ((MX + TX) < 0 || (MX + TX) > MS || (MY + TY) < 0 || (MY + TY) > MS)
			return (-1);
	}
}