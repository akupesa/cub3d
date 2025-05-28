/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:57:57 by akupesa           #+#    #+#             */
/*   Updated: 2025/05/28 16:46:23 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <sys/select.h>

void	control_cub(int keycode, t_cub *cub)
{
	if (keycode == ESC)
	{
		mlx_loop_end(cub->mlx.ptr);
		free_all(cub, 0);
	}
	if (keycode == MLX_A)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(-1, 0));
	if (keycode == MLX_D)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(1, 0));
	if (keycode == MLX_W)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(0, -1));
	if (keycode == MLX_S)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(0, 1));
	cub->player.coords = get_coords(cub);
	cub->prevlastframetime = cub->lastframetime;
	gettimeofday(&cub->frametime, NULL);
	cub->lastframetime = gettimeofday(struct timeval *__restrict tv, void *__restrict tz);
}

int	cub_loop(int keycode, t_cub *cub)
{
	control_cub(keycode, cub);
	//physics_cub(cub);
	//process_cub(cub);
	//render_cub(cub);
	return (false);
}
