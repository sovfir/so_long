/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:47 by gjacinta          #+#    #+#             */
/*   Updated: 2022/01/22 17:20:36 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_main_init(t_data	*main, char *name)
{
	main->fn = name;
	main->height = 0;
	main->width = 0;
	main->count_c = 0;
	main->pos_x = 0;
	main->pos_y = 0;
	main->moves = 0;
	main->player_c = 0;
	main->door_open = 0;
	init_pics(main);
	printf("ft_main_init\n");
}

void	init_pics(t_data *main)
{
	int	img_weight;
	int	img_height;

	main->graphics = malloc(sizeof(t_graphics));
	main->graphics->key = mlx_xpm_file_to_image(main->mlx, KEY,
			&img_height, &img_weight);
	main->graphics->wall = mlx_xpm_file_to_image(main->mlx, WALL,
			&img_weight, &img_height);
	main->graphics->space = mlx_xpm_file_to_image(main->mlx, SPACE,
			&img_weight, &img_height);
	main->graphics->exit_c = mlx_xpm_file_to_image(main->mlx, EXIT_C,
			&img_weight, &img_height);
	main->graphics->win = mlx_xpm_file_to_image(main->mlx, WIN,
			&img_weight, &img_height);
	main->graphics->player = mlx_xpm_file_to_image(main->mlx, PLAYER,
			&img_weight, &img_height);
	printf("init_pics\n");
}