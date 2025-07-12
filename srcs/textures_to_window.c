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

void	render_skybox(t_cub *cub)
{
	t_coords	pos;

	pos.y = 0;
	while (pos.y < cub->mlx.height / 2)
	{
		pos.x = -1;
		while (++pos.x < cub->mlx.width)
			put_image_pixel(cub, &cub->screen, pos, cub->ceiling.color);
		pos.y++;
	}
	while (pos.y < cub->mlx.height)
	{
		pos.x = -1;
		while (++pos.x < cub->mlx.width)
			put_image_pixel(cub, &cub->screen, pos, cub->floor.color);
		pos.y++;
	}
}

void	put_texture_pixel(t_texture *text, const t_coords pos,
						const unsigned int color)
{
	unsigned int	offset;

	if (!text || !text->img.addr)
		return ;
	if (pos.x < 0 || pos.x >= text->width
		|| pos.y < 0 || pos.y >= text->height)
		return ;
	text->modified = true;
	offset = pos.y * text->img.llen + pos.x * (text->img.bpp / 8);
	*(unsigned int *)(text->img.addr + offset) = color;
}

void	put_image_pixel(const t_cub *cub, const t_img *img,
		const t_coords pos, const unsigned int color)
{
	unsigned int	offset;

	if (!img || !img->addr)
		return ;
	if (pos.x < 0 || pos.x >= cub->mlx.width
		|| pos.y < 0 || pos.y >= cub->mlx.height)
		return ;
	offset = pos.y * img->llen + pos.x * (img->bpp / 8);
	*(unsigned int *)(img->addr + offset) = color;
}

unsigned int	get_texture_pixel(const t_texture *text, const t_coords pos)
{
	unsigned int	offset;

	if (!text || !text->img.addr)
		return (0);
	if (pos.x < 0 || pos.x >= text->width
		|| pos.y < 0 || pos.y >= text->height)
		return (0);
	offset = pos.y * text->img.llen + pos.x * (text->img.bpp / 8);
	return (*(unsigned int *)(text->img.addr + offset));
}

unsigned int	get_image_pixel(const t_cub *cub, const t_img *img,
								const t_coords pos)
{
	unsigned int	offset;

	if (!img || !img->addr)
		return (0);
	if (pos.x < 0 || pos.x >= cub->mlx.width
		|| pos.y < 0 || pos.y >= cub->mlx.height)
		return (0);
	offset = pos.y * img->llen + pos.x * (img->bpp / 8);
	return (*(unsigned int *)(img->addr + offset));
}
