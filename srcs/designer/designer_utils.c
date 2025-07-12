/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:13:05 by akupesa           #+#    #+#             */
/*   Updated: 2025/06/22 19:13:10 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_raycasting(t_cub *cub)
{
	static const double_t	field_of_view = M_PI / 3.0;
	static const double_t	field = field_of_view / 2.0;
	static int				column = -1;
	double_t				relative_angle;

	if (cub->pcpt.raycasting_initialized == true)
		return ;
	while (++column < WIDTH)
	{
		relative_angle = -field + ((double_t)column / WIDTH) * field_of_view;
		cub->pcpt.ray_dir[column].x = cos(relative_angle);
		cub->pcpt.ray_dir[column].y = sin(relative_angle);
		cub->pcpt.cos_fac[column] = cos(relative_angle);
	}
	cub->pcpt.raycasting_initialized = true;
}

t_dda_data	iterate_to_wall(t_cub *cub, t_dda_data dda)
{
	while (!(dda.map_pos.x < 0
			|| dda.map_pos.x >= cub->map.width
			|| dda.map_pos.y < 0
			|| dda.map_pos.y >= cub->map.height)
		&& cub->map.matrix[dda.map_pos.y][dda.map_pos.x] != '1')
	{
		if (dda.side_distance.x < dda.side_distance.y)
		{
			dda.side_distance.x += dda.delta_distance.x;
			dda.map_pos.x += dda.step.x;
			dda.side = 0;
		}
		else
		{
			dda.side_distance.y += dda.delta_distance.y;
			dda.map_pos.y += dda.step.y;
			dda.side = 1;
		}
	}
	return (dda);
}

void	dda_clamp(t_dda_data *dda, const t_vector2d pos, const t_vector2d dir)
{
	if (dir.x < 0)
		dda->step.x = -1;
	if (dir.x < 0)
		dda->side_distance.x = (pos.x - dda->map_pos.x)
			* dda->delta_distance.x;
	if (dir.x >= 0)
		dda->step.x = 1;
	if (dir.x >= 0)
		dda->side_distance.x = (dda->map_pos.x + 1.0 - pos.x)
			* dda->delta_distance.x;
	if (dir.y < 0)
		dda->step.y = -1;
	if (dir.y < 0)
		dda->side_distance.y = (pos.y - dda->map_pos.y)
			* dda->delta_distance.y;
	if (dir.y >= 0)
		dda->step.y = 1;
	if (dir.y >= 0)
		dda->side_distance.y = (dda->map_pos.y + 1.0 - pos.y)
			* dda->delta_distance.y;
}

int	get_texture_x(const t_dda_result result, const t_texture *texture)
{
	int			tex_x;
	double_t	wall_hit;

	if (result.side == 0)
		wall_hit = result.hit_point.y;
	else
		wall_hit = result.hit_point.x;
	wall_hit -= floor(wall_hit);
	tex_x = (int)(wall_hit * (double_t)texture->width);
	if ((result.side == 0 && result.hit_point.x < result.map_pos.x)
		|| (result.side == 1 && result.hit_point.y < result.map_pos.y))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

t_texture	*get_wall_texture(t_cub *cub, const t_dda_result result)
{
	if (result.side == 0)
	{
		if (result.dir.x < 0)
			return (&cub->texture.west);
		else
			return (&cub->texture.east);
	}
	else
	{
		if (result.dir.y < 0)
			return (&cub->texture.north);
		else
			return (&cub->texture.south);
	}
}
