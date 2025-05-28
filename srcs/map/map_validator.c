/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:17:48 by akupesa           #+#    #+#             */
/*   Updated: 2025/05/28 15:57:12 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	is_map_empty(t_cub *cub, int i)
{
	if (is_there_two_n(cub, i) == true)
		free_and_print(cub,
			"Error!\nMap contains more than one followed newline.\n", 2);
	if (cub->map.matrix == NULL || (cub->map.height == 1
			&& cub->map.matrix[0] == NULL))
		free_and_print(cub, "Fatal Error!\nFailure on Map Allocation\n", 1);
}

bool	is_there_two_n(t_cub *cub, int i)
{
	int	count;

	count = 0;
	if (cub->map.file == NULL || cub->map.file[0] == '\0')
		return (false);
	while (cub->map.file[i] != '\0')
	{
		if (cub->map.file[i] == '\n')
			count++;
		if (count > 1 && cub->map.file[i] != '\n')
			return (true);
		else if (cub->map.file[i] != '\n')
			count = 0;
		i++;
	}
	return (false);
}

void	map_validator(t_cub *cub)
{
	int	x;
	int	y;

	if (player_validator(cub))
		free_and_print(cub, "Error!\nInvalid number of player.\n", 2);
	y = -1;
	while (cub->map.matrix[++y] != NULL)
	{
		x = -1;
		while (cub->map.matrix[y][++x] != '\0')
		{
			if (!chars_validator(cub->map.matrix[y][x]))
				free_and_print(cub, "Error!\nMap contains invalid characters.\n",
					2);
		}
	}
}

bool	player_validator(t_cub *cub)
{
	int	x;
	int	y;
	int	player_counter;

	y = -1;
	player_counter = 0;
	while (cub->map.matrix[++y] != NULL)
	{
		x = -1;
		while (cub->map.matrix[y][++x] != '\0')
			if (cub->map.matrix[y][x] == 'N'
				|| cub->map.matrix[y][x] == 'S'
				|| cub->map.matrix[y][x] == 'E'
				|| cub->map.matrix[y][x] == 'W')
				player_counter++;
	}
	if (player_counter != 1)
		return (true);
	return (false);
}

bool	chars_validator(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}
