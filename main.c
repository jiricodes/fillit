/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:54:39 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/07 12:00:17 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Main
*/

static void	initialize(t_tetr **t, char **argv, t_map *map_res, t_bmap *map)
{
	int	size;
	int t_cnt;

	t_cnt = 0;
	get_input(argv[1], t, &t_cnt);
	size = ft_min_sqrt(t_cnt * 4);
	init_bmap(map, size);
	init_map(map_res, size);
}

static void	reset_map(t_bmap *map, t_map *map_res, t_tetr **tetros)
{
	int newsize;

	newsize = map->size + 1;
	del_bmap(map);
	init_bmap(map, newsize);
	free(map_res->tile);
	init_map(map_res, newsize);
	reset_tetriminos(tetros);
}

int			main(int argc, char **argv)
{
	t_tetr	**tetros;
	int		size;
	t_map	map_res;
	t_bmap	map;

	if (argc == 2)
	{
		if (!(tetros = (t_tetr **)malloc(26 * sizeof(t_tetr *))))
			ft_puterr(-1);
		initialize(tetros, argv, &map_res, &map);
		while (not_placed_tetr(tetros))
		{
			place_tetr_bmap(&map, tetros);
			if (not_placed_tetr(tetros))
			{
				reset_map(&map, &map_res, tetros);
				continue ;
			}
		}
		tetr_to_map(&map_res, tetros);
	}
	else
		ft_puterr(0);
	return (0);
}
