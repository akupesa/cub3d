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

char	*ft_strjoint(char *s1, const char *s2)
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

int	get_map_size(t_cub *cub, bool axis_flag)
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

void	get_file_data(t_cub *cub, const char *file)
{
	int		i;

	i = -1;
	while (file[++i] != '\0')
	{
		if (file[i] == ' ')
			continue ;
		else if (ft_strncmp(&file[i], "NO", 1) == 0)
			continue ;
		else if (ft_strncmp(&file[i], "SO", 1) == 0)
			continue ;
		else if (ft_strncmp(&file[i], "WE", 1) == 0)
			continue ;
		else if (ft_strncmp(&file[i], "EA", 1) == 0)
			continue ;
		else if (ft_strncmp(&file[i], "F", 0) == 0)
			continue ;
		else if (ft_strncmp(&file[i], "C", 0) == 0)
			continue ;
		else if (file[i] == '1' || file[i] == '0')
			break ;
	}
	cub->map.matrix = ft_split(&file[i], '\n');
}

void	get_full_map(t_cub *cub, const char *file_name)
{
	int		i;
	int		fd;
	char	*file;
	char	buffer[BUFFER_SIZE + 1];

	i = 1;
	file = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		simple_free(cub, "Error!\nInvalid Path or File Not Found.\n", 2);
	while (i > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		i = read(fd, buffer, BUFFER_SIZE);
		file = ft_strjoint(file, buffer);
	}
	close(fd);
	get_file_data(cub, file);
	//is_map_empty(cub, file);
	if (file != NULL)
		free(file);
}

int	load_map(t_cub *cub, const char *file_name)
{
	int	i;

	get_full_map(cub, file_name);
	i = -1;
	while (++i < cub->map.height)
		printf("%s\n", cub->map.matrix[i]);
	//if (map_validator(cub))
		//simple_free(cub, "Invalid map!", 2);
	cub->floor.color = 0x555511;
	cub->ceiling.color = 0x5599f1;
	return (1);
}
