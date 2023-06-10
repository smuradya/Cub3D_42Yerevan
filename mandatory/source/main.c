/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:16:20 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/10 21:54:17 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	arg_validation(int argc, char *argv)
{
	int	len;

	if (argc != 2)
	{
		write (1, "Argc error\n", 11);
		return (1);
	}
	len = ft_strlen(argv) - 1;
	if (argv[len] == 'b' && argv[len - 1] == 'u'
		&& argv[len - 2] == 'c' && argv[len - 3] == '.')
		return (0);
	else
		write (1, "file validation error\n", 21);
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	if (map->line)
		return ;
	while (map->line[++i])
	{
		if (!(map->line[i]))
			return ;
		free(map->line[i]);
	}
	free(map->line);
	free(map);
}

void	free_dir(t_dir *dir)
{
	int	i;

	i = -1;
	if (dir->map)
		return ;
	while (dir->map[++i])
	{
		if (!(dir->map[i]))
			return ;
		free(dir->map[i]);
	}
	free(dir->north);
	free(dir->south);
	free(dir->west);
	free(dir->east);
	free(dir->map);
	free(dir);
}

// void	free_map_dir_data(t_map *map, t_dir *dir, t_data *data)
// {
// 	int	i;
	// int	j;
// 	int	l;

// 	i = -1;
	// j = -1;
// 	l = -1;
// 	if (map)
// 	{
// 		while (map->line[++i])
// 			free(map->line[i]);
// 		free(map->line);
// 	}
// 	if (data)
// 	{
// 		// free (data->textures->east->data_addr);
// 		// free (data->textures->west);
// 		// free (data->textures->south->);
// 		// free (data->textures->north->);
// 		free (data->frame->data_addr);
// 	}
// 	if (dir)
// 	{
// 		while (dir->map[++j])
// 			free(dir->map[j]);
// 		free (dir->east);
// 		free (dir->west);
// 		free (dir->south);
// 		free (dir->north);
// 	}
// 	free (map);
// 	free (dir);
// 	free (data);
// }

int	main(int argc, char **argv)
{
	t_map	*map;
	t_dir	*dir;
	t_data	*data;

	if (arg_validation(argc, argv[1]) != 0)
		return (1);
	map = malloc (sizeof(t_map));
	parsing(argv[1], map);
	// while (map->line[++i])
	// 	printf ("{%s}\n", map->line[i]);
	dir = malloc (sizeof(t_dir));
	if (!(dir))
		return (1);
	check_validation(map, dir);
	data = malloc(sizeof(t_data));
	cub_init(dir, data);
	// mlx_destroy_image(data->mlx, data->textures->east.img);
	// mlx_destroy_image(data->mlx, data->textures->west.img);
	// mlx_destroy_image(data->mlx, data->textures->south.img);
	// mlx_destroy_image(data->mlx, data->textures->north.img);
	// free_map_dir_data(map, dir, data);
	free_dir(dir);
	free_map(map);
	// free (data);
	// sleep (1000);
	return (0);
}
