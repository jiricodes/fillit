#include "fillit.h"
#include <stdio.h>

int main ()
{
	t_tetr	t;
	t_map	m;
	int		i;
	int		size;

	t.name = 'D';
	t.tile[0].x = 0;
	t.tile[0].y = 0;
	t.tile[1].x = 1;
	t.tile[1].y = 0;
	t.tile[2].x = 2;
	t.tile[2].y = -1;
	t.tile[3].x = 2;
	t.tile[3].y = 0;

	size = 10;
	init_map(&m, size);
	if (-1 == tetr_to_map(&m, &t, 2, 2))
		{
			printf(" Failed to assign tetrimino to the map!\n");
			return (-1);
		}
	i = 0;
	print_map(&m);
	return (0);
}