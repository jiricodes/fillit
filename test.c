#include "fillit.h"
#include <stdio.h>
#include <time.h>

int	initial_tetr(t_tetr **tetr)
{
	int i;

	i = 0;
	while (i < 19)
	{
		if(!(tetr[i] = (t_tetr*)malloc(sizeof(t_tetr))))
			return (-1);
		tetr[i]->name = 'x';
		i = i + 1;
	}

	/*
	** #### "I-block H"
	*/

	
	tetr[0]->tile[0].x = 0;
	tetr[0]->tile[0].y = 0;
	tetr[0]->tile[1].x = 0;
	tetr[0]->tile[1].y = 1;
	tetr[0]->tile[2].x = 0;
	tetr[0]->tile[2].y = 2;
	tetr[0]->tile[3].x = 0;
	tetr[0]->tile[3].y = 3;

	/*
	** #### "I-block V"
	*/

	tetr[1]->tile[0].x = 0;
	tetr[1]->tile[0].y = 0;
	tetr[1]->tile[1].x = 1;
	tetr[1]->tile[1].y = 0;
	tetr[1]->tile[2].x = 2;
	tetr[1]->tile[2].y = 0;
	tetr[1]->tile[3].x = 3;
	tetr[1]->tile[3].y = 0;

	/*
	** ##
	**  ##  "Z-block H"
	*/

	tetr[2]->tile[0].x = 0;
	tetr[2]->tile[0].y = 0;
	tetr[2]->tile[1].x = 0;
	tetr[2]->tile[1].y = 1;
	tetr[2]->tile[2].x = 1;
	tetr[2]->tile[2].y = 1;
	tetr[2]->tile[3].x = 1;
	tetr[2]->tile[3].y = 2;

	/*
	**   ##
	**  ##  "S-block H"
	*/

	tetr[3]->tile[0].x = 0;
	tetr[3]->tile[0].y = 0;
	tetr[3]->tile[1].x = 0;
	tetr[3]->tile[1].y = 1;
	tetr[3]->tile[2].x = 1;
	tetr[3]->tile[2].y = -1;
	tetr[3]->tile[3].x = 1;
	tetr[3]->tile[3].y = 0;
	/*
	** 	#
	**  ##  "Z-block V"
	**	 #
	*/

	tetr[4]->tile[0].x = 0;
	tetr[4]->tile[0].y = 0;
	tetr[4]->tile[1].x = 1;
	tetr[4]->tile[1].y = 0;
	tetr[4]->tile[2].x = 1;
	tetr[4]->tile[2].y = 1;
	tetr[4]->tile[3].x = 2;
	tetr[4]->tile[3].y = 1;
	/*
	**   #
	**  ##  "S-block H"
	**	#
	*/

	tetr[5]->tile[0].x = 0;
	tetr[5]->tile[0].y = 0;
	tetr[5]->tile[1].x = 1;
	tetr[5]->tile[1].y = -1;
	tetr[5]->tile[2].x = 1;
	tetr[5]->tile[2].y = 0;
	tetr[5]->tile[3].x = 2;
	tetr[5]->tile[3].y = -1;

	/*
	** 	##
	**  ##  "O-block"
	*/

	tetr[6]->tile[0].x = 0;
	tetr[6]->tile[0].y = 0;
	tetr[6]->tile[1].x = 0;
	tetr[6]->tile[1].y = 1;
	tetr[6]->tile[2].x = 1;
	tetr[6]->tile[2].y = 0;
	tetr[6]->tile[3].x = 1;
	tetr[6]->tile[3].y = 1;

	/*
	** 	#
	**  #  "L-block 0"
	**	##
	*/

	tetr[7]->tile[0].x = 0;
	tetr[7]->tile[0].y = 0;
	tetr[7]->tile[1].x = 1;
	tetr[7]->tile[1].y = 0;
	tetr[7]->tile[2].x = 2;
	tetr[7]->tile[2].y = 0;
	tetr[7]->tile[3].x = 2;
	tetr[7]->tile[3].y = 1;

	/*
	**   #
	**   #  "J-block 0"
	**	##
	*/

	tetr[8]->tile[0].x = 0;
	tetr[8]->tile[0].y = 0;
	tetr[8]->tile[1].x = 1;
	tetr[8]->tile[1].y = 0;
	tetr[8]->tile[2].x = 2;
	tetr[8]->tile[2].y = -1;
	tetr[8]->tile[3].x = 2;
	tetr[8]->tile[3].y = 0;

	/*
	**  #
	**	### "J-block 90"
	*/

	tetr[9]->tile[0].x = 0;
	tetr[9]->tile[0].y = 0;
	tetr[9]->tile[1].x = 1;
	tetr[9]->tile[1].y = 0;
	tetr[9]->tile[2].x = 1;
	tetr[9]->tile[2].y = 1;
	tetr[9]->tile[3].x = 1;
	tetr[9]->tile[3].y = 2;

	/*
	**    #
	**	### "L-block 270"
	*/

	tetr[10]->tile[0].x = 0;
	tetr[10]->tile[0].y = 0;
	tetr[10]->tile[1].x = 1;
	tetr[10]->tile[1].y = -2;
	tetr[10]->tile[2].x = 1;
	tetr[10]->tile[2].y = -1;
	tetr[10]->tile[3].x = 1;
	tetr[10]->tile[3].y = 0;

	/*
	** 	##
	**  #  "J-block 180"
	**	#
	*/

	tetr[11]->tile[0].x = 0;
	tetr[11]->tile[0].y = 0;
	tetr[11]->tile[1].x = 0;
	tetr[11]->tile[1].y = 1;
	tetr[11]->tile[2].x = 1;
	tetr[11]->tile[2].y = 0;
	tetr[11]->tile[3].x = 2;
	tetr[11]->tile[3].y = 0;

	/*
	**  ##
	**   # "L-block 180"
	**	 #
	*/

	tetr[12]->tile[0].x = 0;
	tetr[12]->tile[0].y = 0;
	tetr[12]->tile[1].x = 0;
	tetr[12]->tile[1].y = 1;
	tetr[12]->tile[2].x = 1;
	tetr[12]->tile[2].y = 1;
	tetr[12]->tile[3].x = 2;
	tetr[12]->tile[3].y = 1;

	/*
	**	### "L-block 90"
	**  #
	*/

	tetr[13]->tile[0].x = 0;
	tetr[13]->tile[0].y = 0;
	tetr[13]->tile[1].x = 0;
	tetr[13]->tile[1].y = 1;
	tetr[13]->tile[2].x = 0;
	tetr[13]->tile[2].y = 2;
	tetr[13]->tile[3].x = 1;
	tetr[13]->tile[3].y = 0;

	/*
	**	### "J-block 270"
	**    #
	*/

	tetr[14]->tile[0].x = 0;
	tetr[14]->tile[0].y = 0;
	tetr[14]->tile[1].x = 0;
	tetr[14]->tile[1].y = 1;
	tetr[14]->tile[2].x = 0;
	tetr[14]->tile[2].y = 2;
	tetr[14]->tile[3].x = 1;
	tetr[14]->tile[3].y = 2;

	/*
	**   #
	**	### "T-block 180"
	*/

	tetr[15]->tile[0].x = 0;
	tetr[15]->tile[0].y = 0;
	tetr[15]->tile[1].x = 1;
	tetr[15]->tile[1].y = -1;
	tetr[15]->tile[2].x = 1;
	tetr[15]->tile[2].y = 0;
	tetr[15]->tile[3].x = 1;
	tetr[15]->tile[3].y = 1;

	/*
	**	### "T-block 0"
	**   #
	*/

	tetr[16]->tile[0].x = 0;
	tetr[16]->tile[0].y = 0;
	tetr[16]->tile[1].x = 0;
	tetr[16]->tile[1].y = 1;
	tetr[16]->tile[2].x = 0;
	tetr[16]->tile[2].y = 2;
	tetr[16]->tile[3].x = 1;
	tetr[16]->tile[3].y = 1;

	/*
	**  #
	**  ## "T-block 270"
	**	#
	*/
	
	tetr[17]->tile[0].x = 0;
	tetr[17]->tile[0].y = 0;
	tetr[17]->tile[1].x = 1;
	tetr[17]->tile[1].y = 0;
	tetr[17]->tile[2].x = 1;
	tetr[17]->tile[2].y = 1;
	tetr[17]->tile[3].x = 2;
	tetr[17]->tile[3].y = 0;

	/*
	**   #
	**  ##	"T-block 90"
	**	 #
	*/

	tetr[18]->tile[0].x = 0;
	tetr[18]->tile[0].y = 0;
	tetr[18]->tile[1].x = 1;
	tetr[18]->tile[1].y = -1;
	tetr[18]->tile[2].x = 1;
	tetr[18]->tile[2].y = 0;
	tetr[18]->tile[3].x = 2;
	tetr[18]->tile[3].y = 0;

	return (0);
}

