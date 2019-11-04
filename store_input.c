/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:38:38 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/04 16:55:00 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		store_input(char *buf, int tetr_cnt, t_tetr **tetros)
{
	int cnt;
	int head;
	int tl_cnt;

	cnt = 0;
	tl_cnt = 0;
	if (!(tetros[tetr_cnt] = (t_tetr *)malloc(sizeof(t_tetr))))
		return (-1);
	tetros[tetr_cnt]->name = tetr_cnt + 65;
	tetros[tetr_cnt]->placed = 0;
	while (buf[cnt] != '\0')
	{
		while (buf[cnt] != '#' && buf[cnt] != '\0') 
			cnt++;
		if (buf[cnt] == '#' && tl_cnt == 0)
		{
			tetros[tetr_cnt]->tile[tl_cnt].x = 0;
			tetros[tetr_cnt]->tile[tl_cnt].y = 0;
			head = cnt;
		}
		if (buf[cnt] == '#' && tl_cnt > 0)
		{
			tetros[tetr_cnt]->tile[tl_cnt].x = ((cnt / 5) - (head / 5));
			tetros[tetr_cnt]->tile[tl_cnt].y = ((cnt % 5) - (head % 5));
		}
		tl_cnt++;
		cnt++;
	}
	printf("'%c'\n", tetros[tetr_cnt]->name);
	print_tetrimino_bmap(tetros[tetr_cnt]);
	printf("\n");
	return (1);
}
