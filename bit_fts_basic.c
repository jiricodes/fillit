/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_fts_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:37:50 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/02 21:40:55 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int is_bit_set(int x, int i)
{
	int mask;

	mask = 1 << i;
	return (mask & x);
}

int set_bit(int x, int i)
{
	int mask;

	mask = 1 << i;
	return (mask | x);
}

int clear_bit(int x, int i)
{
	int mask;

	mask = 1 << i;
	return ((~mask) & x);
}
