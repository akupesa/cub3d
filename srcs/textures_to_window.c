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

#include "../includes/cub3d.h"

static void     put_pixel(char *buffer, int x, int y, int color, int line_length)
{
        int     offset;

        offset = (y * line_length) + (x * 4);
        *(unsigned int *)(buffer + offset) = color;
}

void     put_texture(t_cub *cub)
{
        int     x;
        int     y;
        int     half_height;
        int     line_length;
        int     bpp;
        int     endian;
        char    *buffer;

        cub->floor = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
        buffer = mlx_get_data_addr(cub->floor, &bpp, &line_length, &endian);
        half_height = HEIGHT / 2;
        y = -1;
        while (++y < half_height)
        {
                x = -1;
                while (++x < WIDTH)
                {
                        put_pixel(buffer, x, y, cub->C, line_length);
                }
        }
        while (y < HEIGHT)
        {
                x = -1;
                while (++x < WIDTH)
                        put_pixel(buffer, x, y, cub->F, line_length);
                y++;
        }
        mlx_put_image_to_window(cub->mlx, cub->window, cub->floor, 0, 0);
}
