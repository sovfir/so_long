/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:21:20 by gjacinta          #+#    #+#             */
/*   Updated: 2022/01/21 21:31:07 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_readmap(t_data	*data)
{
int		fd;
char	*line;
int		index;

fd = open(data->fn, O_RDONLY);
line = get_next_line(fd);
data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
index = 0;
while(line)
{
	data->map[index] = line;
	line = get_next_line(fd);
	index++;
}
data->map[index] = NULL;
free(line);
line = NULL;
close(fd);
}

void	ft_mapheight(t_data *data)
{
	char	*line;
	int		fd;

	fd = open(data->fn, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		printf("Cant read file");
		exit(EXIT_FAILURE);
	}
	while(line[data->width] != '\0')
		data->width++;
	while (line)
		if ((int)ft_strlen(line) != data->width)
		{
			printf("ERROR! MAP IS NOT VALID!!!!");
			exit(EXIT_FAILURE);
		}
		data->height++;
		free(line);
		line = get_next_line(fd);
		line = NULL;
		close(fd);
}