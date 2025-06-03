/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_validator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:39:49 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:43:49 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_coords	get_coords(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub != NULL && cub->map.matrix != NULL
		&& cub->map.matrix[++i] != NULL)
	{
		j = -1;
		while (cub->map.matrix[i][++j] != '\0')
			if (cub->map.matrix[i][j] == 'N'
			|| cub->map.matrix[i][j] == 'S'
			|| cub->map.matrix[i][j] == 'E'
			|| cub->map.matrix[i][j] == 'W')
				return ((t_coords){j, i});
	}
	return ((t_coords){0, 0});
}

void	verify_path(t_cub *cub)
{
	t_coords	p_coords;
	char		backup;

	p_coords = get_coords(cub);
	cub->map.matrix_cpy[p_coords.y][p_coords.x] = '0';
	backup = cub->map.matrix_cpy[p_coords.y][p_coords.x];
	if (map_not_closed(cub, (const char **)cub->map.matrix_cpy) == true)
		free_and_print(cub, "Error\nMap is not closed\n", 2);
	cub->map.matrix_cpy[p_coords.y][p_coords.x] = backup;
}

bool	map_not_closed(t_cub *cub, const char **matrix)
{
	int		y;
	int		x;

	y = -1;
	while (++y < cub->map.height)
	{
		x = -1;
		while (matrix[y][++x] != '\0')
		{
			if (matrix[y][x] == '0')
			{
				if (x == 0 || y == 0
					|| y == cub->map.height -1
					|| matrix[y][x + 1] == '\0'
					|| matrix[y][x + 1] == ' '
					|| matrix[y][x - 1] == ' '
					|| matrix[y + 1][x] == ' '
					|| matrix[y - 1][x] == ' ')
					return (true);
			}
		}
	}
	return (false);
}
