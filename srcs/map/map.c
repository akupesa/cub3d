/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:35 by akupesa           #+#    #+#             */
/*   Updated: 2025/05/28 15:57:05 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	load_layers(t_cub *cub);

void	load_map(t_cub *cub, const char *file_name)
{
	int		i;

	cub->floor.color = -1;
	cub->ceiling.color = -1;
	cub->mlx.width = WIDTH;
	cub->mlx.height = HEIGHT;
	get_file(cub, file_name);
	map_validator(cub);
	while (cub->map.matrix[cub->map.height] != NULL)
	{
		i = -1;
		while (cub->map.matrix[cub->map.height][++i] != '\0')
			if (i > cub->map.width)
				cub->map.width = i;
		cub->map.height++;
	}
	verify_path(cub);
	load_layers(cub);
}

static void	load_layers(t_cub *cub)
{
	int		i;

	i = -1;
	while (++i < LAYERS_SIZE)
	{
		cub->layer[i].img.ptr = mlx_new_image(cub->mlx.ptr,
				cub->mlx.width, cub->mlx.height);
		cub->layer[i].img.addr = mlx_get_data_addr(cub->layer[i].img.ptr,
				&cub->layer[i].img.bpp,
				&cub->layer[i].img.llen, &cub->layer[i].img.end);
		cub->layer[i].width = cub->mlx.width;
		cub->layer[i].height = cub->mlx.height;
	}
	cub->screen.ptr = mlx_new_image(cub->mlx.ptr, cub->mlx.width, cub->mlx.height);
	cub->screen.addr = mlx_get_data_addr(cub->screen.ptr, &cub->screen.bpp,
			&cub->screen.llen, &cub->screen.end);
}

char	*ft_strjoint(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	j = 0;
	i = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s1 == NULL)
		i++;
	while (s1 != NULL && s1[++i] != '\0')
		result[i] = s1[i];
	while (s2 != NULL && s2[j] != '\0')
		result[i++] = s2[j++];
	if (s1 != NULL)
		free(s1);
	s1 = NULL;
	return (result);
}
