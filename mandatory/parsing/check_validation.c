/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:25:37 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/11 23:19:48 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_position(t_dir *dir)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (dir->map[++i])
	{
		j = 0;
		while (dir->map[i][j])
		{
			if (dir->map[i][j] == 'N' || dir->map[i][j] == 'S' ||
				dir->map[i][j] == 'W' || dir->map[i][j] == 'E')
			{
				dir->x = i;
				dir->y = j;
				dir->player_direction = dir->map[i][j];
			}
			j++;
		}
	}
}

void	check_map(char **map)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	while (map[++i])
	{
		index += index + ft_is_pos(map[i]);
		if (ft_other_char(map[i]) == 1)
		{
			printf("Wrong char in the map error\n");
			exit (1);
		}
	}
	if (index != 1)
	{
		printf("Possition error %d\n", index);
		exit (1);
	}
}

void	ft_val_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S') && (map[i][j + 1] == '\n'
				|| map[i][j + 1] == ' ' || map[i][j + 1] == '\0'
				|| map[i][j + 1] == '\t' || map[i][j - 1] == '\n'
				|| map[i][j - 1] == ' ' || map[i][j - 1] == '\0'
				|| map[i][j - 1] == '\t' || map[i + 1][j] == '\n'
				|| map[i + 1][j] == ' ' || map[i + 1][j] == '\0'
				|| map[i + 1][j] == '\t' || map[i - 1][j] == '\n'
				|| map[i - 1][j] == ' ' || map[i - 1][j] == '\0'
				|| map[i - 1][j] == '\t'))
				free_exit("Map Error");
		}
	}
}

void	check_validation(t_map	*map, t_dir *dir)
{
	int	i;
	int	map_size;
	int	last_row_check;

	last_row_check = ft_check(map->line[map->index]);
	if (last_row_check >= 1 && last_row_check <= 6)
		free_exit_map(map, "File is incorrect");
	i = -1;
	while (map->line[++i])
	{
		if (!map->line[i][0])
			continue ;
		if (!fill_values(map->line, dir, i))
			break ;
	}
	map_size = map->index - i + 1;
	dir->map = malloc(sizeof(char *) * (map_size + 1));
	dir->map[map_size] = 0;
	fill_map(map->line + i, dir->map);
	if (dir->east == 0 || dir->west == 0 || dir->south == 0 || dir->north == 0)
		free_exit_dir(dir, "File is incorrect");
	ft_val_map (dir->map);
	find_position (dir);
}
