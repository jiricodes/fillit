/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:29:11 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/01 14:53:35 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		get_coords(char *buf, t_tetr **tetr)
{
	int x;
	int y;
	int tile_cnt;
	int i;

	i = 0;
	while (i < 19)
	{
		tetr[i] = (t_tetr*)malloc(sizeof(t_tetr));
		i = i + 1;
	}

	x = 0;
	tile_cnt = 0;
	while (tile_cnt <= 4)
	{
		
	}
}

int		check_neighbour(char *buf)
{
	int 	x;
	int		n_cnt;

	x = 0;
	n_cnt = 0;
	while (buf[x] != '\0')
	{
		while (buf[x] != '#' && buf[x] != '\0')
			x++;
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
	printf("Final count is: %d\n", n_cnt);
	if (n_cnt != 6)
	{
		printf("Wrong count: %d\n", n_cnt);
		return (-1);
	}
	else
		return (1);
}

int		check_input(char *buf)
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

char	*strip_tetro(char *buf)
{
	int	len;
	int ln_cnt;
	int x;

	len = ft_strlen(buf);
	ln_cnt = 0;
	x = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] == '\n')
			ln_cnt++;
		x++;
	}
	if (ln_cnt == 5)
		return (ft_strsub(buf, 0, len - 1));
	else
		return (buf);
	
}

int		get_input(char **argv)
{
	t_tetr	**tetrimino;
	char	*buf;
	int		fd;
	int		ret;
	int		x;

	if (!(tetrimino = (t_tetr**)malloc(sizeof(t_tetr*)*19)))
		return (-1);
	x = 0;
	buf = (char *)malloc(22 * sizeof(char));
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		printf("Original Tetromino %d is:\n%s", x, buf);
		buf = strip_tetro(buf);
		printf("Stripped Tetromino %d is:\n%s", x, buf);
		if ((check_input(buf)) != 1)
		{
			printf("Input is shit\n");
			return (-1);
		}
		// else
		// 	get_coords(buf, tetrimino);
		x++;
	}
	return (1);
}
