/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_generator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:26:32 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/30 19:50:49 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

/* CUNT */

typedef struct	s_tetrox
{
	char		*name;
	t_coords	tile[4];
}				t_tetrox;

void	initial_tetr(t_tetrox *tetr, int a, int b)
{
	/*
	** ####
	*/
	tetr[0].name = "I-block H";
	tetr[0].tile[0].x = a;
	tetr[0].tile[0].y = 0;
	tetr[0].tile[1].x = tetr[0].tile[0].x ;
	tetr[0].tile[1].y = tetr[0].tile[0].y + 1;
	tetr[0].tile[2].x = tetr[0].tile[0].x ;
	tetr[0].tile[2].y = tetr[0].tile[0].y + 2;
	tetr[0].tile[3].x = tetr[0].tile[0].x ;
	tetr[0].tile[3].y = tetr[0].tile[0].y + 3;



	tetr[1].name = "I-block V";
	tetr[1].tile[0].x = 0;
	tetr[1].tile[0].y = b;
	tetr[1].tile[1].x = tetr[1].tile[0].x + 1;
	tetr[1].tile[1].y = tetr[1].tile[0].y;
	tetr[1].tile[2].x = tetr[1].tile[0].x + 2;
	tetr[1].tile[2].y = tetr[1].tile[0].y;
	tetr[1].tile[3].x = tetr[1].tile[0].x + 3;
	tetr[1].tile[3].y = tetr[1].tile[0].y;
	
	/*
	** ##
	**  ##
	*/
	tetr[2].name = "Z-block H";
	tetr[2].tile[0].x = a;
	tetr[2].tile[0].y = b;
	tetr[2].tile[1].x = tetr[2].tile[0].x ;
	tetr[2].tile[1].y = tetr[2].tile[0].y + 1;
	tetr[2].tile[2].x = tetr[2].tile[0].x + 1;
	tetr[2].tile[2].y = tetr[2].tile[0].y + 1;
	tetr[2].tile[3].x = tetr[2].tile[0].x + 1;
	tetr[2].tile[3].y = tetr[2].tile[0].y + 2;
	/*
	**   ##
	**  ##
	*/
	tetr[3].name = "S-block H";
	tetr[3].tile[0].x = a;
	if (b > 0)
		tetr[3].tile[0].y = b;
	else
		tetr[3].tile[0].y = b + 1;
	tetr[3].tile[1].x = tetr[3].tile[0].x ;
	tetr[3].tile[1].y = tetr[3].tile[0].y + 1;
	tetr[3].tile[2].x = tetr[3].tile[0].x + 1;
	tetr[3].tile[2].y = tetr[3].tile[0].y - 1;
	tetr[3].tile[3].x = tetr[3].tile[0].x + 1;
	tetr[3].tile[3].y = tetr[3].tile[0].y;
	/*
	** 	#
	**  ##
	**	 #
	*/
	tetr[4].name = "Z-block V";
	tetr[4].tile[0].x = a;
	tetr[4].tile[0].y = b;
	tetr[4].tile[1].x = tetr[4].tile[0].x + 1;
	tetr[4].tile[1].y = tetr[4].tile[0].y;
	tetr[4].tile[2].x = tetr[4].tile[0].x + 1;
	tetr[4].tile[2].y = tetr[4].tile[0].y + 1;
	tetr[4].tile[3].x = tetr[4].tile[0].x + 2;
	tetr[4].tile[3].y = tetr[4].tile[0].y + 1;
	/*
	**   #
	**  ##
	**	#
	*/
	tetr[5].name = "S-block H";
	tetr[5].tile[0].x = a;
	if (b > 0)
		tetr[5].tile[0].y = b;
	else
		tetr[5].tile[0].y = b + 1;
	tetr[5].tile[1].x = tetr[5].tile[0].x + 1;
	tetr[5].tile[1].y = tetr[5].tile[0].y - 1;
	tetr[5].tile[2].x = tetr[5].tile[0].x + 1;
	tetr[5].tile[2].y = tetr[5].tile[0].y;
	tetr[5].tile[3].x = tetr[5].tile[0].x + 2;
	tetr[5].tile[3].y = tetr[5].tile[0].y - 1;
	/*
	** 	##
	**  ##
	*/
	tetr[6].name = "O-block";
	tetr[6].tile[0].x = a;
	tetr[6].tile[0].y = b;
	tetr[6].tile[1].x = tetr[6].tile[0].x ;
	tetr[6].tile[1].y = tetr[6].tile[0].y + 1;
	tetr[6].tile[2].x = tetr[6].tile[0].x + 1;
	tetr[6].tile[2].y = tetr[6].tile[0].y;
	tetr[6].tile[3].x = tetr[6].tile[0].x + 1;
	tetr[6].tile[3].y = tetr[6].tile[0].y + 1;
	/*
	** 	#
	**  #
	**	##
	*/
	tetr[7].name = "L-block 0";
	tetr[7].tile[0].x = a;
	tetr[7].tile[0].y = b;
	tetr[7].tile[1].x = tetr[7].tile[0].x + 1;
	tetr[7].tile[1].y = tetr[7].tile[0].y;
	tetr[7].tile[2].x = tetr[7].tile[0].x + 2;
	tetr[7].tile[2].y = tetr[7].tile[0].y;
	tetr[7].tile[3].x = tetr[7].tile[0].x + 2;
	tetr[7].tile[3].y = tetr[7].tile[0].y + 1;

	/*
	**   #
	**   #
	**	##
	*/
	tetr[8].name = "J-block 0";
	tetr[8].tile[0].x = a;
	if (b > 0)
		tetr[8].tile[0].y = b;
	else
		tetr[8].tile[0].y = b + 1;
	tetr[8].tile[1].x = tetr[8].tile[0].x + 1;
	tetr[8].tile[1].y = tetr[8].tile[0].y;
	tetr[8].tile[2].x = tetr[8].tile[0].x + 2;
	tetr[8].tile[2].y = tetr[8].tile[0].y;
	tetr[8].tile[3].x = tetr[8].tile[0].x + 2;
	tetr[8].tile[3].y = tetr[8].tile[0].y - 1;

	/*
	**  #
	**	###
	*/
	tetr[9].name = "J-block 90";
	tetr[9].tile[0].x = a;
	tetr[9].tile[0].y = b;
	tetr[9].tile[1].x = tetr[9].tile[0].x + 1;
	tetr[9].tile[1].y = tetr[9].tile[0].y;
	tetr[9].tile[2].x = tetr[9].tile[0].x + 1;
	tetr[9].tile[2].y = tetr[9].tile[0].y + 1;
	tetr[9].tile[3].x = tetr[9].tile[0].x + 1;
	tetr[9].tile[3].y = tetr[9].tile[0].y + 2;

	/*
	**    #
	**	###
	*/
	tetr[10].name = "L-block 270";
	tetr[10].tile[0].x = a;
	if (b > 1)
		tetr[10].tile[0].y = b;
	else
		tetr[10].tile[0].y = b + 2;
	tetr[10].tile[1].x = tetr[10].tile[0].x + 1;
	tetr[10].tile[1].y = tetr[10].tile[0].y - 2;
	tetr[10].tile[2].x = tetr[10].tile[0].x + 1;
	tetr[10].tile[2].y = tetr[10].tile[0].y - 1;
	tetr[10].tile[3].x = tetr[10].tile[0].x + 1;
	tetr[10].tile[3].y = tetr[10].tile[0].y;

	/*
	** 	##
	**  #
	**	#
	*/
	tetr[11].name = "J-block 180";
	tetr[11].tile[0].x = a;
	tetr[11].tile[0].y = b;
	tetr[11].tile[1].x = tetr[11].tile[0].x ;
	tetr[11].tile[1].y = tetr[11].tile[0].y + 1;
	tetr[11].tile[2].x = tetr[11].tile[0].x + 1;
	tetr[11].tile[2].y = tetr[11].tile[0].y;
	tetr[11].tile[3].x = tetr[11].tile[0].x + 2;
	tetr[11].tile[3].y = tetr[11].tile[0].y;

	/*
	**  ##
	**   #
	**	 #
	*/
	tetr[12].name = "L-block 180";
	tetr[12].tile[0].x = a;
	tetr[12].tile[0].y = b;
	tetr[12].tile[1].x = tetr[12].tile[0].x;
	tetr[12].tile[1].y = tetr[12].tile[0].y + 1;
	tetr[12].tile[2].x = tetr[12].tile[0].x + 1;
	tetr[12].tile[2].y = tetr[12].tile[0].y + 1;
	tetr[12].tile[3].x = tetr[12].tile[0].x + 2;
	tetr[12].tile[3].y = tetr[12].tile[0].y + 1;

	/*
	**	###
	**  #
	*/
	tetr[13].name = "L-block 90";
	tetr[13].tile[0].x = a;
	tetr[13].tile[0].y = b;
	tetr[13].tile[1].x = tetr[13].tile[0].x;
	tetr[13].tile[1].y = tetr[13].tile[0].y + 1;
	tetr[13].tile[2].x = tetr[13].tile[0].x;
	tetr[13].tile[2].y = tetr[13].tile[0].y + 2;
	tetr[13].tile[3].x = tetr[13].tile[0].x + 1;
	tetr[13].tile[3].y = tetr[13].tile[0].y;

	/*
	**	###
	**    #
	*/
	tetr[14].name = "J-block 270";
	tetr[14].tile[0].x = a;
	tetr[14].tile[0].y = b;
	tetr[14].tile[1].x = tetr[14].tile[0].x ;
	tetr[14].tile[1].y = tetr[14].tile[0].y + 1;
	tetr[14].tile[2].x = tetr[14].tile[0].x ;
	tetr[14].tile[2].y = tetr[14].tile[0].y + 2;
	tetr[14].tile[3].x = tetr[14].tile[0].x + 1;
	tetr[14].tile[3].y = tetr[14].tile[0].y + 2;

	/*
	**   #
	**	###
	*/
	tetr[15].name = "T-block 180";
	tetr[15].tile[0].x = a;
	if (b > 0)
		tetr[15].tile[0].y = b;
	else
		tetr[15].tile[0].y = b + 1;
	tetr[15].tile[1].x = tetr[15].tile[0].x + 1;
	tetr[15].tile[1].y = tetr[15].tile[0].y - 1;
	tetr[15].tile[2].x = tetr[15].tile[0].x + 1;
	tetr[15].tile[2].y = tetr[15].tile[0].y;
	tetr[15].tile[3].x = tetr[15].tile[0].x + 1;
	tetr[15].tile[3].y = tetr[15].tile[0].y + 1;

	/*
	**	###
	**   #
	*/
	tetr[16].name = "T-block 0";
	tetr[16].tile[0].x = a;
	tetr[16].tile[0].y = b;
	tetr[16].tile[1].x = tetr[16].tile[0].x ;
	tetr[16].tile[1].y = tetr[16].tile[0].y + 1;
	tetr[16].tile[2].x = tetr[16].tile[0].x ;
	tetr[16].tile[2].y = tetr[16].tile[0].y + 2;
	tetr[16].tile[3].x = tetr[16].tile[0].x + 1;
	tetr[16].tile[3].y = tetr[16].tile[0].y + 1;

	/*
	**  #
	**  ##
	**	#
	*/
	tetr[17].name = "T-block 270";
	tetr[17].tile[0].x = a;
	tetr[17].tile[0].y = b;
	tetr[17].tile[1].x = tetr[17].tile[0].x + 1;
	tetr[17].tile[1].y = tetr[17].tile[0].y;
	tetr[17].tile[2].x = tetr[17].tile[0].x + 1;
	tetr[17].tile[2].y = tetr[17].tile[0].y + 1;
	tetr[17].tile[3].x = tetr[17].tile[0].x + 2;
	tetr[17].tile[3].y = tetr[17].tile[0].y;

	/*
	**   #
	**  ##
	**	 #
	*/
	tetr[18].name = "T-block 90";
	tetr[18].tile[0].x = a;
	if (b > 0)
		tetr[18].tile[0].y = b;
	else
		tetr[18].tile[0].y = b + 1;
	tetr[18].tile[1].x = tetr[18].tile[0].x + 1;
	tetr[18].tile[1].y = tetr[18].tile[0].y - 1;
	tetr[18].tile[2].x = tetr[18].tile[0].x + 1;
	tetr[18].tile[2].y = tetr[18].tile[0].y;
	tetr[18].tile[3].x = tetr[18].tile[0].x + 2;
	tetr[18].tile[3].y = tetr[18].tile[0].y;
}

