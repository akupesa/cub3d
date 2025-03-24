/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:04:55 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:45:17 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	put_pixel(t_cub *cub, t_coords vec, int color)
{
	int	offset;

	offset = (vec.y * cub->background.llen)
		+ (vec.x * (cub->background.bpp / 8));
	*(unsigned int *)(cub->background.addr + offset) = color;
}

void	render_background(t_cub *cub)
{
	t_coords	vec;

	cub->background.ptr = mlx_new_image(cub->mlx.ptr, WIDTH, HEIGHT);
	cub->background.addr = mlx_get_data_addr(cub->background.ptr,
			&cub->background.bpp, &cub->background.llen, &cub->background.end);
	vec.y = 0;
	while (vec.y < HEIGHT / 2)
	{
		vec.x = -1;
		while (++vec.x < WIDTH)
			put_pixel(cub, vec, cub->ceiling.color);
		vec.y++;
	}
	while (vec.y < HEIGHT)
	{
		vec.x = -1;
		while (++vec.x < WIDTH)
			put_pixel(cub, vec, cub->floor.color);
		vec.y++;
	}
}
