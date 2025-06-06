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

void	player_speed_calc(t_cub *cub)
{
	cub->player.vel = vec2d_add(cub->player.vel,
			vec2d_multby(cub->player.acel, cub->time.delta));
	cub->player.pos = vec2d_add(cub->player.pos,
			vec2d_multby(cub->player.vel, cub->time.delta));
	cub->player.vel = vec2d_zero();
}

void	player_input_calc(t_cub *cub)
{
	double_t speed;

	speed = 1000;
	if (cub->player.direct.sprint == true)
		speed = 2500;
	if (cub->player.direct.left == true)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(-speed, 0));
	if (cub->player.direct.right == true)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(speed, 0));
	if (cub->player.direct.up == true)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(0, -speed));
	if (cub->player.direct.down == true)
		cub->player.acel = vec2d_add(cub->player.acel, vec2d_create(0, speed));
	if (cub->player.direct.left_turn == true)
		cub->player.angle = -0.9 * cub->time.delta;
	if (cub->player.direct.right_turn == true)
		cub->player.angle = 0.9 * cub->time.delta;
}

void	physics_cub(t_cub *cub)
{
	player_input_calc(cub);
	player_speed_calc(cub);
}
