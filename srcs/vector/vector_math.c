/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:45:10 by gecarval          #+#    #+#             */
/*   Updated: 2025/05/28 15:50:49 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector2d	vec2d_add(t_vector2d lop, t_vector2d rop)
{
	return ((t_vector2d){lop.x + rop.x, lop.y + rop.y});
}

t_vector2d	vec2d_addby(t_vector2d lop, double_t rop)
{
	return ((t_vector2d){lop.x + rop, lop.y + rop});
}

t_vector2d	vec2d_sub(t_vector2d lop, t_vector2d rop)
{
	return ((t_vector2d){lop.x - rop.x, lop.y - rop.y});
}

t_vector2d	vec2d_subby(t_vector2d lop, double_t rop)
{
	return ((t_vector2d){lop.x - rop, lop.y - rop});
}

t_vector2d	vec2d_pow(t_vector2d lop, double_t rop)
{
	return ((t_vector2d){pow(lop.x, rop), pow(lop.y, rop)});
}
