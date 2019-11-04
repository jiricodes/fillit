/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:37:06 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/04 14:52:24 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Returns "Map Score" based on given rules.
*/

int	map_score(t_bmap *map)
{
	int res;

	res = rule_one(map) + rule_two(map) + rule_three(map);
	return (res);
}
