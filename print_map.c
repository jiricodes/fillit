/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:02:26 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/03 14:23:38 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < MS * MS)
	{
		ft_putchar(MV);
		if (MY == MS - 1)
			ft_putchar('\n');
		i = i + 1;
	}
}

void	print_bmap(t_bmap *map)
{
	int i;
	int j;

	i = 0;
	while (i < MS)
	{
		j = 0;
		while (j < MS)
		{
			if (!(is_bit_set(map->lines[i], j)))
				ft_putchar('#');
			else
				ft_putchar('.');
			j = j + 1;
		}
		if (i + 1 < MS)
			ft_putchar('\n');
		i = i + 1;
	}
}