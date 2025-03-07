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

typedef struct s_player
{
	float		x;
	float		y;
	int		moves;
	int		player_coords;
}			t_player;

typedef struct s_coords
{
  int		x;
	int		y;
}			t_coords;

typedef struct s_vector2d
{
  float		x;
	float		y;
}			t_vector2d;

typedef struct s_ray
{
	double	x;
	double	y;
	double	angle;
}			t_ray;

typedef struct s_cub
{
	int		F;
	int		EA;
	int		NO;
	int		SO;
	int		WE;
	int		map_h;
	int		map_w;
	char	**map;
	char	**map_cpy;
	void	*mlx;
	void	*window;
	t_player	*player;
}			t_cub;


#endif
