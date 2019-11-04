/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:38:38 by asolopov          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/11/04 12:32:42 by asolopov         ###   ########.fr       */
=======
/*   Updated: 2019/11/04 14:10:37 by asolopov         ###   ########.fr       */
>>>>>>> bits-and-scores
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

<<<<<<< HEAD
int		get_coords(char *buf, int tetr_cnt, t_tetr **tetros)
=======
int		store_input(char *buf, int tetr_cnt, t_tetr **tetros)
>>>>>>> bits-and-scores
{
	int cnt;
	int head;
	int tl_cnt;

	cnt = 0;
	tl_cnt = 0;
<<<<<<< HEAD
	tetros[tetr_cnt] = (t_tetr *)malloc(sizeof(t_tetr));
	tetros[tetr_cnt]->name = tetr_cnt + 65;
	tetros[tetr_cnt]->placed = 0;
	printf("Tetro %d has a name %c and placed value of %d\n", tetr_cnt, tetros[tetr_cnt]->name, tetros[tetr_cnt]->placed);
=======
	if (!(tetros[tetr_cnt] = (t_tetr *)malloc(sizeof(t_tetr))))
		return (-1);
	tetros[tetr_cnt]->name = tetr_cnt + 65;
	tetros[tetr_cnt]->placed = 0;
>>>>>>> bits-and-scores
	while (buf[cnt] != '\0')
	{
		while (buf[cnt] != '#' && buf[cnt] != '\0')
			cnt++;
		if (buf[cnt] == '#' && tl_cnt == 0)
		{
			tetros[tetr_cnt]->tile[tl_cnt].x = 0;
			tetros[tetr_cnt]->tile[tl_cnt].y = 0;
			head = cnt;
<<<<<<< HEAD
			printf("Head is located at: %d, Current position is: %d\n", head, cnt);
			printf("Tile %d| X is: %d, Y is: %d\n", tl_cnt, tetros[tetr_cnt]->tile[tl_cnt].x, tetros[tetr_cnt]->tile[tl_cnt].y);
=======
>>>>>>> bits-and-scores
		}
		if (buf[cnt] == '#' && tl_cnt > 0)
		{
			tetros[tetr_cnt]->tile[tl_cnt].x = ((cnt / 5) - (head / 5));
			tetros[tetr_cnt]->tile[tl_cnt].y = ((cnt % 5) - (head % 5));
<<<<<<< HEAD
			printf("Head is located at: %d, Current position is: %d\n", head, cnt);
			printf("Tile %d| X is: %d, Y is: %d\n", tl_cnt, tetros[tetr_cnt]->tile[tl_cnt].x, tetros[tetr_cnt]->tile[tl_cnt].y);
=======
>>>>>>> bits-and-scores
		}
		tl_cnt++;
		cnt++;
	}
<<<<<<< HEAD
	return (0);
}

int		store_input(char *buf, int tetr_cnt, t_tetr **tetros)
{
	get_coords(buf, tetr_cnt, tetros);
	return (1);
}
=======
	return (1);
}
>>>>>>> bits-and-scores
