/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:16:20 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/09 14:50:57 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	read_file(t_map *map, char *filename, char *line)
{
	int	i;

	map->fd = open(filename, O_RDONLY);
	line = get_next_line(map->fd);
	i = -1;
	while (line)
	{
		map->line[++i] = line;
		map->line[i][ft_strlen(line) - 1] = 0;
		map->index = i;
		line = get_next_line(map->fd);
	}
}

int	parsing(char *filename, t_map *map)
{
	int		i;
	int		count;
	char	*line;

	i = -1;
	line = NULL;
	count = 0;
	map->fd = open(filename, O_RDONLY);
	if (map->fd == -1)
		free_exit("File error");
	line = get_next_line(map->fd);
	while (line)
	{
		++count;
		line = get_next_line(map->fd);
	}
	close (map->fd);
	map->line = malloc(sizeof(char *) * (count + 1));
	map->line[count] = 0;
	read_file(map, filename, line);
	return (0);
}
