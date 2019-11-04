/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:38:38 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/04 12:28:54 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		get_coords(char *buf, int tetr_cnt, t_tetr **tetros)
{
	int cnt;
	int head;
	int tl_cnt;

	cnt = 0;
	tl_cnt = 0;
	tetros[tetr_cnt] = (t_tetr *)malloc(sizeof(t_tetr));
	tetros[tetr_cnt]->name = tetr_cnt + 65;
	tetros[tetr_cnt]->placed = 0;
	printf("Tetro %d has a name %c and placed value of %d\n", tetr_cnt, tetros[tetr_cnt]->name, tetros[tetr_cnt]->placed);
	while (buf[cnt] != '\0')
	{
		while (buf[cnt] != '#' && buf[cnt] != '\0')
			cnt++;
		if (buf[cnt] == '#' && tl_cnt == 0)
		{
			tetros[tetr_cnt]->tile[tl_cnt].x = 0;
			tetros[tetr_cnt]->tile[tl_cnt].y = 0;
			head = cnt;
			printf("Head is located at: %d, Current position is: %d\n", head, cnt);
			printf("Tile %d| X is: %d, Y is: %d\n", tl_cnt, tetros[tetr_cnt]->tile[tl_cnt].x, tetros[tetr_cnt]->tile[tl_cnt].y);
		}
		if (buf[cnt] == '#' && tl_cnt < 4)
		{
			tetros[tetr_cnt]->tile[tl_cnt].x = ((cnt / 5) - (head / 5));
			tetros[tetr_cnt]->tile[tl_cnt].y = ((cnt % 5) - (head % 5));
			printf("Head is located at: %d, Current position is: %d\n", head, cnt);
			printf("Tile %d| X is: %d, Y is: %d\n", tl_cnt, tetros[tetr_cnt]->tile[tl_cnt].x, tetros[tetr_cnt]->tile[tl_cnt].y);
		}
		tl_cnt++;
		cnt++;
	}
	return (0);
}

int		store_input(char *buf, int tetr_cnt, t_tetr **tetros)
{
	get_coords(buf, tetr_cnt, tetros);
	return (1);
}