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
	const double_t speed = 1000;

	if (cub->player.direct.left)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(-speed, 0));
	if (cub->player.direct.right)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(speed, 0));
	if (cub->player.direct.up)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(0, -speed));
	if (cub->player.direct.down)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(0, speed));
	cub->player.vel = vec2d_add(cub->player.vel,
			vec2d_multby(cub->player.acel, cub->time.delta));
	if (cub->player.acel.x < 0)
		cub->player.acel.x = -pow(-cub->player.acel.x, 0.99);
	else
		cub->player.acel.x = pow(cub->player.acel.x, 0.99);
	if (cub->player.acel.y < 0)
		cub->player.acel.y = -pow(-cub->player.acel.y, 0.99);
	else
		cub->player.acel.y = pow(cub->player.acel.y, 0.99);
	cub->player.pos = vec2d_add(cub->player.pos,
			vec2d_multby(cub->player.vel, cub->time.delta));
	cub->player.vel = vec2d_zero();
}

void	physics_cub(t_cub *cub)
{
	player_physics(cub);
}
