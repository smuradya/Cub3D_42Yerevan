/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:16:20 by anhakob2          #+#    #+#             */
/*   Updated: 2023/05/08 14:30:30 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void setup_player(t_data *data, int x, int y)
// {
//  if (data->map_data.map[x][y] == 'N')
//   data->player.dir = new_vector(-1, 0.01);
//  else if (data->map_data.map[x][y] == 'E')
//   data->player.dir = new_vector(0.01, 1);
//  else if (data->map_data.map[x][y] == 'W')
//   data->player.dir = new_vector(0.01, -1);
//  else if (data->map_data.map[x][y] == 'S')
//   data->player.dir = new_vector(1, 0.01);
// }

void xpm_to_image(t_dir *dir, t_data *data)
{
	int w_h[] = {64,64};
	data->img_east = mlx_xpm_file_to_image(data->mlx, dir->east, &w_h[0], &w_h[1]);	
	data->img_west = mlx_xpm_file_to_image(data->mlx, dir->west, &w_h[0], &w_h[1]);	
	data->img_south = mlx_xpm_file_to_image(data->mlx, dir->south, &w_h[0], &w_h[1]);	
	data->img_north = mlx_xpm_file_to_image(data->mlx, dir->north, &w_h[0], &w_h[1]);	
}


void	cub_init(t_dir *dir, t_data *data)
{
	// t_data  *data;

	// data = malloc(sizeof(t_data));
    data->player.pos = new_vector(17, 7);
    data->player.dir = new_vector(-1, 0);
    data->plane = new_vector(0, 0.66);
    data->map_data.map = dir->map;
	data->map_data.ceiling = dir->ceiling;
	data->map_data.floor = dir->floor;

	// int i = -1;
	// while (data->map_data.map[++i])
	// 	printf("line[%d] = %s\n", i, data->map_data.map[i]);
    data->draw.step_x = 0;
    data->draw.step_y = 0;
    data->draw.side = 0;
    data->player.wall_dis = 0.0;
    data->mouse = init_mouse();
    data->mlx = mlx_init();
    //data->mouse.horiz = 0.06;
    //data->mouse.vertic = 0.06;
    data->window = mlx_new_window(data->mlx, 720, 720, "Cub 3D");
	data->frame = malloc(sizeof(t_img));
	t_img	*frame = data->frame;
	frame->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HIGHT);
	frame->data_addr = mlx_get_data_addr(frame->img,
		&frame->bits_per_pixel, &frame->size_line, &frame->endian);
	xpm_to_image(dir, data);
    game_start(data);
	//printf("BAAAAAARRRREEEEV\n");
    mlx_hook(data->window, 2, 1L<<0, key_code, data);
    mlx_hook(data->window, 17, 0L, esc_code, data);
    mlx_hook(data->window, 6, 0L, mouse_move, data);
    mlx_loop(data->mlx);
}

int parsing(char *filename, t_map *map)
{
	int		i;
	char	*line;
	
	i = -1;
	line = NULL;
	map->fd = open(filename, O_RDONLY);
	if (map->fd == -1)
	{
		write (1, "File error\n", 11);
		return (1);
	}
	line = get_next_line(map->fd);
    int count = 0;
    while (line)
    {
		if (ft_strcmp(line, "\n"))
        	++count;
        line = get_next_line(map->fd);
    }
    close(map->fd);
    map->line = malloc(sizeof(char *) * (count + 1));
    map->line[count] = 0;
	map->fd = open(filename, O_RDONLY);
    line = get_next_line(map->fd);
    i = -1;
    while (line)
    {
		if (ft_strcmp(line, "\n"))
		{
        	map->line[++i] = line;
			map->line[i][ft_strlen(line) - 1] = 0;
			map->index = i;
		}
        line = get_next_line(map->fd);
    }
    // i = -1;
    // while (map->line[++i])
    // {
    //     write(1, map->line[i], strlen(map->line[i]));
    //     write(1, "\n", 1);
    // }
    

	// while ((line = get_next_line(map->fd)) != 0)
	// {
	// 	if(ft_strcmp(line, "\n") != 0)
	// 	{
	// 		line[ft_strlen(line) - 1] = 0;
	// 		map->line[++i] = ft_strdup(line);
	// 		printf("-%s-\n", map->line[i]);
	// 		map->index = i;
	// 	}
	// 	free(line);
	// }
	// map->line[++i] = "\0";
	// printf("%d\n", map->index);
	// check_validation(map);
	return (0);
}