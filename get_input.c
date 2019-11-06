/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:29:11 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/06 11:16:17 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Count neighbour cells to check total number of tiles
*/

static void		check_neighbour(char *buf)
{
	int	x;
	int	n_cnt;
	int	t_cnt;

	x = 0;
	n_cnt = 0;
	t_cnt = 0;
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
		ft_puterr(-1);
}

/*
**	Check for width, length and chars
*/

static void		check_input(char *buf)
{
	int		x;
	int		len;
	int		nl_cnt;

	nl_cnt = 0;
	len = ft_strlen(buf);
	x = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] != '.' && buf[x] != '#' && buf[x] != '\n')
			ft_puterr(-1);
		if (x != 20 && buf[x] == '\n' && x % 5 != 4)
			ft_puterr(-1);
		if (buf[x] == '\n' || buf[x + 1] == '\0')
			nl_cnt++;
		x++;
	}
	check_neighbour(buf);
	if (nl_cnt != 4)
		ft_puterr(-1);
	if (buf[len - 1] != '\n')
		ft_puterr(-1);
}

/*
**	Format the input
*/

static void		strip_tetro(char **buf)
{
	int		len;
	int		nl_cnt;
	int		x;
	char	*temp;

	len = ft_strlen(*buf);
	nl_cnt = 0;
	x = 0;
	while ((*buf)[x] != '\0')
	{
		if ((*buf)[x] == '\n')
			nl_cnt++;
		x++;
	}
	if (nl_cnt == 5)
	{
		temp = ft_strsub(*buf, 0, len - 1);
		free(*buf);
		*buf = temp;
	}
}

/*
**	Read input from file and transform tetrominoes into coordinates
*/

void			get_input(char *argv, t_tetr **tetros, int *t_cnt)
{
	char	*buf;
	int		fd;
	int		ret;
	int		last_ret;

	buf = (char *)malloc(22 * sizeof(char));
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_puterr(-1);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		last_ret = ret;
		buf[ret] = '\0';
		strip_tetro(&buf);
		check_input(buf);
		store_input(buf, (*t_cnt), tetros);
		(*t_cnt)++;
	}
	if ((ret <= 0 && last_ret == 21) || (*t_cnt) > 26)
		ft_puterr(-1);
	free(buf);
}
