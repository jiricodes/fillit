/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:29:11 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/30 13:39:17 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include <stdio.h>

int		check_input(char *str)
{
	int nlcnt;
	int x;
	int y;

	y = 0;
	nlcnt = 0;
	while (str)
	{
		while (nlcnt != 5)
		{
			x = 0;
			while (str[x + y] != '\n')
				x++;
			printf("%d", x);
			if (str[x + y + 1] == '\n' && x != 4)
				return (0);
			else
			{
				nlcnt++;
				y += 5;
			}
		}
	}
	return (1);
}


int	get_input(char **argv)
{
	int		fd;
	int		ret;
	char	*buf;
	char	*string;
	int		input;

	string = ft_strnew(1);
	buf = malloc((BUFF_SIZE + 1) * sizeof(char));
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		string = ft_strjoin(string, buf);
	}
	printf("This is the string:\n%s\n", string);
	input = check_input(string);
	printf("\nInput is:\n%d", input);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		get_input(argv);
	else
		ft_putstr("usage : don't put crap input\n");
	return (0);
}