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

void	flood_fill(t_cub *cub, int x, int y)
{
	if (x < 0 || x >= cub->map_w || y < 0 || y >= cub->map_h)
		return ;
	if (cub->map_cpy[y][x] == 'X')
		return ;
	if (cub->map_cpy[y][x] == '1')
		return ;
	cub->map_cpy[y][x] = 'X';
	flood_fill(cub, x + 1, y);
	flood_fill(cub, x - 1, y);
	flood_fill(cub, x, y + 1);
	flood_fill(cub, x, y - 1);
}

t_coords	get_coords(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub != NULL && cub->map != NULL && cub->map[++i] != NULL)
	{
		j = -1;
		while (cub->map[i][++j] != '\0')
			if (cub->map[i][j] == 'N')
				return ((t_coords){j, i});
	}
	return ((t_coords){0, 0});
}


void	verify_path(t_cub *cub)
{
	t_coords	p_coords;

	p_coords = get_coords(cub);
	cub->map_cpy = map_copy(cub);
	flood_fill(cub, p_coords.x, p_coords.y);
	if (cub->map_cpy[p_coords.y][p_coords.x] != 'X')
		simple_free(cub, "Error\nMap is not closed\n");
}
