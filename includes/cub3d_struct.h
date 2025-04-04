/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:23 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:33:51 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "../libft/libft.h"
# include "./hash.h"

typedef struct s_list	t_list;

typedef struct s_coords
{
	int					x;
	int					y;
}						t_coords;

typedef struct s_vector2d
{
	double_t			x;
	double_t			y;
}						t_vector2d;

typedef struct s_mlx
{
	void				*ptr;
	void				*window;
	unsigned int		width;
	unsigned int		height;
}						t_mlx;

typedef struct s_img
{
	void				*ptr;
	char				*addr;
	int					bpp;
	int					llen;
	int					end;
}						t_img;

typedef struct s_texture
{
	t_img				img;
	int					color;
	char				*path;
	unsigned int		width;
	unsigned int		height;
}						t_texture;

typedef struct s_cardial
{
	t_texture			north;
	t_texture			south;
	t_texture			east;
	t_texture			west;
}						t_cardial;

typedef struct s_map
{
	t_hashtable			**map;
	char				**matrix;
	char				**matrix_cpy;
	int					width;
	int					height;
}						t_map;

typedef struct s_ray
{
	t_vector2d			ini;
	t_vector2d			fin;
	double_t			angle;
}						t_ray;

typedef struct s_player
{
	t_vector2d			pos;
	t_vector2d			vel;
	t_vector2d			acel;
	t_coords			coords;
	double_t			angle;
	unsigned int		moves;
}						t_player;

typedef struct s_cub
{
	t_hashtable			hashtable;
	t_player			player;
	t_cardial			card;
	t_texture			floor;
	t_texture			ceiling;
	t_img				background;
	t_img				view;
	t_map				map;
	t_mlx				mlx;
	void				*wall;
}						t_cub;

#endif
