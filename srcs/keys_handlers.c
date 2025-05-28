/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:57:57 by akupesa           #+#    #+#             */
/*   Updated: 2025/05/28 15:56:59 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	control_cub(int keycode, t_cub *cub)
{
	if (keycode == ESC)
	{
		mlx_loop_end(cub->mlx.ptr);
		free_all(cub, 0);
	}
	if (keycode == MLX_A)
		cub->player.acel = vec2d_create(-1, 0);
	if (keycode == MLX_D)
	if (keycode == MLX_W)
	if (keycode == MLX_S)
	cub->player.coords = get_coords(cub);
}

int	cub_loop(int keycode, t_cub *cub)
{
	control_cub(keycode, cub);
	return (false);
}
