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
		simple_free(cub, "Error!\nInvalid Path or File Not Found.\n");
	cub->map_h = 14;
	cub->map_w = 18;
	cub->map = (char **) ft_calloc((cub->map_h + 1), sizeof(char *));
	if (cub->map == NULL)
		simple_free(cub, "Error!\nMap Allocation Failed!!!\n");
	i = -1;
	while (++i < cub->map_h)
	{
		cub->map[i] = get_next_line(fd);
		printf("%s", cub->map[i]);
	}
	close(fd);
	if (!is_map_empty(cub))
		simple_free(cub, "Error!\nEmpty Map.\n");
	return (1);
}
