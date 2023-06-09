/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_values2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:23:15 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/09 15:44:53 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	color(char *str, int *i)
{
	int	rgb;

	rgb = 0;
	if (ft_atoi(str + *i) >= 0 && ft_atoi(str + *i) <= 255)
	{
		rgb = ft_atoi(str + *i);
		while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
	return (rgb);
}

int	check_color(char *str, int i)
{
	int	result;
	int	rgb;
	int	rgb1;
	int	rgb2;

	if (str && str[i])
	{
		rgb = color(str, &i);
		if (str[i] && str[i] == ',')
		{
			i++;
			rgb1 = color(str, &i);
			if (str[i] && str[i] == ',')
			{
				i++;
				rgb2 = color(str, &i);
				if (str[i] == '\0')
				{
					result = (rgb << 16) | (rgb1 << 8) | (rgb2);
					return (result);
				}
			}
		}
	}
	return (1);
}

int	fill_values(char **line, t_dir *dir, int i)
{
	int	check_value;

	check_value = ft_check(line[i]);
	if (check_value == 1 && check_file(line[i], 3) == 0)
		dir->north = ft_strdup(line[i] + 3);
	else if (check_value == 2 && check_file(line[i], 3) == 0)
		dir->south = ft_strdup(line[i] + 3);
	else if (check_value == 3 && check_file(line[i], 3) == 0)
		dir->west = ft_strdup(line[i] + 3);
	else if (check_value == 4 && check_file(line[i], 3) == 0)
		dir->east = ft_strdup(line[i] + 3);
	else if (check_value == 5 || check_value == 6)
		fill_color(line, dir, i);
	return (check_value != 0);
}