void	print_tetrimino(t_tetrox *tetr)
{
	printf("\033[1;31m");
	printf("%s\n", tetr->name);
	printf("\033[0m");
	printf("Tile 1\t%d | %d\n",tetr->tile[0].x, tetr->tile[0].y);
	printf("Tile 2\t%d | %d\n",tetr->tile[1].x, tetr->tile[1].y);
	printf("Tile 3\t%d | %d\n",tetr->tile[2].x, tetr->tile[2].y);
	printf("Tile 4\t%d | %d\n",tetr->tile[3].x, tetr->tile[3].y);
}

int main(int ac, char **av)
{
	char **line1;
	char *block[4];
	char *user_out;
	int fdw;
	int ret;
	int i, j, k, l;
	int a, b, x;
	t_tetrox	*tetriminos;


	if (ac == 2)
	{
		if (ft_atoi(av[1]) > 26 || ft_atoi(av[1]) < 1)
		{
			printf("\033[1;31m");
			printf("Wrong number of Tetriminos. Must be between 1 and 26.\n");
			printf("\033[0m");
			return (-1);
		}
		user_out = ft_strjoin("tetrimino_testfile_", av[1]);
		fdw = open(user_out, O_CREAT, 0777);
		close(fdw);
		fdw = open(user_out, O_RDWR);
		if (fdw == -1)
		{
			printf("Failed to open file %s\n", user_out);
			return (-1);
		}
		if (!(tetriminos = (t_tetrox*)malloc(sizeof(t_tetrox) * 20)))
		{
			printf("\033[1;31m");
			printf("Couldn't allocate memory for Tetriminos!\n");
			printf("\033[0m");
			return (-1);
		}
		a = 0;
		b = 0;
		setlocale(LC_CTYPE,"UTF-8");
		initial_tetr(tetriminos, a, b);
		printf("\033[1;31m");
		printf("%lc\n", 0x2588);
		printf("\033[0m");
		i = 0;
		while (i < ft_atoi(av[1]))
		{
			j = 0;
			while (j < 4)
			{
				ft_strdel(&block[j]);
				if (j < 3)
					block[j] = ft_strdup("....\n");
				else
					block[j] = ft_strdup("....");
				j++;
			}
			x = rand() % 19;
			j = 0;
			while (j < 4)
			{
				k = 0;
				while (k < 4)
				{
					l = 0;
					while (l < 4)
						{
							if (tetriminos[x].tile[l].x == j && tetriminos[x].tile[l].y == k)
								block[j][k] = '#';
							l++;
						}
					k++;
				}
				j++;
			}
			j = 0;
			while (j < 4)
			{
				printf("%s", block[j]);
				ft_putstr_fd(block[j], fdw);
				j++;
			}
			if ((i + 1) < ft_atoi(av[1]))
			{
				printf("\n\n");
				ft_putstr_fd("\n\n", fdw);
			}
			i++;
		}
		return (0);
	}
}
