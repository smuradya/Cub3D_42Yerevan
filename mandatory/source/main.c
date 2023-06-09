/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:16:20 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/09 15:05:50 by anhakob2         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	*map;
	t_dir	*dir;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (arg_validation(argc, argv[1]) != 0)
		return (1);
	dir = malloc (sizeof(t_dir));
	if (!(dir))
		return (1);
	map = malloc (sizeof(t_map));
	parsing(argv[1], map);
	check_validation(map, dir);
	cub_init(dir, data);
	return (0);
}
