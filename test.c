#include "fillit.h"
#include <stdio.h>

int main ()
{
	t_tetr	t;
	t_tetr	t2;
	t_map	map;
	int		i;
	int		size;
	int		ret;

	t.name = 'A';
	t.tile[0].x = 0;
	t.tile[0].y = 0;
	t.tile[1].x = 1;
	t.tile[1].y = -1;
	t.tile[2].x = 1;
	t.tile[2].y = 0;
	t.tile[3].x = 2;
	t.tile[3].y = 0;

	t2.name = 'B';
	t2.tile[0].x = 0;
	t2.tile[0].y = 0;
	t2.tile[1].x = 0;
	t2.tile[1].y = 1;
	t2.tile[2].x = 0;
	t2.tile[2].y = 2;
	t2.tile[3].x = 0;
	t2.tile[3].y = 3;

	size = 10;
	init_map(&map, size);
	i = 0;
	while (i < 3)
	{
		ret = check_space(&map, i, &t);
		if (ret == 0)
		{
			tetr_to_map (&map, &t, map.tile[i].loc.x, map.tile[i].loc.y);
			break ;
		}
		i = i + 1;
	}
	i = 0;
	while (i < size * size)
	{
		if (0 == check_space(&map, i, &t2))
		{
			tetr_to_map (&map, &t2, map.tile[i].loc.x, map.tile[i].loc.y);
			break ;
		}
		i = i + 1;
	}
	print_map(&map);
	return (0);
}