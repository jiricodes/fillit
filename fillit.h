/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:17:32 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/01 12:58:04 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "libft/get_next_line.h"

/*
**	Helpful definitions
*/

# define MS map->size
# define MT map->tile
# define MV map->tile[i].value
# define MX map->tile[i].loc.x
# define MY map->tile[i].loc.y
# define TN tetrimino->name
# define TT tetrimino->tile
# define TP tetrimino->placed
# define TX tetrimino->tile[j].x
# define TY tetrimino->tile[j].y

/*
** Coordinates struct for easier readibility of the code
*/

typedef struct	s_coords
{
	int	x;
	int	y;
}				t_coords;

/*
**	Tile struct
*/

typedef struct	s_tile
{
	char value;
	t_coords loc;
}				t_tile;

/*
** Tetrimino struct
*/

typedef struct	s_tetrimino
{
	char		name;
	t_coords	tile[4];
	int			placed;
}				t_tetr;

/*
** Board/Map struct
*/

typedef struct	s_map
{
	int	size;
	t_tile	*tile;
}				t_map;


/*
**	Map functions
*/

int		init_map(t_map *map, int size);
int		tetr_to_map(t_map *map, t_tetr *tetrimino, int x, int y);
void	print_map(t_map *map);
int		check_space(t_map *map, int org, t_tetr *tetrimino);
int		place_tetriminos(t_map *map, t_tetr **tetrimino, int count);

/*
** Tetrimino functions
*/

void	copy_tetrimino(t_tetr *t1, t_tetr *t2);
int		check_tetrimino(t_tetr *tetrimino, t_map *map, int i);
void	print_tetrimino(t_tetr *tetrimino);
void	reset_tetriminos(t_tetr **tetrimino, int count);

#endif