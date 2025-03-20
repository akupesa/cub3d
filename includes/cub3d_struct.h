/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:23 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/10 15:39:25 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include <math.h>
# include "../libft/libft.h"

typedef struct s_coords
{
	int			x;
	int			y;
}			t_coords;

typedef struct s_vector2d
{
	double_t	x;
	double_t	y;
}			t_vector2d;

typedef struct s_ray
{
	t_vector2d	ini;
	t_vector2d	fin;
	double_t	angle;
}			t_ray;

typedef struct s_player
{
	t_vector2d	pos;
	int			moves;
	int			player_coords;
}			t_player;

typedef struct s_quad
{
	float_t		x;
	float_t		y;
	float_t		width;
	float_t		height;
}			t_quad;

typedef struct s_cardial
{
	int			EA;
	int			NO;
	int			SO;
	int			WE;
}			t_cardial;

typedef struct s_list
{
        int     list;
        char    *list_k;
}               t_list;

typedef struct s_hash
{
	t_quad		square;
	t_list		list;
}			t_hash;

typedef struct s_map
{
	int			height;
	int			width;
	t_hash		**map;
	char		**matrix;
	char		**matrix_cpy;
}			t_map;

typedef struct s_cub
{
	int			F;
	t_cardial	card;
	t_map		map;
	void		*mlx;
	void		*window;
	t_player	*player;
}			t_cub;

#endif
