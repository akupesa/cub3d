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

void	load_map(t_cub *cub, const char *file_name)
{
	int		i;

	cub->floor.color = -1;
	cub->ceiling.color = -1;
	get_file(cub, file_name);
	map_validator(cub);
	while (cub->map.matrix[cub->map.height] != NULL)
	{
		i = -1;
		while (cub->map.matrix[++i])
			if (i > cub->map.width)
				cub->map.width = i;
		cub->map.height++;
	}
}

t_coords	get_coords(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub != NULL && cub->map.matrix != NULL
		&& cub->map.matrix[++i] != NULL)
	{
		j = -1;
		while (cub->map.matrix[i][++j] != '\0')
			if (cub->map.matrix[i][j] == 'N')
				return ((t_coords){j, i});
	}
	return ((t_coords){0, 0});
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
