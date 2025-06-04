/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:42:28 by gecarval          #+#    #+#             */
/*   Updated: 2025/05/29 10:42:48 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player_physics(t_cub *cub)
{
	cub->player.acel = vec2d_multby(cub->player.acel, cub->time.delta);
	cub->player.vel = vec2d_add(cub->player.vel, cub->player.acel);
	cub->player.acel = vec2d_zero();
	cub->player.vel = vec2d_multby(cub->player.vel, cub->time.delta);
	cub->player.pos = vec2d_add(cub->player.pos, cub->player.vel);
	cub->player.vel = vec2d_sqrt(cub->player.vel);
}

void	physics_cub(t_cub *cub)
{
	player_physics(cub);
}
