/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:12:50 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/21 08:50:37 by gecarval         ###   ########.fr       */
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
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		simple_free(cub, "Error!\nMLX Initialization Failed.\n", 2);
	load_map(cub, av[1]);
	if (map_validator(cub))
		return (1);
	cub->window = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	if (cub->window == NULL)
		simple_free(cub, "Error!\nWindow creation failed.\n", 2);
	hook(cub);
	mlx_loop(cub->mlx);
	free(cub);
	return (0);
}
