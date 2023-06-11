/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:52:07 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/11 23:49:55 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_file(char *line, int i)
{
	int	len;
	int	fd;

	len = ft_strlen(line) - 1;
	if (line[len] != 'm' || line[len - 1] != 'p'
		|| line[len - 2] != 'x' || line[len - 3] != '.')
		free_exit("Not valid image file");
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

void	free_splitted(char **splitted)
{
	int	i;

	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	free(splitted);
}

int	values(char **splitted)
{
	int		value;

	value = 0;
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
	return (value);
}

int	ft_check(char *str)
{
	char	**splitted;
	int		value;
	int		i;

	splitted = ft_split(str, ' ');
	i = -1;
	value = 0;
	while (splitted[++i])
		;
	if (i != 2)
	{
		free_splitted(splitted);
		return (0);
	}
	value = values(splitted);
	free_splitted(splitted);
	return (value);
}

void	fill_color(char **line, t_dir *dir, int i)
{
	char	*floor;
	char	*ceiling;

	floor = NULL;
	ceiling = NULL;
	if ((ft_check(line[i]) == 5 || ft_check(line[i]) == 6)
		&& ft_strrchr(line[i], '-') == 0)
	{
		if (ft_check(line[i]) == 5)
		{
			floor = line[i];
			if (check_color(floor, 2) != 1)
				dir->floor = check_color(line[i], 2);
		}
		else if (ft_check(line[i]) == 6)
		{
			ceiling = line[i];
			if (check_color(ceiling, 2) != 1)
				dir->ceiling = check_color(line[i], 2);
		}
	}
	else
		free_exit_dir(dir, "Color error");
}
