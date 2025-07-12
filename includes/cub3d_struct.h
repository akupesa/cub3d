/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:23 by akupesa           #+#    #+#             */
/*   Updated: 2025/05/29 10:46:52 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <math.h>

// Render Layers
# ifndef LAYERS_SIZE
#  define LAYERS_SIZE 3
# endif

// Window frame size
# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

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

typedef struct s_direct
{
	bool				up;
	bool				down;
	bool				left;
	bool				right;
	bool				left_turn;
	bool				right_turn;
	bool				jump;
	bool				sprint;
}						t_direct;

typedef struct s_mlx
{
	void				*ptr;
	void				*window;
	int					width;
	int					height;
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
	t_vector2d			pos;
	t_img				img;
	char				*path;
	int					color;
	int					width;
	int					height;
	bool				modified;
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
	int					width;
	int					height;
	char				*file;
	char				**matrix;
	char				**matrix_cpy;
}						t_map;

typedef struct s_time
{
	long				frames_per_second;
	long				prevlastframetime;
	long				lastframetime;
	struct timeval		frametime;
	double_t			delta;
	double_t			second_interval;
	double_t			process_call_timer;
}						t_time;

typedef struct s_player
{
	t_vector2d			pos;
	t_vector2d			vel;
	t_vector2d			acel;
	t_direct			direct;
	t_coords			coords;
	double_t			angle;
	unsigned int		moves;
}						t_player;

typedef struct s_dda_data
{
	t_vector2d	delta_distance;
	t_vector2d	side_distance;
	t_coords	map_pos;
	t_coords	step;
	int			side;
}	t_dda_data;

typedef struct s_dda_result
{
	t_vector2d		dir;
	t_vector2d		hit_point;
	double_t		distance;
	t_coords		map_pos;
	t_coords		tex;
	int				side;
	int				end_y;
	int				y;
}	t_dda_result;

typedef struct s_precompute {
	t_vector2d		ray_dir[WIDTH];
	double_t		cos_fac[WIDTH];
	bool			raycasting_initialized;
}	t_precompute;

typedef struct s_cub
{
	t_precompute		pcpt;
	t_img				screen;
	t_cardial			texture;
	t_texture			floor;
	t_texture			ceiling;
	t_texture			layer[LAYERS_SIZE];
	t_player			player;
	t_time				time;
	t_map				map;
	t_mlx				mlx;
	int					column;
}						t_cub;

#endif
