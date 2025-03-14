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

int     is_map_empty(t_cub *cub)
{
        if (cub->map == NULL || cub->map_h == 0)
                return (0);
        return (1);
}

int     is_there_two_n(t_cub *cub)
{
        int     i;
        int     j;

        i = 0;
        while (cub->map[i] != NULL)
        {
                j = 0;
                while (cub->map[i][j] != '\0')
                {
                        if (cub->map[i][j] == '\n' && cub->map[i + 1][j] == '\n')
                                return (TRUE);
                        j++;
                }
                i++;
        }
        return (FALSE);
}
