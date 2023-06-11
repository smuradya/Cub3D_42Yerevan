/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:16:20 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/11 23:46:14 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	read_file(t_map *map, char *filename, char *line)
{
	int	i;

	map->fd = open(filename, O_RDONLY);
	i = -1;
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		map->line[++i] = ft_strdup(line);
		map->line[i][ft_strlen(line) - 1] = 0;
		map->index = i;
		free(line);
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
		free_exit_map(map, "File error");
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		++count;
		free (line);
	}
	close (map->fd);
	map->line = malloc(sizeof(char *) * (count + 1));
	map->line[count] = 0;
	read_file(map, filename, line);
	return (0);
}
