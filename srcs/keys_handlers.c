/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:57:57 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:44:22 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_handler_left(t_cub *cub)
{
	t_coords	*vector;

	vector = &cub->player.coords;
	if (cub->map.matrix[vector->y][vector->x - 1] != '1')
	{
		cub->map.matrix[vector->y][vector->x - 1] = 'N';
		cub->map.matrix[vector->y][vector->x] = '0';
		cub->player.moves++;
	}
}

void	key_handler_right(t_cub *cub)
{
	t_coords	*vector;

	vector = &cub->player.coords;
	if (cub->map.matrix[vector->y][vector->x + 1] != '1')
	{
		cub->map.matrix[vector->y][vector->x + 1] = 'N';
		cub->map.matrix[vector->y][vector->x] = '0';
		cub->player.moves++;
	}
}

void	key_handler_up(t_cub *cub)
{
	t_coords	*vector;

	vector = &cub->player.coords;
	if (cub->map.matrix[vector->y - 1][vector->x] != '1')
	{
		cub->map.matrix[vector->y - 1][vector->x] = 'N';
		cub->map.matrix[vector->y][vector->x] = '0';
		cub->player.moves++;
	}
}

void	key_handler_down(t_cub *cub)
{
	t_coords	*vector;

	vector = &cub->player.coords;
	if (cub->map.matrix[vector->y + 1][vector->x] != '1')
	{
		cub->map.matrix[vector->y + 1][vector->x] = 'N';
		cub->map.matrix[vector->y][vector->x] = '0';
		cub->player.moves++;
	}
}

int	keys_handler(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		free_all(cub, 0);
	cub->player.coords = get_coords(cub);
	if (keycode == MLX_A)
		key_handler_left(cub);
	else if (keycode == MLX_D)
		key_handler_right(cub);
	else if (keycode == MLX_W)
		key_handler_up(cub);
	else if (keycode == MLX_S)
		key_handler_down(cub);
	else
		return (true);
	printf("%d ", cub->player.moves);
	return (false);
}
