/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:55:57 by anhakob2          #+#    #+#             */
/*   Updated: 2023/04/29 16:58:10 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// char **fill_map(char **line, char **map)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	j = -1;
// 	while (line[++i] == NULL)
// 		;
// 	i--;
// 	while(line[++i])
// 	{
// 		map[++j] = line[i];
// 		line[i] = NULL;
// 		// printf("map -%s-\n", map[j]);
// 	}
// 	map[j] = NULL;
// 	// j = 0;
// 	// while (map[j++])
// 	// 	printf("map = %s\n", map[j]);
// 		// printf("map = %s\n", map[j]);
// 	return(map);
// }

void	fill_map(char **line, char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (line[++i] == NULL)
		;
	i--;
	while(line[++i])
	{
		map[++j] = line[i];
		line[i] = NULL;
		// printf("map -%s-\n", map[j]);
	}
	// j = 0;
	// while (map[j++])
	// 	printf("map = %s\n", map[j]);
		// printf("map = %s\n", map[j]);
	// return(map);
}

int	space_before(char *str)
{
	int i;

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