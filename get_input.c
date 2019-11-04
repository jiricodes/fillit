/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:29:11 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/04 17:36:41 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
**	Count neighbour cells to check total number of tiles
*/

static int		check_neighbour(char *buf)
{
	int	x;
	int	n_cnt;
	int	t_cnt;

	x = 0;
	n_cnt = 0;
	while (buf[x] != '\0')
	{
		while (buf[x] != '#' && buf[x] != '\0')
			x++;
		if (buf[x] == '#')
			t_cnt++;
		if (buf[x] == '#' && buf[x + 1] == '#')
			n_cnt++;
		if (buf[x] == '#' && buf[x + 5] == '#')
			n_cnt++;
		if (buf[x] == '#' && buf[x - 1] == '#')
			n_cnt++;
		if (buf[x] == '#' && buf[x - 5] == '#')
			n_cnt++;
		x++;
	}
	if (!((n_cnt == 6 || n_cnt == 8) && t_cnt == 4))
		return (-1);
	return (1);
}

/*
**	Check for width, length and chars
*/

static int		check_input(char *buf)
{
	int		x;
	int		len;
	int		lncnt;

	lncnt = 0;
	len = ft_strlen(buf);
	x = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] != '.' && buf[x] != '#' && buf[x] != '\n')
			return (-1);
		if (x != 20 && buf[x] == '\n' && x % 5 != 4)
			return (-1);
		if (buf[x] == '\n' || buf[x + 1] == '\0')
			lncnt++;
		x++;
	}
	if (lncnt != 4)
		return (-1);
	if (len == 21 && buf[len - 1] != '\n')
		return (-1);
	if (check_neighbour(buf) != 1)
		return (-1);
	return (1);
}

/*
**	Format the input
*/

static void 		strip_tetro(char **buf)
{
	int	len;
	int ln_cnt;
	int x;
	char *temp;

	len = ft_strlen(*buf);
	ln_cnt = 0;
	x = 0;
	while ((*buf)[x] != '\0')
	{
		if ((*buf)[x] == '\n')
			ln_cnt++;
		x++;
	}
	if (ln_cnt == 5)
	{
		temp = ft_strsub(*buf, 0, len - 1);
		free(*buf);
		*buf = temp;
	}
}

/*
**	Read input from file and transform tetrominoes into coordinates
*/

t_tetr			**get_input(char *argv, int *cnt) /*add pointer to maxc int then assign tetr_cnt to it before return*/
{
	char	*buf;
	int		fd;
	int		ret;
	int		tetr_cnt;
	t_tetr	**tetros;

	tetros = (t_tetr **)malloc(26 * sizeof(t_tetr *) + 1);
	tetr_cnt = 0;
	buf = (char *)malloc(22 * sizeof(char));
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buf, 21)) > 0) /*protect from ret = -1*/
	{
		buf[ret] = '\0';
		strip_tetro(&buf);
		if ((check_input(buf)) != 1)
			return (0);
		else
			store_input(buf, tetr_cnt, tetros);
		tetr_cnt++;
	}
	free(buf);
	tetros[tetr_cnt] = 0;
	cnt[0] = tetr_cnt;
	return (tetros);
}
