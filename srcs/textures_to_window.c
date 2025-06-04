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

void	render_background(t_cub *cub)
{
	t_coords	pos;

	pos.y = 0;
	while (pos.y < cub->mlx.height / 2)
	{
		pos.x = -1;
		while (++pos.x < cub->mlx.width)
			put_texture_pixel(&cub->layer[0], pos, cub->ceiling.color);
		pos.y++;
	}
	while (pos.y < cub->mlx.height)
	{
		pos.x = -1;
		while (++pos.x < cub->mlx.width)
			put_texture_pixel(&cub->layer[0], pos, cub->floor.color);
		pos.y++;
	}
}

void	put_texture_pixel(t_texture *text, t_coords pos, int color)
{
	int	offset;

	if (pos.x < 0 || pos.x >= text->width
		|| pos.y < 0 || pos.y >= text->height)
		return ;
	offset = pos.y * text->img.llen + pos.x * (text->img.bpp / 8);
	*(int *)(text->img.addr + offset) = color;
}

int	get_texture_pixel(t_texture *text, t_coords pos)
{
	int	offset;

	if (pos.x < 0 || pos.x >= text->width
		|| pos.y < 0 || pos.y >= text->height)
		return (0);
	offset = pos.y * text->img.llen + pos.x * (text->img.bpp / 8);
	return (*(int *)(text->img.addr + offset));
}

int	get_image_pixel(t_cub *cub, t_img *img, t_coords pos)
{
	int	offset;

	if (pos.x < 0 || pos.x >= cub->mlx.width
		|| pos.y < 0 || pos.y >= cub->mlx.height)
		return (0);
	offset = pos.y * img->llen + pos.x * (img->bpp / 8);
	return (*(int *)(img->addr + offset));
}

void	put_image_pixel(t_cub *cub, t_img *img, t_coords pos, int color)
{
	int	offset;

	if (pos.x < 0 || pos.x >= cub->mlx.width
		|| pos.y < 0 || pos.y >= cub->mlx.height)
		return ;
	offset = pos.y * img->llen + pos.x * (img->bpp / 8);
	*(int *)(img->addr + offset) = color;
}
