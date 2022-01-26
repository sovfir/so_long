/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:28:59 by gjacinta          #+#    #+#             */
/*   Updated: 2022/01/26 19:54:01 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_setchar2(t_data *data, int ex2)
{
	if (data->count_c == 0 || data->player_c == 0
		|| ex2 == 0 || data->player_c > 1)
	{
		printf("Error.\n WRONG MAP");
		exit(EXIT_FAILURE);
	}
}

void	ft_put_map2(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		ft_put_wall(data, &j, &i);
	else if (data->map[i][j] == '0')
		ft_put_space(data, &j, &i);
	else if (data->map[i][j] == 'P')
		ft_put_hero(data, &j, &i);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->graphics->exit_c, j * 40, i * 40);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->graphics->key, j * 40, i * 40);
}
