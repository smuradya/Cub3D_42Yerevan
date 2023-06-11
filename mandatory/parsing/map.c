/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:55:57 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/11 21:29:31 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_maxlen(char **line)
{
	int	i;
	int	max_len;
	int	line_len;

	i = -1;
	max_len = ft_strlen(line[0]);
	while (line[++i])
	{
		line_len = ft_strlen(line[i]);
		if (line_len > max_len)
			max_len = line_len;
	}
	return (max_len);
}

void	fill_map(char **line, char **map)
{
	int	i;
	int	k;
	int	max_len;
	int	line_len;

	i = -1;
	max_len = get_maxlen(line);
	while (line[++i])
	{
		map[i] = malloc(max_len + 1);
		map[i][max_len] = 0;
		k = -1;
		line_len = ft_strlen(line[i]);
		while (++k < max_len)
		{
			if (k < line_len)
				map[i][k] = line[i][k];
			else
				map[i][k] = ' ';
		}
	}
}

int	space_before(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	if (str[i] == '1' || str[i] == '0' || str[i] == 'N' || str[i] == 'E'
		|| str[i] == 'S' || str[i] == 'W')
		return (0);
	return (1);
}
