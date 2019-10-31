/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_sqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:12:18 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/31 12:48:54 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the minimum int square root x of given nb where x * x >= nb.
*/

int	ft_min_sqrt(int nb)
{
	int i;

	if (nb == 0 || nb == 1)
		return (nb);
	if (nb > 1)
	{
		i = 1;
		while (i < nb / 2)
		{
			if (i * i >= nb)
				return (i);
			i = i + 1;
		}
	}
	return (0);
}
