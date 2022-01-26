/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:51:25 by gjacinta          #+#    #+#             */
/*   Updated: 2022/01/26 19:30:14 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_result(t_data	*data)
{
	mlx_clear_window(data->mlx, data->win);
	data->endgame = 1;
	mlx_put_image_to_window(data->mlx, data->win, data->graphics->win,
		data->width * 40 / 2.4, data->height * 40 / 4);
}

void	ft_setchar(t_data	*data)
{
	int	i;
	int	j;
	int	ex;

	i = 0;
	j = 0;
	ex = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				data->player_c += 1;
			else if (data->map[j][i] == 'E')
				ex++;
			else if (data->map[j][i] == 'C')
				data->count_c += 1;
			i++;
		}
		j++;
	}
	ft_setchar2(data, ex);
}

void	ft_charcheck(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P' || data->map[j][i] == 'E'
					|| data->map[j][i] == '1' || data->map[j][i] == 'C'
					|| data->map[j][i] == '0')
				i++;
			else
			{
				printf("ERROR! INVALID CHAR ON MAP!");
				exit(EXIT_FAILURE);
			}
		}
		i = 0;
		j++;
	}
}

void	ft_formatcheck(t_data *data)
{
	char	*ber;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	ber = "ber";
	len = ft_strlen(data->fn);
	if (len < 3)
	{
		printf("ERROR! WRONG MAP EXTENSION!");
		exit(EXIT_FAILURE);
	}
	i = len - 3;
	while (data->fn[i] != '\0' && ber[j] != '\0')
	{
		if (data->fn[i] != ber[j])
		{
			printf("ERROR!\nCHECK FILE EXTENSION!");
			exit(EXIT_FAILURE);
		}
		i++;
		j++;
	}
}

void	ft_wallcheck(t_data	*data)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			err++;
		i++;
	}
	i = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->height - 1][i] != '1')
			err++;
		i++;
	}
	if (err > 0)
	{
		printf("ERROR. INVALID WALLS!");
		exit(EXIT_FAILURE);
	}
}
