/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:44:33 by gecarval          #+#    #+#             */
/*   Updated: 2025/05/28 15:45:00 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector2d	vec2d_create(double_t x, double_t y)
{
	return ((t_vector2d){x, y});
}

t_vector2d	vec2d_zero(void)
{
	return ((t_vector2d){0.0, 0.0});
}

