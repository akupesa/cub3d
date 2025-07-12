/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:42:28 by gecarval          #+#    #+#             */
/*   Updated: 2025/06/26 16:42:13 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	hash_collision(const t_cub *cub, const t_vector2d *result)
{
	double_t	i;

	if (result->y < 0.0 || result->y >= cub->map.height)
		return (false);
	i = 0;
	if (result->x < i)
		return (false);
	while (cub->map.matrix_cpy[(int)floor(result->y)][(int)floor(i)] != '\0')
		i++;
	if (result->x >= i)
		return (false);
	if (cub->map.matrix_cpy[(int)floor(result->y)]
		[(int)floor(result->x)] != '1')
		return (true);
	return (false);
}

void	player_speed_calc(t_cub *cub)
{
	t_vector2d	result;
	t_player	*p;

	p = &cub->player;
	p->vel = vec2d_add(p->vel,
			vec2d_multby(p->acel, cub->time.delta));
	p->acel = vec2d_zero();
	result = vec2d_add(p->pos,
			vec2d_multby(p->vel, cub->time.delta));
	if (hash_collision(cub, &result) == true)
		p->pos = result;
	p->vel = vec2d_zero();
}

void	player_input_calc(t_cub *cub)
{
	static const double_t	deg = (M_PI) / 2.5;
	t_player				*p;
	double_t				speed;
	t_vector2d				direction;

	p = &cub->player;
	speed = 40;
	if (p->direct.sprint == true)
		speed = 80;
	direction = vec2d_create(speed * sin(p->angle), -speed * cos(p->angle));
	if (p->direct.left == true)
		p->acel = vec2d_add(p->acel, direction);
	if (p->direct.right == true)
		p->acel = vec2d_add(p->acel, vec2d_multby(direction, -1));
	direction = vec2d_create(-speed * cos(p->angle), -speed * sin(p->angle));
	if (p->direct.down == true)
		p->acel = vec2d_add(p->acel, direction);
	if (p->direct.up == true)
		p->acel = vec2d_add(p->acel, vec2d_multby(direction, -1));
	if (p->direct.left_turn == true)
		p->angle -= deg * cub->time.delta;
	if (p->direct.right_turn == true)
		p->angle += deg * cub->time.delta;
	if ((p->angle >= (M_PI * 2)) || (p->angle <= -(M_PI * 2)))
		p->angle = 0;
}

void	physics_cub(t_cub *cub)
{
	player_input_calc(cub);
	player_speed_calc(cub);
}
