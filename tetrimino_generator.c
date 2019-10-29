/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_generator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:26:32 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/29 18:13:02 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>

typedef struct	s_tetrox
{
	char		*name;
	t_coords	tile1;
	t_coords	tile2;
	t_coords	tile3;
	t_coords	tile4;
}				t_tetrox;

void	initial_tetr(t_tetrox **tetr)
{
	/*
	** ####
	*/

	/*
	** #
	** #
	** #
	** #
	*/
	
	/* Z - shape */
	/* S - shape */
	/* Lightning left-right */
	/* Lightning right-left */
	/* Brick */
	/* L - shape */
	/* 
}

int main(int ac, char **av)
{
	char **line1;
	char *user_out;
	int fdw;
	int ret;
	int i;
	t_tetrox	tetriminos[19];


	/*
	** If no argument, then read given tetriminos from stdin and save to a file
	*/

	if (ac == 1)
	{
		if (!(line1 = (char**)malloc(sizeof(char*) * 200)))
		{
			printf("\033[1;31m");
			printf("Failed to allocate memory for *line");
			printf("\033[0m");
			return (404);
		}
		user_out = "tetriminos_stdin";
		fdw = open(user_out, O_CREAT, 0777);
		close(fdw);
		fdw = open(user_out, O_RDWR);
		if (fdw == -1)
			{
				printf("Failed to open file %s\n", user_out);
				return (-1);
			}
		i = 0;
		while ((ret = get_next_line(0, &line1[i])))
		{
			if (ret == -1)
			{
				printf("\033[1;31m");
				printf("ERROR OCCURED ret = -1!\n");
				printf("\033[0m");
				return (-1);
			}
			i = i + 1;
		}
		i = 0;
		while (line1[i])
		{
			ft_putstr_fd(line1[i], fdw);
			if (line1[i+1])
				ft_putstr_fd("\n", fdw);
			i = i + 1;
		}
		i = 0;
		while (line1[i])
		{
			ft_memdel((void**)&line1[i]);
			i = i + 1;
		}
		free(line1);
		return (0);
	}

	if (ac == 2)
	{
		if (ft_atoi(av[1]) > 26 || ft_atoi(av[1]) < 1)
		{
			printf("\033[1;31m");
			printf("Wrong number of Tetriminos. Must be between 1 and 26.\n");
			printf("\033[0m");
			return (-1);
		}
		user_out = ft_strjoin("tetriminos_", av[1]);
		fdw = open(user_out, O_CREAT, 0777);
		close(fdw);
		fdw = open(user_out, O_RDWR);
		if (fdw == -1)
		{
			printf("Failed to open file %s\n", user_out);
			return (-1);
		}
		i = 0;
		while (i < ft_atoi(av[1]))
		{
			
		}
		return (0);
	}
}