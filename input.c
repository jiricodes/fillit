/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:29:11 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/30 18:48:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		check_input(char *tetro)
{
	int		x;
	int		len;

	len = ft_strlen(tetro);
	x = 0;
	while (tetro[x] != '\0')
	{
		if (tetro[x] != '.' && tetro[x] != '#' && tetro[x] != '\n')
			return (-1);
		x++;
	}
	if (len == 21 && tetro[len - 1] != '\n')
	{
		return (-1);
	}

	return (1);

}

int		get_input(char **argv)
{
	char	*buf;
	int		fd;
	int		ret;
	int		x;
	char	**tetro;

	x = 0;
	tetro = (char **)malloc(26 * sizeof(char*));
	buf = (char *)malloc(22 * sizeof(char));
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		tetro[x] = buf;
		printf("Tetromino %d is:\n%s", x, tetro[x]);
		if ((check_input(tetro[x])) != 1)
			printf("Input is shit");
		x++;
	}
}
