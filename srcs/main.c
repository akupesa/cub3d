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

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = NULL;
	if (ac != 2)
		free_and_print(cub, "Error!\nFew or many arguments.\n", 2);
	cub = ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		free_and_print(cub, "Error!\nFailed on main struct allocation.\n", 2);
	cub->mlx.ptr = mlx_init();
	if (cub->mlx.ptr == NULL)
		free_and_print(cub, "Error!\nMLX initialization failed.\n", 2);
	cub->mlx.window = mlx_new_window(cub->mlx.ptr, WIDTH, HEIGHT, "cub3d");
	if (cub->mlx.window == NULL)
		free_and_print(cub, "Error!\nWindow creation failed.\n", 2);
	load_map(cub, av[1]);
	render_background(cub);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.window,
		cub->background.ptr, 0, 0);
	mlx_hook(cub->mlx.window, 2, 1l << 0, control_cub, cub);
	mlx_hook(cub->mlx.window, 17, 0, free_all, cub);
	mlx_loop_hook(cub->mlx.ptr, cub_loop, cub);
	mlx_loop(cub->mlx.ptr);
	return (free_all(cub, 0));
}
