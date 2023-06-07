/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:52:07 by anhakob2          #+#    #+#             */
/*   Updated: 2023/05/20 15:32:44 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_file(char *line, int i)
{
	int len;
	int	fd;
	
	len = ft_strlen(line) - 1;
	if (line[len] != 'm' && line[len - 1] != 'p' &&
		line[len - 2] != 'x' && line[len - 3] != '.')
	{
		printf("Not valid image file\n");
		exit (1);
	}
	fd = open (line + i, O_RDONLY);
	if (fd == -1)
	{
		close (fd);
		printf("Cannot open %s file\n", line + i);
		exit (0);
	}
	close (fd);
	return (0);
}

int check_color(char *str, int i)
{
	int result;
	int rgb;
	int rgb1;
	int rgb2;
	
	if (str && str[i])
	{
		if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
		{
			rgb = ft_atoi(str + i);
			while (str[i] && str[i] >= '0' && str[i] <= '9')
				i++;
			if(str[i] && str[i] == ',')
			{
				i++;
				if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
				{
					rgb1 = ft_atoi(str + i);
					while (str[i] && str[i] >= '0' && str[i] <= '9')
						i++;
					if(str[i] && str[i] == ',')
					{
						i++;
						if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
						{
							rgb2 = ft_atoi(str + i);
							while (str[i] && str[i] >= '0' && str[i] <= '9')
								i++;
							if (str[i] == '\0')
							{
								result = (rgb << 16) | (rgb1 << 8) | (rgb2);
								return (result);
							}
						}
					}
				}
			}
		}
	}
	return (1);
}

int	ft_check(char *str)
{
	char	**splitted;
	int		i;
	int		value;

	splitted = ft_split(str, ' ');
	i = -1;
	while (splitted[++i])
		;
	if (i != 2)
		return (0);
	if (!ft_strcmp(splitted[0], "NO"))
		value = 1;
	else if (!ft_strcmp(splitted[0], "SO"))
		value = 2;
	else if (!ft_strcmp(splitted[0], "WE"))
		value = 3;
	else if (!ft_strcmp(splitted[0], "EA"))
		value = 4;
	else if (!ft_strcmp(splitted[0], "F"))
		value = 5;
	else if (!ft_strcmp(splitted[0], "C"))
		value = 6;
	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	free(splitted);
	return (value);
}

void fill_color(char **line, t_dir *dir, int i)
{
	char	*floor;
	char	*ceiling;

	floor = NULL;
	ceiling = NULL;
	if ((ft_check(line[i]) == 5 || ft_check(line[i]) == 6) &&
			ft_strrchr(line[i], '-') == 0)
	{
		if (ft_check(line[i]) == 5)
		{
			floor = line[i];
			if (check_color(floor, 2) != 1)
				dir->floor = check_color(line[i], 2);
			line[i] = NULL;
		}
		else if (ft_check(line[i]) == 6)
		{
			ceiling = line[i];
			if (check_color(ceiling, 2) != 1)
				dir->ceiling = check_color(line[i], 2);
			line[i] = NULL;
		}
	}
	else
	{
		write (1, "Color error\n", 12);
		exit (1);
	}
}

int	fill_values(char **line, t_dir *dir, int i)
{
	int	check_value;

	check_value = ft_check(line[i]);
	if (check_value == 1)
	{
		if (check_file(line[i], 3) == 0)
			dir->north = ft_strdup(line[i] + 3);
	}
	else if (check_value == 2)
	{
		if (check_file(line[i], 3) == 0)
			dir->south = ft_strdup(line[i] + 3);
	}
	else if (check_value == 3)
	{
		if (check_file(line[i], 3) == 0)
			dir->west = ft_strdup(line[i] + 3);
	}
	else if (check_value == 4)
	{
		if (check_file(line[i], 3) == 0)
			dir->east = ft_strdup(line[i] + 3);
	}
	else if (check_value == 5 || check_value == 6)
		fill_color(line, dir, i);
	return (check_value != 0);
}
