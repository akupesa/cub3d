/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designer_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:16:17 by akupesa           #+#    #+#             */
/*   Updated: 2025/06/26 16:18:24 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_dda(t_dda_data *dda, const t_vector2d pos,
					const t_vector2d dir)
{
	dda->map_pos.x = (int)pos.x;
	dda->map_pos.y = (int)pos.y;
	dda->delta_distance.x = 1e30;
	if (dir.x != 0)
		dda->delta_distance.x = fabs(1.0 / dir.x);
	dda->delta_distance.y = 1e30;
	if (dir.y != 0)
		dda->delta_distance.y = fabs(1.0 / dir.y);
	dda_clamp(dda, pos, dir);
}

static t_dda_result	perform_dda(t_dda_result result, t_cub *cub,
		const t_vector2d pos)
{
	t_dda_data		dda;

	init_dda(&dda, pos, result.dir);
	dda = iterate_to_wall(cub, dda);
	if (dda.side == 0)
		result.distance = (dda.map_pos.x - pos.x + (1.0 - dda.step.x)
				/ 2.0) / result.dir.x;
	else
		result.distance = (dda.map_pos.y - pos.y + (1.0 - dda.step.y)
				/ 2.0) / result.dir.y;
	result.side = dda.side;
	result.hit_point.x = pos.x + result.distance * result.dir.x;
	result.hit_point.y = pos.y + result.distance * result.dir.y;
	result.map_pos = dda.map_pos;
	return (result);
}

static void	render_wall_column(t_cub *cub, t_dda_result result, int column,
								const int wall_height)
{
	const int		start_y = (HEIGHT / 2.0) - (wall_height / 2.0);
	const t_texture	*wall_texture = get_wall_texture(cub, result);
	const int		*texture_data = (int *)wall_texture->img.addr;
	const double_t	scale = (double_t)wall_texture->height / wall_height;

	result.tex.x = get_texture_x(result, wall_texture);
	result.y = 0;
	if (start_y > 0)
		result.y = start_y;
	result.end_y = start_y + wall_height;
	if (result.end_y > HEIGHT)
		result.end_y = HEIGHT;
	while (++result.y < result.end_y)
	{
		result.tex.y = (result.y - start_y) * scale;
		put_texture_pixel(&cub->layer[0], (t_coords){column, result.y},
			texture_data[result.tex.y * wall_texture->width + result.tex.x]);
	}
}

static void	cast_ray(t_cub *cub, int column)
{
	static double_t	cos_player = 0.0;
	static double_t	sin_player = 0.0;
	static int		first_frame = 1;
	t_dda_result	result;

	if (first_frame || column == 0)
	{
		cos_player = cos(cub->player.angle);
		sin_player = sin(cub->player.angle);
		first_frame = 0;
	}	
	result.dir.x = cub->pcpt.ray_dir[column].x * cos_player
		- cub->pcpt.ray_dir[column].y * sin_player;
	result.dir.y = cub->pcpt.ray_dir[column].x * sin_player
		+ cub->pcpt.ray_dir[column].y * cos_player;
	result = perform_dda(result, cub, cub->player.pos);
	result.distance *= cub->pcpt.cos_fac[column];
	if ((int)(HEIGHT / result.distance) > 0)
		render_wall_column(cub, result, column,
			(int)(HEIGHT / result.distance));
}

void	render_ray(t_cub *cub)
{
	init_raycasting(cub);
	cub->column = 0;
	while (cub->column < WIDTH)
		cast_ray(cub, cub->column++);
}
