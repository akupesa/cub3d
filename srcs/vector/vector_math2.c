/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:45:51 by gecarval          #+#    #+#             */
/*   Updated: 2025/05/28 15:51:59 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector2d	vec2d_mult(t_vector2d lop, t_vector2d rop)
{
	return ((t_vector2d){lop.x * rop.x, lop.y * rop.y});
}

t_vector2d	vec2d_multby(t_vector2d lop, double_t rop)
{
	return ((t_vector2d){lop.x * rop, lop.y * rop});
}

t_vector2d	vec2d_div(t_vector2d lop, t_vector2d rop)
{
	return ((t_vector2d){lop.x / rop.x, lop.y / rop.y});
}

t_vector2d	vec2d_divby(t_vector2d lop, double_t rop)
{
	return ((t_vector2d){lop.x / rop, lop.y / rop});
}

t_vector2d	vec2d_sqrt(t_vector2d lop)
{
	return ((t_vector2d){sqrt(lop.x), sqrt(lop.y)});
}
