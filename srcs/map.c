/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:35 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:45:12 by gecarval         ###   ########.fr       */
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
		copy[i] = (char *)ft_calloc(sizeof(char), (cub->map.width + 1));
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