int main (int ac, char **av)
{
	t_tetr	**tetrimino;
	t_tetr	**originals;
	t_map	map;
	int		i;
	int		size;
	int		ret;
	int		rng;
	int		c, cnt;
	int		maxc;
	int		minsize;
	
	if (ac == 3)
	{
		srand(time(0));
		if (!(tetrimino = (t_tetr**)malloc(sizeof(t_tetr*)*19)))
			return (-1);
		size = ft_atoi(av[2]);
		maxc = ft_atoi(av[1]);
		init_map(&map, size);
		initial_tetr(tetrimino);
		c = 0;
		while (c < maxc)
		{
			i = 0;
			rng = rand() % 19;
			tetrimino[rng]->name = c + 65;
			while (i < size * size)
			{
				ret = check_space(&map, i, tetrimino[rng]);
				if (ret == 0)
				{
					tetr_to_map(&map, tetrimino[rng], map.tile[i].loc.x, map.tile[i].loc.y);
					break ;
				}
				i = i + 1;
			}
			c = c + 1;
		}
		print_map(&map);
		free(map.tile);
	}

	if (ac == 2)
	{
		srand(time(0));
		if (!(originals = (t_tetr**)malloc(sizeof(t_tetr*)*19)))
			return (-1);
		maxc = ft_atoi(av[1]);
		if (!(tetrimino = (t_tetr**)malloc(sizeof(t_tetr*)*maxc)))
			return (-1);
		i = 0;
		while (i < maxc)
		{
			if(!(tetrimino[i] = (t_tetr*)malloc(sizeof(t_tetr))))
				return (-1);
			i = i + 1;
		}
		printf("Allocation done\n");
		initial_tetr(originals);
		c = 0;
		printf("Created tetriminos: ");
		while (c < maxc)
		{
			rng = rand() % 19;
			copy_tetrimino(tetrimino[c], originals[rng]);
			tetrimino[c]->name = c + 65;
			printf("'%c' | ", tetrimino[c]->name);
			c = c + 1;
		}
		printf("\n");
		minsize = ft_min_sqrt(maxc * 4);
		printf("Smalles ever possible square for %d tetriminos is %dx%d\n", maxc, minsize, minsize);
		while (cnt != maxc)
		{
			init_map(&map, minsize);
			c = 0;
			cnt = place_tetriminos(&map, tetrimino, maxc);
			if (cnt != maxc)
				free(map.tile);
			minsize = minsize + 1;
		}
		print_map(&map);
		printf("Fitted on map %dx%d\n", map.size, map.size);
	}
	return (0);
}