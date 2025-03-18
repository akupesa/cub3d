/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:09:20 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/10 15:09:22 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	extension_validator(t_cub *cub, char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (file_name[len - 4] == '.'
		&& file_name[len - 3] == 'c'
		&& file_name[len - 2] == 'u'
		&& file_name[len - 1] == 'b')
	{
		return (1);
	}
	else
	{
		simple_free(cub, "Error\nInvalid file extension.\n", 2);
		return (0);
	}
}
