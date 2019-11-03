/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:37:06 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/03 14:41:44 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
**	Selects and returns the better of two maps
*/

int	map_score(t_bmap *map)
{
	int res;

	res = rule_one(map) + rule_two(map) + rule_three(map);
	return (res);
}
