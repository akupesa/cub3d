/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:12:50 by akupesa           #+#    #+#             */
/*   Updated: 2025/05/29 12:31:29 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	extension_validator(t_cub *cub, char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4)
		free_and_print(cub, "Error!\nInvalid file extension.\n", 2);
	if (file_name[len - 4] == '.' && file_name[len - 3] == 'c' && file_name[len
			- 2] == 'u' && file_name[len - 1] == 'b')
		return ;
	else
		free_and_print(cub, "Error!\nInvalid file extension.\n", 2);
}

static void	args_counter(t_cub *cub, int ac)
{
	if (ac < 2)
		free_and_print(cub, "Error!\nFew arguments.\n", 2);
	else if (ac > 2)
		free_and_print(cub, "Error!\nMany arguments.\n", 2);
	else
		return ;
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = NULL;
	args_counter(cub, ac);
	extension_validator(cub, av[1]);
	cub = ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		free_and_print(cub, "Error!\nFailed on main struct allocation.\n", 2);
	cub->mlx.ptr = mlx_init();
	if (cub->mlx.ptr == NULL)
		free_and_print(cub, "Error!\nMLX initialization failed.\n", 2);
	cub->mlx.width = WIDTH;
	cub->mlx.height = HEIGHT;
	cub->mlx.window = mlx_new_window(cub->mlx.ptr,
			cub->mlx.width, cub->mlx.height, "cub3d");
	if (cub->mlx.window == NULL)
		free_and_print(cub, "Error!\nWindow creation failed.\n", 2);
	load_map(cub, av[1]);
	mlx_hook(cub->mlx.window, 2, 1l << 0, control_cub, cub);
	mlx_key_hook(cub->mlx.window, control_release_cub, cub);
	mlx_hook(cub->mlx.window, 17, 0, free_all, cub);
	mlx_loop_hook(cub->mlx.ptr, cub_loop, cub);
	mlx_loop(cub->mlx.ptr);
	return (free_all(cub, 0));
}
