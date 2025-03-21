/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:04:55 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/21 11:02:36 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d"

int     put_texture(t_cub *cub)
{
        int     x;
        int     y;

        x = 0;
        y = 0;
        if (cub->map[y][x] == '0')
                mlx_put_image_to_window(cub->mlx, cub->window,
                                cub->floor, );
        else if (cub->[y][x] == '1')
                mlx_put_image_to_window(cub->mlx, cub->window,
                                cub->wall, );
        else
                return (1);
        return (0);
}

int     game_render(t_cub *cub)
{
        
}
