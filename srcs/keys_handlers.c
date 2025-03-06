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

void	key_handler_left(t_cub *cub, int p_y, int p_x)
{
	if (cub->map[p_y][p_x -1] != '1')
	{
		cub->map[p_y][p_x - 1] = 'N';
		cub->map[p_y][p_x] = '0';
		cub->player->moves++;
	}
}

void	key_handler_right(t_cub *cub, int p_y, int p_x)
{
	if (cub->map[p_y][p_x + 1] != '1')
	{
		cub->map[p_y][p_x + 1] = 'N';
		cub->map[p_y][p_x] = '0';
		cub->player->moves++;
	}
}

void	key_handler_up(t_cub *cub, int p_y, int p_x)
{
	if (cub->map[p_y - 1][p_x] != 1)
	{
		cub->map[p_y - 1][p_x] = 'N';
		cub->map[p_y][p_x] = '0';
		cub->player->moves++;
	}
}

void	key_handler_down(t_cub *cub, int p_y, int p_x)
{
	if (cub->map[p_y + 1][p_x] != '1')
	{
		cub->map[p_y + 1][p_x] = 'N';
		cub->map[p_y][p_x] = '0';
		cub->player->moves++;
	}
}

int	keys_handler(t_cub *cub, int keycode)
{
	t_coords	player_coords;

	player_coords = get_coords(cub);
	if (keycode == A)
		key_handler_left(cub, player_coords.y, player_coords.x);
	else if (keycode == D)
		key_handler_right(cub, player_coords.y, player_coords.x);
	else if (keycode == W)
		key_handler_up(cub, player_coords.y, player_coords.x);
	else if(keycode == S)
		key_handler_down(cub, player_coords.y, player_coords.x);
	else
		return (FALSE);
	return (TRUE);
}