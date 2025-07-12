/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:40:25 by gecarval          #+#    #+#             */
/*   Updated: 2025/05/29 10:40:54 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_image(t_cub *cub, t_img *image)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->mlx.height)
	{
		j = -1;
		while (++j < cub->mlx.width)
			put_image_pixel(cub, image, (t_coords){j, i}, 0);
	}
	cub->layer[i].modified = false;
}

void	paint_layer(t_cub *cub, t_texture *layer)
{
	t_coords		pos;
	t_coords		tmp_pos;
	unsigned int	color;

	pos.y = -1;
	while (++pos.y < cub->mlx.height)
	{
		pos.x = -1;
		while (++pos.x < cub->mlx.width)
		{
			color = 0;
			color = get_texture_pixel(layer, pos);
			if (color != 0x00000000)
			{
				tmp_pos = (t_coords){pos.x + layer->pos.x,
					pos.y + layer->pos.y};
				put_image_pixel(cub, &cub->screen, tmp_pos, color);
			}
		}
	}
}

void	render_cub(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < LAYERS_SIZE)
		if (cub->layer[i].modified == true)
			clear_image(cub, &cub->layer[i].img);
	render_skybox(cub);
	render_ray(cub);
	i = -1;
	while (++i < LAYERS_SIZE)
		if (cub->layer[i].modified == true)
			paint_layer(cub, &cub->layer[i]);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.window, cub->screen.ptr, 0,
		0);
}
