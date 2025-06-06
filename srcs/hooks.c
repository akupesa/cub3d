/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:57:57 by akupesa           #+#    #+#             */
/*   Updated: 2025/05/29 12:37:19 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	control_cub(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		mlx_loop_end(cub->mlx.ptr);
	if (keycode == MLX_A)
		cub->player.direct.left = true;
	if (keycode == MLX_D)
		cub->player.direct.right = true;
	if (keycode == MLX_W)
		cub->player.direct.up = true;
	if (keycode == MLX_S)
		cub->player.direct.down = true;
	return (true);
}

int				control_release_cub(int keycode, t_cub *cub)
{
	if (keycode == MLX_A)
		cub->player.direct.left = false;
	if (keycode == MLX_D)
		cub->player.direct.right = false;
	if (keycode == MLX_W)
		cub->player.direct.up = false;
	if (keycode == MLX_S)
		cub->player.direct.down = false;
	return (true);
}

void	get_frame_time(t_cub *cub)
{
	gettimeofday(&cub->time.frametime, NULL);
	cub->time.prevlastframetime = cub->time.lastframetime;
	cub->time.lastframetime = cub->time.frametime.tv_usec;
	if (cub->time.lastframetime - cub->time.prevlastframetime >= 0.0)
		cub->time.delta = (cub->time.lastframetime
				- cub->time.prevlastframetime) / 1000000.0;
	cub->time.frames_per_second++;
	cub->time.second_interval += cub->time.delta;
	cub->time.process_call_timer += cub->time.delta;
	if (cub->time.second_interval >= 1.0)
	{
		cub->time.frames_per_second = 0;
		cub->time.second_interval = 0.0;
	}
	cub->player.coords = get_coords(cub);
}

int	cub_loop(t_cub *cub)
{
	get_frame_time(cub);
	physics_cub(cub);
	while (cub->time.process_call_timer >= AMOUNT_TO_CALL)
	{
		process_cub(cub);
		cub->time.process_call_timer -= AMOUNT_TO_CALL;
	}
	physics_process_cub(cub);
	render_cub(cub);
	return (true);
}
