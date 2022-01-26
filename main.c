/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:55:30 by gjacinta          #+#    #+#             */
/*   Updated: 2022/01/26 19:10:09 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_allcheck(t_data	*data)
{
	ft_setchar(data);
	ft_charcheck(data);
	ft_formatcheck(data);
	ft_wallcheck(data);
}

int	ft_frame(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_put_map(data);
	if (data->count_c == 0 && data->player_c == 1 && data->door_open == 1)
	{
		ft_result(data);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{	
		data.mlx = mlx_init();
		ft_main_init(&data, argv[1]);
		ft_mapheight(&data);
		ft_readmap(&data);
		ft_allcheck(&data);
		data.win = mlx_new_window(data.mlx, data.width * 40,
				data.height * 40, "SO_LONG");
		mlx_hook(data.win, 17, 0, ft_exit_empty, &data);
		mlx_hook(data.win, 02, 0, ft_press_button, &data);
		mlx_loop_hook(data.mlx, ft_frame, &data);
		mlx_loop(data.mlx);
	}
}
