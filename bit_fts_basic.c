/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_fts_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:37:50 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/06 09:25:50 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks whether a given bit is set (=1). Returns 0 if it's not
** otherwise it returns some value which != 0
*/

int	is_bit_set(int x, int i)
{
	int mask;

	mask = 1 << i;
	return (mask & x);
}

/*
** Sets bit in given int at positin i to 1.
*/

int	set_bit(int x, int i)
{
	int mask;

	mask = 1 << i;
	return (mask | x);
}

/*
** Clears bit in given int at position i.
*/

int	clear_bit(int x, int i)
{
	int mask;

	mask = 1 << i;
	return ((~mask) & x);
}
