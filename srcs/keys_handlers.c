/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:57:57 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/05 09:57:58 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_handler_left(t_cub *cub, t_coords *vector)
{
	if (cub->map[vector->y][vector->x -1] != '1')
	{
		cub->map[vector->y][vector->x - 1] = 'N';
		cub->map[vector->y][vector->x] = '0';
		cub->player->moves++;
	}
}

void	key_handler_right(t_cub *cub, t_coords *vector)
{
	if (cub->map[vector->y][vector->x + 1] != '1')
	{
		cub->map[vector->y][vector->x + 1] = 'N';
		cub->map[vector->y][vector->x] = '0';
		cub->player->moves++;
	}
}

void	key_handler_up(t_cub *cub, t_coords *vector)
{
	if (cub->map[vector->y - 1][vector->x] != 1)
	{
		cub->map[vector->y - 1][vector->x] = 'N';
		cub->map[vector->y][vector->x] = '0';
		cub->player->moves++;
	}
}

void	key_handler_down(t_cub *cub, t_coords *vector)
{
	if (cub->map[vector->y + 1][vector->x] != '1')
	{
		cub->map[vector->y + 1][vector->x] = 'N';
		cub->map[vector->y][vector->x] = '0';
		cub->player->moves++;
	}
}

int	keys_handler(int keycode, t_cub *cub)
{
	t_coords	player_coords;

	if (keycode == ESC)
		free_all(cub);
	player_coords = get_coords(cub);
	if (keycode == A)
		key_handler_left(cub, &player_coords);
	else if (keycode == D)
		key_handler_right(cub, &player_coords);
	else if (keycode == W)
		key_handler_up(cub, &player_coords);
	else if(keycode == S)
		key_handler_down(cub, &player_coords);
	else
		return (FALSE);
	return (TRUE);
}
