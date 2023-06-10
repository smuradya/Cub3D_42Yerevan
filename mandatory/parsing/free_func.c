/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:13:12 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/09 21:17:48 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_exit_dir(t_dir *dir, char *str)
{
	int	i;

	i = -1;
	if (dir)
	{
		while (dir->map[++i])
			free(dir->map[i]);
		if (dir->east)
			free(dir->east);
		if (dir->south)
			free(dir->south);
		if (dir->west)
			free(dir->west);
		if (dir->north)
			free(dir->north);
	}
	free (dir);
	if (str != NULL)
	{
		printf ("%s\n", str);
		exit (1);
	}
}

void	free_exit(char *str)
{	
	printf ("%s\n", str);
	exit (1);
}

void	free_exit_map(t_map *map, char *str)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map)
		{
			if (map->line[i])
				free(map->line[i]);
			i++;
		}
	}
	free(map);
	if (str != NULL)
	{
		printf ("%s\n", str);
		exit (1);
	}
}
