/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:42:22 by gecarval          #+#    #+#             */
/*   Updated: 2025/05/29 11:45:57 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player_friction(t_cub *cub)
{
	const double_t	friction = 0.85;

	if (cub->player.acel.x < 0)
		cub->player.acel.x = -pow(-cub->player.acel.x, friction);
	else
		cub->player.acel.x = pow(cub->player.acel.x, friction);
	if (cub->player.acel.y < 0)
		cub->player.acel.y = -pow(-cub->player.acel.y, friction);
	else
		cub->player.acel.y = pow(cub->player.acel.y, friction);
}

void	process_cub(t_cub *cub)
{
	static unsigned long int i = 0;

	printf("[%ld] - Mensagem de Routina!\n", i++);
	player_friction(cub);
	(void)cub;
}
