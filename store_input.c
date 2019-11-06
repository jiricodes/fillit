/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:38:38 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/06 14:44:16 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_tetro(t_tetr **tetros, int tetr_cnt)
{
	if (!(tetros[tetr_cnt] = (t_tetr *)malloc(sizeof(t_tetr))))
		ft_puterr(-1);
	tetros[tetr_cnt]->name = tetr_cnt + 65;
	tetros[tetr_cnt]->placed = -1;
}

void		store_input(char *buf, int tetr_cnt, t_tetr **tetros)
{
	int cnt;
	int head;
	int tl_cnt;

	cnt = 0;
	tl_cnt = 0;
	init_tetro(tetros, tetr_cnt);
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
}
