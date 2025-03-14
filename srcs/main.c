/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:12:50 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/25 13:12:51 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	main(int ac, char **av)
{
	t_cub	*cub;

	(void)av;
	cub = NULL;
	if (ac != 2)
		simple_free(cub, "Error!\nFew or Many Arguments.\n");
	cub = ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		return (FALSE);
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
	{
		simple_free(cub, "Error!\nMLX initialization failed.\n");
		return (1);
	}
	load_map(cub, av[1]);
        map_validator(cub);
	cub->window = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	if (cub->window == NULL)
	{
		simple_free(cub, "Error!\nWindow creation failed.\n");
		return (1);
	}
	hook(cub);
	mlx_loop(cub->mlx);
	free(cub);
	return (TRUE);
}
