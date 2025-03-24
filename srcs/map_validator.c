/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:17:48 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:45:06 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	is_map_empty(t_cub *cub, int fd, char *fullmap)
{
	if (is_there_two_n(fullmap) == true)
	{
		close(fd);
		if (fullmap != NULL)
			free(fullmap);
		simple_free(cub,
			"Error!\nMap contains more than one followed newline.\n", 2);
	}
	if (cub->map.matrix == NULL || (cub->map.height == 1
			&& cub->map.matrix[0] == NULL))
	{
		close(fd);
		if (fullmap != NULL)
			free(fullmap);
		simple_free(cub, "Fatal Error!\nFailure on Map Allocation\n", 1);
	}
}

bool	is_there_two_n(char *fullmap)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (fullmap == NULL || fullmap[0] == '\0')
		return (false);
	while (fullmap[++i] != '\0')
	{
		if (fullmap[i] == '\n')
		{
			count++;
			continue ;
		}
		if (count > 1 && fullmap[i] != '\n')
			return (true);
		count = 0;
	}
	return (false);
}
