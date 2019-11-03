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
		tetr[i]->placed = 0;
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
	t_bmap map;
	int size;
	int i;
	int r1;
	int r2;
	int r3;
	t_tetr	**tetrimino;
	t_tetr	**originals;
	t_map	map_res;
	int		ret;
	int		rng;
	int		c;
	int		maxc;

	if (ac != 2)
	{
		printf("\033[1;31mWrong amount of arguments. Please select only one positive numerical value as an argument.\033[0m\n");
	}

	maxc = ft_atoi(av[1]);

	if (ac == 2 && maxc > 0)
	{
		if (maxc > 52)
			return(-1);
		srand(time(0));
		if (!(originals = (t_tetr**)malloc(sizeof(t_tetr*)*19)))
			return (-1);
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
		printf("Created tetriminos:\n");
		while (c < maxc)
		{
			rng = rand() % 19;
			copy_tetrimino(tetrimino[c], originals[rng]);
			if (c < 26)
				tetrimino[c]->name = c + 65;
			else if (c < 52)
				tetrimino[c]->name = c + 72;
			printf("\033[1;31m'%c'\033[0m\n", tetrimino[c]->name);
			print_tetrimino_bmap(tetrimino[c]);
			printf("\n");
			tetrimino[c]->placed = 0;
			c = c + 1;
		}
		printf("\n");
		size = ft_min_sqrt(maxc * 4) + 2;
		printf("Smalles ever possible square for %d tetriminos is %dx%d\n", maxc, size, size);
		init_bmap(&map, size);
		init_map(&map_res, size);
		printf("\n");
		c = 0;
		while (c < maxc)
		{
			printf("Sending shit %d\n", c);
			i = place_tetr_bmap(&map, tetrimino[c]);
			if (i >= map.size * map.size)
			{
				printf("\033[1;31mFailed to place tetrimino no. %d\033[0m\n", c);
				break ;
			}
			/*place it here to t_map*/
			tetr_to_bmap(&map, tetrimino[c], i);
			tetr_to_map(&map_res, tetrimino[c], map_res.tile[i].loc.x, map_res.tile[i].loc.y);
			print_bmap(&map);
			c = c + 1;
		}
		printf("\nSolution\n");
		print_map(&map_res);
		printf("\n-------------------------\n");
		// printf("\n");
		// map.lines[0] = 3;
		// map.lines[1] = 43;
		// map.lines[2] = 27;
		// map.lines[3] = 11;
		// map.lines[4] = 111;

		// printf("\n");
		// print_bmap(&map);
		// printf("\n");
		// r1 = rule_one(&map);
		// r2 = rule_two(&map);
		// r3 = rule_three(&map);
		// printf("Rule 1 score:\t%d\n",r1);
		// printf("Rule 1 score:\t%d\n",r2);
		// printf("Rule 3 score:\t%d\n",r3);
		// printf("Total:\t\t%d\n",r1+r2+r3);
	}
	return (0);
}