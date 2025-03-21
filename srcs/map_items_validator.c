/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_items_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:05:27 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/27 10:05:30 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	chars_validator(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == ' ');
}

int	player_validator(t_cub *cub)
{
	int		x;
	int		y;
	int		player_counter;

	y = -1;
	player_counter = 0;
	while (++y < cub->map.height)
	{
		x = -1;
		while (++x < cub->map.width)
			if (cub->map.matrix[y][x] == 'N')
				player_counter++;
	}
	if (player_counter != 1)
		return (false);
	return (true);
}
