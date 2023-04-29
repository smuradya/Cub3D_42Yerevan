/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:25:37 by anhakob2          #+#    #+#             */
/*   Updated: 2023/04/29 17:01:21 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int			ft_map_wall(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	while (str && str[i] && str[i] == '1')
		i++;
	if (str && str[i] == '\0')
		return (0);
	return (1);
}

int		ft_around(char *s1, char *s, char *s2)
{
	int i;
	int l;
	int j;

	i = 0;
	l = 0;
	j = 0;
	while (s && s[i])
	{
		if ((s[i] == '0' || s[i] == 'N' ||
			s[i] == 'E' || s[i] == 'W' ||
			s[i] == 'S') && (s[i + 1] == ' ' ||
			s1[i] == ' ' || s2[i] == ' '))
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

int			ft_wall_around(char *str)
{
	int i;

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

int			ft_other_char(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != '1' && str[i] != '0' &&
			str[i] != 'N' && str[i] != 'S' && str[i] != 'W' &&
			str[i] != 'E' && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_pos(char *str)
{
	int i;
	int error;

	i = 0;
	error = 0;
	while (str && str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			error++;
		i++;
	}
	return (error);
}

void	check_map(char **map, int i, int index)
{
	if (map[0])
	{
		while (map && map[i] && space_before(map[i]) == 0)
		{
			if (i == 0 && (ft_map_wall(map[i]) == 1 || ft_wall_around(map[i]) == 1))
			{
				printf("Wall error\n");
				exit (1);
			}
			if (map[i + 1] == 0)
			{
				if (ft_map_wall(map[i]) == 1)
				{
					printf("Wall error 1\n");
					exit (1);
				}
			}
			if (i > 0 && map[i + 1] != 0 && ft_around(map[i - 1], map[i], map[i + 1]) == 1)
			{
				printf("Map error\n");
				exit (1);	
			}
			if (ft_other_char(map[i]) == 1)
			{
				printf("Wrong char in the map error\n");
				exit (1);
			}
			if (ft_is_pos(map[i]) > 0)
				index = index + ft_is_pos(map[i]);
			i++;
		}
	}
	if (index > 1 || index == 0)
	{
		printf("Possition error\n");
		exit (1);
	}
}

void	check_validation(t_map	*map)
{
	int i;
	t_dir *dir;
	// char **map1 = NULL;

	if (!(dir = malloc (sizeof(t_dir))))
		return ;
	if ((map->line[1][1] == '1' || map->line[1][1] == '0')
		&& map->line[map->index][1] != '1')
	{
		printf("file is incorrect");
		exit(1);
	}
	i = -1;
	int index = 0;
	while(map->line[++i])
	{
		fill_values(map->line, dir, i);
		if (map->line[i] != NULL)
		{
			// printf("-%s-\n", map->line[i]);
			++index;
		}
	}
	// printf("%d\n", index);
	// map1 = (char **)malloc(sizeof(char *));
	dir->map = malloc(sizeof(char *) * (index + 1));
	dir->map[index] = 0;
	// dir->map = fill_map(map->line, map1);
	fill_map(map->line, dir->map);
	int l = -1;
	while (dir->map[++l])
	printf("line{%s}\n", dir->map[l]);
	check_map(dir->map, 0, 0);
	cub_init(dir);
	printf("north = %s\n", dir->north);
	printf("south = %s\n", dir->south);
	printf("east = %s\n", dir->east);
	printf("west = %s\n", dir->west);
	printf("floor = %d\n", dir->floor);
	printf("ceiling = %d\n", dir->ceiling);
}