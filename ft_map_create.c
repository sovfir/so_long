/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:00:26 by gjacinta          #+#    #+#             */
/*   Updated: 2022/01/22 18:07:52 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_empty(t_data	*data)
{
	(void)	*data;
	exit(EXIT_SUCCESS);
}

void	ft_put_hero(t_data	*data, int	*j,	int	*i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->graphics->player, (*j) * 40, (*i) * 40);
	data->pos_y = *i;
	data->pos_x = *j;
}

void	ft_put_wall(t_data	*data, int	*j, int	*i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->graphics->wall, (*j) * 40, (*i) * 40);
}

void	ft_put_space(t_data	*data, int	*j, int	*i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->graphics->space, (*j) * 40, (*i) * 40);
}

void	ft_put_map(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				ft_put_wall(data, &j, &i);
			else if (data->map[i][j] == '0')
				ft_put_space(data, &j, &i);
			else if (data->map[i][j] == 'P')
				ft_put_hero(data, &j, &i);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->graphics->exit_c, j * 40, i * 40);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->graphics->key, j * 40, i * 40);
			j++;
		}
		j = 0;
		i++;
	}
}