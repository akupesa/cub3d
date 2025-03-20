/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:35 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/12 12:16:36 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**map_copy(t_cub *cub)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	copy = NULL;
	copy = (char **)ft_calloc(sizeof(char *), (cub->map.height + 1));
	copy[cub->map.height] = NULL;
	while (i < cub->map.height)
	{
		copy[i] = (char *)ft_calloc(sizeof(char ), (cub->map.width + 1));
		j = 0;
		while (j < cub->map.width)
		{
			copy[i][j] = cub->map.matrix[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

int	map_validator(t_cub *cub)
{
	int	x;
	int	y;

	if (player_validator(cub))
	{
		simple_free(cub, "Error!\nInvalid number of player.\n", 2);
		return (true);
	}
	y = -1;
	while (++y < cub->map.height)
	{
		x = -1;
		while (++x < cub->map.width)
		{
			if (!chars_validator(cub->map.matrix[y][x]))
			{
				simple_free(cub, "Error!\nMap contains invalid characters.\n", 2);
				return (true);
			}
		}
	}
	return (false);
}
