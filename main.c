/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:54:39 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/06 18:43:48 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Main
*/

int		main(int argc, char **argv)
{
	int		t_cnt;
	t_tetr	**tetros;
	int		size;
	t_map	map_res;
	t_bmap	map;
	int		i;

	t_cnt = 0;
	if (argc == 2)
	{
		if (!(tetros = (t_tetr **)malloc(26 * sizeof(t_tetr *))))
			ft_puterr(-1);
		get_input(argv[1], tetros, &t_cnt);
		if (t_cnt > 26 || t_cnt < 1)
			ft_puterr(-1);
		size = ft_min_sqrt(t_cnt * 4);
		init_bmap(&map, size);
		init_map(&map_res, size);
		while (not_placed_tetr(tetros))
		{
			i = place_tetr_bmap(&map, tetros);
			if (not_placed_tetr(tetros))
			{
				size = size + 1;
				del_bmap(&map);
				init_bmap(&map, size);
				free(map_res.tile);
				init_map(&map_res, size);
				reset_tetriminos(tetros, t_cnt);
				continue ;
			}
		}
		tetr_to_map(&map_res, tetros);
		print_map(&map_res);
	}
	else
		ft_puterr(0);
	return (0);
}
