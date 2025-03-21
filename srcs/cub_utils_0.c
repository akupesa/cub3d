/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:17:48 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/21 18:17:49 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void     is_map_empty(t_cub *cub, int fd, char *fullmap)
{
        if (cub->map.matrix == NULL ||
                (cub->map.height == 1 &&
                cub->map.matrix[0] == NULL))
	{
		close(fd);
		if (fullmap != NULL)
			free(fullmap);
		simple_free(cub, "Fatal Error!\nFailure on Map Allocation", 1);
	}
}

int     is_there_two_n(t_cub *cub)
{
        int     i;
        int     j;
        int     count;

        i = 0;
        count = 0;
        while (i < cub->map.height)
        {
                j = 0;
                while (cub->map.matrix[i][j] != '\0')
                {
                        if (cub->map.matrix[i][j] == '\n')
                                count++;
                        else if (cub->map.matrix[i][j] != '\n' && count > 1)
                                return (true);
                        else if (cub->map.matrix[i][j] != '\n')
                                count = 0;
                        j++;
                }
                i++;
        }
        return (false);
}
