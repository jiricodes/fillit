/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:54:39 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/05 14:22:14 by asolopov         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int		t_cnt;
	t_tetr	**tetros;
	int		size;
	t_map	map_res;
	t_bmap	map;
	int		c;
	int		i;

	t_cnt = 0;
	if (argc == 2)
	{
		if (!(tetros = (t_tetr **)malloc(26 * sizeof(t_tetr *) + 1)))
			ft_puterr(-1);
		get_input(argv[1], tetros, &t_cnt);
		size = ft_min_sqrt(t_cnt * 4);
		init_bmap(&map, size);
		init_map(&map_res, size);
		c = 0;
		while (tetros[c] != NULL)
		{
			i = place_tetr_bmap(&map, tetros, c, c);
			if (i == -1)
			{
				size = size + 1;
				del_bmap(&map);
				init_bmap(&map, size);
				free(map_res.tile);
				init_map(&map_res, size);
				reset_tetriminos(tetros, t_cnt);
				c = 0;
				continue ;
			}
			tetr_to_bmap(&map, tetros[c], i);
			tetr_to_map(&map_res, tetros[c], map_res.tile[i].loc.x, map_res.tile[i].loc.y);
			c++;
		}
		print_map(&map_res);
	}
	else
		ft_puterr(0);
	return (0);
}
