/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_frees.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:03:52 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:34:19 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map != NULL && map[i] != NULL)
		free(map[i++]);
	if (map != NULL)
		free(map);
}

static void	free_textures(t_cub *cub)
{
	if (cub->texture.north.path != NULL)
		free(cub->texture.north.path);
	if (cub->texture.north.img.ptr != NULL)
		mlx_destroy_image(cub->mlx.ptr, cub->texture.north.img.ptr);
	if (cub->texture.south.path != NULL)
		free(cub->texture.south.path);
	if (cub->texture.south.img.ptr != NULL)
		mlx_destroy_image(cub->mlx.ptr, cub->texture.south.img.ptr);
	if (cub->texture.east.path != NULL)
		free(cub->texture.east.path);
	if (cub->texture.east.img.ptr != NULL)
		mlx_destroy_image(cub->mlx.ptr, cub->texture.east.img.ptr);
	if (cub->texture.west.path != NULL)
		free(cub->texture.west.path);
	if (cub->texture.west.img.ptr != NULL)
		mlx_destroy_image(cub->mlx.ptr, cub->texture.west.img.ptr);
}

static void	free_cub(t_cub *cub)
{
	if (cub == NULL)
		return ;
	free_textures(cub);
	if (cub->background.ptr != NULL)
		mlx_destroy_image(cub->mlx.ptr, cub->background.ptr);
	if (cub->view.ptr != NULL)
		mlx_destroy_image(cub->mlx.ptr, cub->view.ptr);
	if (cub->map.file != NULL)
		free(cub->map.file);
	if (cub->map.matrix != NULL)
		free_map(cub->map.matrix);
	if (cub->map.matrix_cpy != NULL)
		free_map(cub->map.matrix_cpy);
	if (cub->mlx.window != NULL)
		mlx_destroy_window(cub->mlx.ptr, cub->mlx.window);
	if (cub->mlx.ptr != NULL)
		mlx_destroy_display(cub->mlx.ptr);
	if (cub->mlx.ptr != NULL)
		free(cub->mlx.ptr);
	free(cub);
}

void	free_and_print(t_cub *cub, char *str, int fd)
{
	if (str != NULL)
		ft_putstr_fd(str, 2);
	free_cub(cub);
	exit(fd);
}

int	free_all(t_cub *cub, int fd)
{
	mlx_loop_end(cub->mlx.ptr);
	free_cub(cub);
	exit(fd);
	return (fd);
}
