/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:41:58 by akupesa           #+#    #+#             */
/*   Updated: 2025/05/28 15:57:08 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_color_number(t_cub *cub, int *i)
{
	int		j;
	int		num;
	char	*file;

	j = 0;
	num = 0;
	file = cub->map.file;
	if (!ft_isdigit(file[*i]))
		num = 256;
	while (file[*i] != '\0' && file[*i] != '\n' && file[*i] != ',')
	{
		if (j++ > 3 || !ft_isdigit(file[*i]))
			free_and_print(cub, "Error!\nWrong color format.\n", 2);
		num = (num * 10) + (file[(*i)++] - '0');
	}
	if (num > 255 || j > 3)
		free_and_print(cub, "Error!\nWrong color value.\n", 2);
	return (num);
}

void	get_color(t_cub *cub, t_texture *rsc, int *i)
{
	int		j;
	char	*file;

	j = -1;
	file = cub->map.file;
	while (file[*i] != '\0' && (file[*i] != ' ' && file[*i] != '\t'))
		(*i)++;
	while (file[*i] != '\0' && (file[*i] == ' ' || file[*i] == '\t'))
		(*i)++;
	if (rsc->color != -1)
		free_and_print(cub, "Error!\nRepetead Color.\n", 2);
	while (++j < 3)
	{
		rsc->color = (rsc->color << 8) + get_color_number(cub, i);
		if (file[*i] != '\0' && file[*i] != '\n' && file[*i] == ',' && j == 2)
			free_and_print(cub, "Error!\nWrong color format.\n", 2);
		if (file[*i] != '\0' && file[*i] != '\n' && file[*i] == ',')
			(*i)++;
	}
}

void	get_texture(t_cub *cub, t_texture *rsc, int *i)
{
	int		len;
	char	*file;

	file = cub->map.file;
	while (file[*i] != '\0' && file[*i] != ' ' && file[*i] != '\t')
		(*i)++;
	while (file[*i] != '\0' && (file[*i] == ' ' || file[*i] == '\t'))
		(*i)++;
	len = *i;
	while (file[len] != '\0' && file[len] != ' ' && file[len] != '\n')
		len++;
	if (rsc->path == NULL)
		rsc->path = ft_substr(file, *i, len - *i);
	printf("|%s|\n", rsc->path);
	if (rsc->img.ptr != NULL)
		free_and_print(cub, "Error!\nRepetead texture source.\n", 2);
	rsc->img.ptr = mlx_xpm_file_to_image(cub->mlx.ptr,
			rsc->path, &rsc->width, &rsc->height);
	if (rsc->img.ptr == NULL)
		free_and_print(cub, "Error!\nNo texture source file found.\n", 2);
	*i = len;
	while (file[*i] != '\0' && (file[*i] == ' ' || file[*i] == '\t'))
		(*i)++;
	if (file[*i] != '\n')
		free_and_print(cub, "Error!\nWrong file format.\n", 2);
}

int	get_file_data(t_cub *cub)
{
	int		i;

	i = -1;
	while (cub->map.file[++i] != '\0')
	{
		if (ft_strncmp(&cub->map.file[i], "NO", 2) == 0)
			get_texture(cub, &cub->texture.north, &i);
		else if (ft_strncmp(&cub->map.file[i], "SO", 2) == 0)
			get_texture(cub, &cub->texture.south, &i);
		else if (ft_strncmp(&cub->map.file[i], "WE", 2) == 0)
			get_texture(cub, &cub->texture.west, &i);
		else if (ft_strncmp(&cub->map.file[i], "EA", 2) == 0)
			get_texture(cub, &cub->texture.east, &i);
		else if (ft_strncmp(&cub->map.file[i], "F", 1) == 0)
			get_color(cub, &cub->floor, &i);
		else if (ft_strncmp(&cub->map.file[i], "C", 1) == 0)
			get_color(cub, &cub->ceiling, &i);
		else if (cub->map.file[i] != ' ' && cub->map.file[i] != '\t'
			&& cub->map.file[i] != '\n')
			break ;
	}
	while (cub->map.file[i] != '\0' && cub->map.file[i] != '\n' && i > 0)
		i--;
	return (i);
}

void	get_file(t_cub *cub, const char *file_name)
{
	int		i;
	int		fd;
	char	buffer[BUFFER_SIZE + 1];

	i = 1;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		free_and_print(cub, "Error!\nFailed to open file.\n", 2);
	while (i > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0 && cub->map.file == NULL)
			free_and_print(cub, "Error!\nEmpty file.\n", 2);
		cub->map.file = ft_strjoint(cub->map.file, buffer);
	}
	close(fd);
	i = get_file_data(cub);
	cub->map.matrix = ft_split(&cub->map.file[i], '\n');
	is_map_empty(cub, i);
}
