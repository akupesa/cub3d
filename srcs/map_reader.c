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
#include <stdio.h>

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

void	get_texture(t_cub *cub, t_texture *rsc, char *file, int *i)
{
	int	len;

	while (file[*i] != '\0' && file[*i] != ' ')
		(*i)++;
	while (file[*i] != '\0' && file[*i] == ' ')
		(*i)++;
	len = *i;
	while (file[len] != '\0' && file[len] != ' ' && file[len] != '\n')
		len++;
	rsc->path = (char *)ft_calloc(len, sizeof(char));
	len = 0;
	while (file[*i] != '\0' && file[*i] != ' ' && file[*i] != '\n')
		rsc->path[len++] = file[(*i)++];
	if (rsc->img.ptr != NULL)
	{
		free(file);
		free_and_print(cub, "Repetead texture source\n", 2);
	}
	rsc->img.ptr = mlx_xpm_file_to_image(cub->mlx.ptr,
			rsc->path, &rsc->width, &rsc->height);
	if (rsc->img.ptr == NULL)
	{
		free(file);
		free_and_print(cub, "No texture source file found!\n", 2);
	}
}

int	get_color_number(t_cub *cub, char *file, int *i)
{
	int		j;
	int		num;

	j = 0;
	num = 0;
	while (file[*i] != '\0' && file[*i] != '\n' && file[*i] != ',')
	{
		if (j++ > 3 || !ft_isdigit(file[*i]))
		{
			printf("hi!\n");
			printf("%d\n", num);
			free(file);
			free_and_print(cub, "Repetead Color\n", 2);
		}
		num = (num * 10) + (file[(*i)++] - '0');
	}
	if (num > 255)
	{
		free(file);
		free_and_print(cub, "Wrong color format!\n", 2);
	}
	return (num);
}

void	get_color(t_cub *cub, t_texture *rsc, char *file, int *i)
{
	int		j;
	int		num;

	j = -1;
	num = 0;
	while (file[*i] != '\0' && file[*i] != ' ')
		(*i)++;
	while (++j < 3)
		num = (num << 8) + get_color_number(cub, file, i);
	rsc->color = num;
	//if (rsc->color != -1)
		//free_and_print(cub, "Repetead Resource\n", 2);
}

void	get_file_data(t_cub *cub, char *file)
{
	int		i;

	i = -1;
	while (file[++i] != '\0')
	{
		if (file[i] == ' ' || file[i] == '\n')
			continue ;
		else if (ft_strncmp(&file[i], "NO", 2) == 0)
			get_texture(cub, &cub->texture.north, file, &i);
		else if (ft_strncmp(&file[i], "SO", 2) == 0)
			get_texture(cub, &cub->texture.south, file, &i);
		else if (ft_strncmp(&file[i], "WE", 2) == 0)
			get_texture(cub, &cub->texture.west, file, &i);
		else if (ft_strncmp(&file[i], "EA", 2) == 0)
			get_texture(cub, &cub->texture.east, file, &i);
		else if (ft_strncmp(&file[i], "F", 1) == 0)
			get_color(cub, &cub->floor, file, &i);
		else if (ft_strncmp(&file[i], "C", 1) == 0)
			get_color(cub, &cub->ceiling, file, &i);
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
		free_and_print(cub, "Error!\nInvalid Path or File Not Found.\n", 2);
	while (i > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		i = read(fd, buffer, BUFFER_SIZE);
		file = ft_strjoint(file, buffer);
	}
	close(fd);
	if (file != NULL)
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
		//free_and_print(cub, "Invalid map!", 2);
	//cub->floor.color = 0x555511;
	//cub->ceiling.color = 0x5599f1;
	return (1);
}
