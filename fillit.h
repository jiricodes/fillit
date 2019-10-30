/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:17:32 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/30 09:59:54 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "libft/get_next_line.h"

/*
** Coordinates struct for easier readibility of the code
*/

typedef struct	s_coords
{
	int	x;
	int	y;
}				t_coords;

/*
** Tetrimino struct
*/

typedef struct	s_tetrimino
{
	char		name;
	t_coords	tile1;
	t_coords	tile2;
	t_coords	tile3;
	t_coords	tile4;
}				t_tetr;

#endif