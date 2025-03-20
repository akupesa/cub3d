/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:41:58 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/21 16:42:00 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	load_map(t_cub *cub, const char *file_name)
{
	int	fd;
	int	i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		simple_free(cub, "Error!\nInvalid Path or File Not Found.\n", 2);
	cub->map.height = 14;
	cub->map.width = 18;
	cub->map.matrix = (char **) ft_calloc((cub->map.height + 1), sizeof(char *));
	if (cub->map.matrix == NULL)
		simple_free(cub, "Error!\nMap Allocation Failed!!!\n", 2);
	i = -1;
	while (++i < cub->map.height)
	{
		cub->map.matrix[i] = get_next_line(fd);
		printf("%s", cub->map.matrix[i]);
	}
	close(fd);
	if (!is_map_empty(cub))
		simple_free(cub, "Error!\nEmpty Map.\n", 2);
	return (1);
}
