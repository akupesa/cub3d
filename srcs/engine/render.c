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

void	clear_image(t_cub *cub, t_img *image);

// Layers config:
// 0 - background;
// 1 - background sky overlay;
// 2 - backgroung ground overlay;
// 3 - walls;
// 4 - UI overlay;
// 5 - text ovelay;
void	paint_layer(t_cub *cub, t_texture *layer, t_img *screen)
{
	t_coords		pos;
	int				color;

	color = 0;
	pos.y = -1;
	while (++pos.y < cub->mlx.height)
	{
		pos.x = -1;
		while (++pos.x < cub->mlx.width)
		{
			color = 0;
			color = get_texture_pixel(layer, pos);
			if (color != 0)
				put_image_pixel(cub, screen, pos, color);
		}
	}
}

void	render_cub(t_cub *cub)
{
	int		i;

	put_texture_pixel(&cub->layer[LAYERS_SIZE - 1],
		(t_coords){(int)cub->player.pos.x, (int)cub->player.pos.y}, 0xff0000);
	i = -1;
	while (++i < LAYERS_SIZE)
		paint_layer(cub, &cub->layer[i], &cub->screen);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.window, cub->screen.ptr, 0, 0);
	i = 0;
	while (++i < LAYERS_SIZE)
		clear_image(cub, &cub->layer[i].img);
	clear_image(cub, &cub->screen);
}

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
}
