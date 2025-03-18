/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_frees.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:03:52 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/12 10:04:22 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

void	simple_free(t_cub *cub, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	free (cub);
	exit (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_exit(int __status)
{
	exit(__status);
	return (__status);
}

int	free_all(t_cub *cub)
{
	if (cub == NULL)
		return (ft_exit(0));
	if (cub->map.matrix != NULL)
		free_map(cub->map.matrix);
	if (cub->map.matrix_cpy != NULL)
		free_map(cub->map.matrix_cpy);
	if (cub->window != NULL)
		mlx_destroy_window(cub->mlx, cub->window);
	if (cub->mlx != NULL)
		mlx_destroy_display(cub->mlx);
	if (cub->mlx != NULL)
		free(cub->mlx);
	free(cub);
	return (ft_exit(0));
}
