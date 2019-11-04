/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:54:39 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/30 15:40:40 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		get_input(argv);
	else
		ft_putstr("usage : don't put crap input\n");
	return (0);
}