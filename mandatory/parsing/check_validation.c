/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:25:37 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/08 20:55:53 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_map_wall(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	while (str && str[i] && str[i] == '1')
		i++;
	if (str && str[i] == '\0')
		return (0);
	return (1);
}

int	ft_around(char *s1, char *s, char *s2)
{
	int	i;
	int	l;
	int	j;

	i = 0;
	l = 0;
	j = 0;
	while (s && s[i])
	{
		if ((s[i] == '0' || s[i] == 'N'
				|| s[i] == 'E' || s[i] == 'W'
				|| s[i] == 'S') && (s[i + 1] == ' '
				|| s1[i] == ' ' || s2[i] == ' '))
			return (1);
		i++;
	}
	i = 0;
	while (s && s[i])
		i++;
	while (s && s[i] != '0' && i > 0)
		i--;
	l = ft_strlen(s1);
	if (i >= l)
		return (1);
	j = ft_strlen(s2);
	if (i >= j)
		return (1);
	return (0);
}

int	ft_wall_around(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	if (str && str[i] && str[i] != '1')
		return (1);
	while (str && str[i])
		i++;
	i--;
	if (str && str[i] != '1')
		return (1);
	return (0);
}

int	ft_other_char(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != '1' && str[i] != '0'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W'
			&& str[i] != 'E' && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_pos(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			++count;
		i++;
	}
	return (count);
}

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
				|| map[i][j + 1] == '\t'))
			{
				printf ("MAP ERROR\n");
				exit (1);
			}
			if ((map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S') && (map[i][j - 1] == '\n'
				|| map[i][j - 1] == ' ' || map[i][j - 1] == '\0'
				|| map[i][j - 1] == '\t'))
			{
				printf ("MAP ERROR\n");
				exit (1);
			}
			if ((map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S') && (map[i + 1][j] == '\n'
				|| map[i + 1][j] == ' ' || map[i + 1][j] == '\0'
				|| map[i + 1][j] == '\t'))
			{
				printf ("MAP ERROR\n");
				exit (1);
			}
			if ((map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S') && (map[i - 1][j] == '\n'
				|| map[i - 1][j] == ' ' || map[i - 1][j] == '\0'
				|| map[i - 1][j] == '\t'))
			{
				printf ("MAP ERROR\n");
				exit (1);
			}
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
	{
		printf("file is incorrect");
		exit(1);	
	}
	i = -1;
	while (map->line[++i])
	{
		if (!map->line[i][0])
			continue ;
		if (!fill_values(map->line, dir, i))
			break ;
	}
	map_size = map->index - i + 1;
	printf("i = %d\n", map_size);
	dir->map = malloc(sizeof(char *) * (map_size + 1));
	dir->map[map_size] = 0;
	fill_map(map->line + i, dir->map);
	if (dir->east == 0 || dir->west == 0 || dir->south == 0 || dir->north == 0)
	{
		printf("file is incorrect");
		exit(1);
	}
	i = -1;
	while (dir->map[++i])
		printf("%s\n", dir->map[i]);
	ft_val_map(dir->map);
	find_position(dir);
}
