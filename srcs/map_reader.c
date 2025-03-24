/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:41:58 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:44:59 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strjoint(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1 != NULL && s1[++i] != '\0')
		result[i] = ((unsigned char *)s1)[i];
	while (s2 != NULL && s2[j] != '\0')
		result[i++] = ((unsigned char *)s2)[j++];
	if (s1 != NULL)
		free(s1);
	s1 = NULL;
	if (s2 != NULL)
		free(s2);
	s2 = NULL;
	return (result);
}

int	ft_getmapsize(t_cub *cub, bool axis_flag)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	x = 0;
	i = 0;
	while (cub->map.matrix[y] != NULL)
	{
		i = ft_strlen(cub->map.matrix[y]);
		if (i > x)
			x = i;
		y++;
	}
	if (axis_flag == true)
		return (x);
	return (y);
}

void	get_map_matrix(t_cub *cub, const char *file_name)
{
	int		i;
	int		fd;
	char	*buffer;
	char	*fullmap;

	i = 1;
	buffer = NULL;
	fullmap = (char *)ft_calloc(1, 1);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		simple_free(cub, "Error!\nInvalid Path or File Not Found.\n", 2);
	while (i > 0)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		i = read(fd, buffer, BUFFER_SIZE);
		fullmap = ft_strjoint(fullmap, buffer);
	}
	cub->map.matrix = ft_split(fullmap, '\n');
	is_map_empty(cub, fd, fullmap);
	if (fullmap != NULL)
		free(fullmap);
	close(fd);
}

int	load_map(t_cub *cub, const char *file_name)
{
	int	i;

	get_map_matrix(cub, file_name);
	cub->map.height = ft_getmapsize(cub, false);
	cub->map.width = ft_getmapsize(cub, true);
	i = -1;
	while (++i < cub->map.height)
		printf("%s\n", cub->map.matrix[i]);
	return (1);
}
