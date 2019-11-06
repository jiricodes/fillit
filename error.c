/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:47:16 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/06 10:47:29 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Display error message, exit the program
*/

void	ft_puterr(int x)
{
	if (x == 0)
	{
		ft_putstr("usage: ./fillit file_with_tetriminoes\n");
		exit(0);
	}
	if (x == -1)
	{
		ft_putstr("error\n");
		exit(0);
	}
}
