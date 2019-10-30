/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:02:26 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/30 18:01:57 by jnovotny         ###   ########.fr       */
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
