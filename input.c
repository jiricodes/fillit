/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:29:11 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/31 11:30:05 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		get_coords(char *tetro);

int		check_neighbour(char *tetro);

int		check_input(char *tetro)
{
	int		x;
	int		len;
	int		lncnt;

	lncnt = 0;
	len = ft_strlen(tetro);
	x = 0;
	while (tetro[x] != '\0')
	{
		if (tetro[x] != '.' && tetro[x] != '#' && tetro[x] != '\n')
			return (-1);
		if (x != 20 && tetro[x] == '\n' && x % 5 != 4)
			return (-1);
		if (tetro[x] == '\n' || tetro[x + 1] == '\0')
			lncnt++;
		x++;
	}
	if (lncnt != 4)
		return (-1);
	if (len == 21 && tetro[len - 1] != '\n')
	{
		return (-1);
	}

	return (1);

}

char	*strip_tetro(char *tetro)
{
	int	len;
	int ln_cnt;
	int x;

	len = ft_strlen(tetro);
	ln_cnt = 0;
	x = 0;
	while (tetro[x] != '\0')
	{
		if (tetro[x] == '\n')
			ln_cnt++;
		x++;
	}
	if (ln_cnt == 5)
		return (ft_strsub(tetro, 0, len - 1));
	else
		return (tetro);
	
}

int		get_input(char **argv)
{
	char	*buf;
	int		fd;
	int		ret;
	int		x;

	x = 0;
	buf = (char *)malloc(22 * sizeof(char));
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		printf("Tetromino %d is:\n%s", x, buf);
		buf = strip_tetro(buf);
		printf("!NEW! Tetromino %d is:\n%s", x, buf);
		if ((check_input(buf)) != 1)
		{
			printf("Input is shit");
			return (-1);
		}
		// else
		// 	get_coords(buf);
		x++;
	}
}
