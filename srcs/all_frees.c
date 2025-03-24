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

int	ft_exit(int __status)
{
	exit(__status);
	return (__status);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map != NULL && map[i] != NULL)
		free(map[i++]);
	if (map != NULL)
		free(map);
}

static void	free_cub(t_cub *cub)
{
	if (cub == NULL)
		return ;
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

void	simple_free(t_cub *cub, char *str, int fd)
{
	if (str != NULL)
		ft_putstr_fd(str, 2);
	free_cub(cub);
	exit(fd);
}

int	free_all(t_cub *cub, int fd)
{
	free_cub(cub);
	return (ft_exit(fd));
}
