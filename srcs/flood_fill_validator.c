/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_validator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:39:49 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/26 15:59:56 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	flood_fill(t_cub *cub, t_coords vector)
{
	if (vector.x < 0 || vector.x >= cub->map.map_w || vector.y < 0 || vector.y >= cub->map.map_h)
		return ;
	if (cub->map.matrix_cpy[vector.y][vector.x] == 'X')
		return ;
	if (cub->map.matrix_cpy[vector.y][vector.x] == '1')
		return ;
	cub->map.matrix_cpy[vector.y][vector.x] = 'X';
	flood_fill(cub, (t_coords){vector.x + 1, vector.y});
	flood_fill(cub, (t_coords){vector.x - 1, vector.y});
	flood_fill(cub, (t_coords){vector.x, vector.y + 1});
	flood_fill(cub, (t_coords){vector.x, vector.y - 1});
}

t_coords	get_coords(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub != NULL && cub->map.matrix != NULL && cub->map.matrix[++i] != NULL)
	{
		j = -1;
		while (cub->map.matrix[i][++j] != '\0')
			if (cub->map.matrix[i][j] == 'N')
				return ((t_coords){j, i});
	}
	return ((t_coords){0, 0});
}


void	verify_path(t_cub *cub)
{
	t_coords	p_coords;

	p_coords = get_coords(cub);
	cub->map.matrix_cpy = map_copy(cub);
  flood_fill(cub, p_coords);
	if (cub->map.matrix_cpy[p_coords.y][p_coords.x] != 'X')
		simple_free(cub, "Error\nMap is not closed\n");
}
