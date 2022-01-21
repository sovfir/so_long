/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:49:52 by gjacinta          #+#    #+#             */
/*   Updated: 2022/01/21 21:36:08 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "../so_long.h"

char	*ft_new_string(char *memory)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i])
	{
		free(memory);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(memory) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (memory[i])
		str[j++] = memory[i++];
	str[j] = '\0';
	free(memory);
	return (str);
}

char	*ft_put_line(char *memory)
{
	int		i;
	char	*str;

	i = 0;
	if (!memory[i])
		return (NULL);
	while (memory[i] && memory[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		str[i] = memory[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_string(int fd, char *memory)
{
	char	*tmp;
	int		byte;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	byte = 1;
	while (!ft_strchr(memory, '\n') && byte != 0)
	{
		byte = read (fd, tmp, BUFFER_SIZE);
		if (byte == -1)
		{
			free (tmp);
			return (NULL);
		}
		tmp[byte] = '\0';
		memory = ft_strjoin(memory, tmp);
	}
	free (tmp);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	memory[fd] = ft_read_string(fd, memory[fd]);
	if (!memory[fd])
		return (NULL);
	line = ft_put_line(memory[fd]);
	memory[fd] = ft_new_string(memory[fd]);
	return (line);
}
