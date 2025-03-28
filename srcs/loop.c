/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:22:52 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/28 10:22:54 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	hook(t_cub *cub)
{
	mlx_hook(cub->mlx.window, 2, 1l << 0, keys_handler, cub);
	mlx_hook(cub->mlx.window, 17, 0, free_all, cub);
}
