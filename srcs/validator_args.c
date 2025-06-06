/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:09:20 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:46:47 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	extension_validator(t_cub *cub, char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (file_name[len - 4] == '.' && file_name[len - 3] == 'c' && file_name[len
			- 2] == 'u' && file_name[len - 1] == 'b')
	{
		return (1);
	}
	else
	{
		free_and_print(cub, "Error\nInvalid file extension.\n", 2);
		return (0);
	}
}
