/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:12:50 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:44:31 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = NULL;
	if (ac != 2)
		simple_free(cub, "Error!\nFew or Many Arguments.\n", 2);
	cub = ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		simple_free(cub, "Error!\nFailed on Main Struct Allocation.\n", 2);
	cub->mlx.ptr = mlx_init();
	if (cub->mlx.ptr == NULL)
		simple_free(cub, "Error!\nMLX Initialization Failed.\n", 2);
	load_map(cub, av[1]);
	if (map_validator(cub))
		return (1);
	cub->mlx.window = mlx_new_window(cub->mlx.ptr, WIDTH, HEIGHT, "cub3d");
	if (cub->mlx.window == NULL)
		simple_free(cub, "Error!\nWindow creation failed.\n", 2);
	cub->floor.color = 0x008FBC8F;
	cub->ceiling.color = 0x009400D3;
	render_background(cub);
	hook(cub);
	mlx_loop(cub->mlx.ptr);
	free(cub);
	return (0);
}
