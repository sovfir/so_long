/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:07:46 by gjacinta          #+#    #+#             */
/*   Updated: 2022/01/26 19:11:45 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_w(t_data *data)
{
	if (data->map[data->pos_y - 1][data->pos_x] != '1')
	{
		if (data->map[data->pos_y - 1][data->pos_x] == 'C')
		{
			data->map[data->pos_y][data->pos_x] = '0';
			data->map[data->pos_y - 1][data->pos_x] = 'P';
			data->count_c--;
		}
		else if (data->map[data->pos_y - 1][data->pos_x] == '0')
		{
			data->map[data->pos_y][data->pos_x] = '0';
			data->map[data->pos_y - 1][data->pos_x] = 'P';
		}
		else if (data->map[data->pos_y - 1][data->pos_x] == 'E'
			&& data->count_c == 0)
			data->door_open = 1;
		data->pos_y--;
		data->moves++;
		printf("MOVES: %d\n", data->moves);
	}
}

void	ft_move_s(t_data *data)
{
	if (data->map[data->pos_y + 1][data->pos_x] != '1')
	{
		if (data->map[data->pos_y + 1][data->pos_x] == 'C')
		{
			data->map[data->pos_y][data->pos_x] = '0';
			data->map[data->pos_y + 1][data->pos_x] = 'P';
			data->count_c--;
		}
		else if (data->map[data->pos_y + 1][data->pos_x] == '0')
		{
			data->map[data->pos_y][data->pos_x] = '0';
			data->map[data->pos_y + 1][data->pos_x] = 'P';
		}
		else if (data->map[data->pos_y + 1][data->pos_x] == 'E'
			&& data->count_c == 0)
			data->door_open = 1;
		data->pos_y++;
		data->moves++;
		printf("MOVES: %d\n", data->moves);
	}
}

void	ft_move_a(t_data *data)
{
	if (data->map[data->pos_y][data->pos_x - 1] != '1')
	{
		if (data->map[data->pos_y][data->pos_x - 1] == 'C')
		{
			data->map[data->pos_y][data->pos_x] = '0';
			data->map[data->pos_y][data->pos_x - 1] = 'P';
			data->count_c--;
		}
		else if (data->map[data->pos_y][data->pos_x - 1] == '0')
		{
			data->map[data->pos_y][data->pos_x] = '0';
			data->map[data->pos_y][data->pos_x - 1] = 'P';
		}
		else if (data->map[data->pos_y][data->pos_x - 1] == 'E'
			&& data->count_c == 0)
			data->door_open = 1;
		data->pos_x--;
		data->moves++;
		printf("MOVES: %d\n", data->moves);
	}
}

void	ft_move_d(t_data *data)
{
	if (data->map[data->pos_y][data->pos_x + 1] != '1')
	{
		if (data->map[data->pos_y][data->pos_x + 1] == 'C')
		{
			data->map[data->pos_y][data->pos_x] = '0';
			data->map[data->pos_y][data->pos_x + 1] = 'P';
			data->count_c--;
		}
		else if (data->map[data->pos_y][data->pos_x + 1] == '0')
		{
			data->map[data->pos_y][data->pos_x] = '0';
			data->map[data->pos_y][data->pos_x + 1] = 'P';
		}
		else if (data->map[data->pos_y][data->pos_x + 1] == 'E'
			&& data->count_c == 0)
			data->door_open = 1;
		data->pos_x++;
		data->moves++;
		printf("MOVES: %d\n", data->moves);
	}
}

int	ft_press_button(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit_empty(data);
	if (data->endgame == 0)
	{
		if (keycode == W)
			ft_move_w(data);
		else if (keycode == A)
			ft_move_a(data);
		else if (keycode == S)
			ft_move_s(data);
		else if (keycode == D)
			ft_move_d(data);
	}
	return (0);
}
