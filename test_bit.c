#include "fillit.h"
#include <stdio.h>
#include <time.h>

int main (int ac, char **av)
{
	t_bmap map;
	int size;
	int i;
	int r1;
	int r2;
	int r3;
	t_tetr	**tetrimino;
	t_map	map_res;
	int		ret;
	int		rng;
	int		c;
	int		cnt = 0;

	if (ac != 2)
	{
		printf("\033[1;31mWrong amount of arguments. Please select only one positive numerical value as an argument.\033[0m\n");
	}

	if (ac == 2)
	{
		if (!(tetrimino = (t_tetr **)malloc(27 * sizeof(t_tetr *))))
			ft_puterr(-1);
		get_input(av[1], tetrimino, &cnt);
		if (!tetrimino)
			printf("Tetriminos were not assigned\n");
		printf("Tetriminos count is %d\n", cnt);
		if (cnt > 26 || cnt < 1)
		{	
			printf("Cannot run solver with given size - %d\n", cnt);
		 	return(-1);
		}
		c = 0;
		while (c < cnt)
		{
			print_tetrimino_bmap(tetrimino[c]);
			printf("\n\n");
			c = c + 1;
		}
		size = ft_min_sqrt(cnt * 4);
		printf("Smalles ever possible square for %d tetriminos is %dx%d\n", cnt, size, size);
		init_bmap(&map, size);
		init_map(&map_res, size);
		printf("\n");
		c = 0;
		while (tetrimino[c] != NULL)
		{
			i = place_tetr_bmap(&map, tetrimino, c, c);
			if (i == -1)
			{
				printf("\033[1;31mFailed to place tetrimino no. %d\033[0m\n", c);
				size = size + 1;
				del_bmap(&map);
				init_bmap(&map, size);
				free(map_res.tile);
				init_map(&map_res, size);
				reset_tetriminos(tetrimino, cnt);
				c = 0;
				printf ("Reseted all and resized map to size = %d\n", size);
				continue ;
			}
			printf("Placing '%c' at %d[%d,%d]\n", tetrimino[c]->name, i, map_res.tile[i].loc.x,  map_res.tile[i].loc.y);
			tetr_to_bmap(&map, tetrimino[c], i);
			tetr_to_map(&map_res, tetrimino[c], map_res.tile[i].loc.x, map_res.tile[i].loc.y);
			print_bmap(&map);
			printf("\n\n");
			c = c + 1;
		}
		printf("\nSolution (%dx%d)\n", size, size);
		print_map(&map_res);
		printf("\n-------------------------\n");
		// while (1) {};
	}
	return (0);
}