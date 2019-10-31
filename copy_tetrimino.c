/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:58:31 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/31 14:32:23 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	copy_tetrimino(t_tetr *t1, t_tetr *t2)
{
	int i;

	i = 0;
	t1->name = t2->name;
	while (i < 4)
	{
		t1->tile[i].x = t2->tile[i].x;
		t1->tile[i].y = t2->tile[i].y;
		i = i + 1;
	}
}
