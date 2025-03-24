/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_items_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:05:27 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:44:52 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	chars_validator(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

bool	player_validator(t_cub *cub)
{
	int	x;
	int	y;
	int	player_counter;

	y = -1;
	player_counter = 0;
	while (++y < cub->map.height)
	{
		x = -1;
		while (cub->map.matrix[y][++x] != '\0')
			if (cub->map.matrix[y][x] == 'N')
				player_counter++;
	}
	if (player_counter != 1)
		return (false);
	return (true);
}
