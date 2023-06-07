/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:16:20 by anhakob2          #+#    #+#             */
/*   Updated: 2023/05/20 17:48:40 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void setup_player(t_data *data, int x, int y)
// {
//  if (data->map_data.map[x][y] == 'NO')
//   data->player.dir = new_vector(-1, 0.01);
//  else if (data->map_data.map[x][y] == 'E')
//   data->player.dir = new_vector(0.01, 1);
//  else if (data->map_data.map[x][y] == 'W')
//   data->player.dir = new_vector(0.01, -1);
//  else if (data->map_data.map[x][y] == 'SO')
//   data->player.dir = new_vector(1, 0.01);
// }

void    player_dir(t_data *data, int x, int y)
{
    if (data->map_data.map[x][y] == 'N')
        data->player.dir = new_vector(-1, 0);
    else if (data->map_data.map[x][y] == 'E')
        data->player.dir = new_vector(0, 1);
    else if (data->map_data.map[x][y] == 'W')
        data->player.dir = new_vector(0, -1);
    else if (data->map_data.map[x][y] == 'S')
        data->player.dir = new_vector(1, 0);
	// else
    //  data->player.pos = new_vector(x, y);
    //  data->plane = new_vector(0.66 * data->player.dir.y,
    //          -0.66 * data->player.dir.x);

}

unsigned int    get_img_color(t_img img, int x, int y)
{
    char    *dst;

    if (!img.img)
        return (0);
    dst = img.data_addr + (y * img.size_line + x * (img.bits_per_pixel / 8));
    return ((unsigned int)dst);
}

unsigned int    *get_img_colors(t_img img)
{
    int                i;
    int                j;
    int                k;
    unsigned int		*ptr;

    ptr = malloc(sizeof(unsigned int) * 64 * 64);
    i = -1;
    while (++i < 64)
    {
        j = -1;
        k = 64;
        while (++j < 64 && --k > -1)
            ptr[64 * k + i] = get_img_color(img, j, i);
    }
    return (ptr);
}

t_img    img_init(void *mlx, char *addr)
{
    t_img    img;

    img.data_addr = NULL;
    img.img = mlx_xpm_file_to_image(mlx, addr,
            &img.img_width, &img.img_height);
    img.data_addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
            &img.size_line, &img.endian);
    img.texture = get_img_colors(img);
    return (img);
}

void	init_textures(t_data *data, t_dir  *dir)
{
	data->textures = malloc(sizeof(t_textures));
	data->textures->east = img_init(data->mlx, dir->east);
	data->textures->west = img_init(data->mlx, dir->west);
	data->textures->south = img_init(data->mlx, dir->south);
	data->textures->north = img_init(data->mlx, dir->north);
}


void	cub_init(t_dir *dir, t_data *data)
{
	// t_data  *data;

	// data = malloc(sizeof(t_data));
    data->player.pos = new_vector(dir->x, dir->y);
	data->player.dir = new_vector(-1, 0);
	//player_dir(data, dir->x, dir->y);
    data->plane = new_vector(0, -0.66);
    data->map_data.map = dir->map;
	data->map_data.ceiling = dir->ceiling;
	data->map_data.floor = dir->floor;

    data->draw.step_x = 0;
    data->draw.step_y = 0;
    data->draw.side = 0;
	
    data->player.wall_dis = 0.0;
    data->mouse = init_mouse();
    data->mlx = mlx_init();
	init_textures(data, dir);
    printf("%d", *(data->textures->south.texture));
    data->window = mlx_new_window(data->mlx, 720, 720, "Cub 3D");
	data->frame = malloc(sizeof(t_img));
	t_img	*frame = data->frame;
	frame->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	frame->data_addr = mlx_get_data_addr(frame->img,
		&frame->bits_per_pixel, &frame->size_line, &frame->endian);

    game_start(data);
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
		map->line[++i] = line;
		map->line[i][ft_strlen(line) - 1] = 0;
		map->index = i;
        line = get_next_line(map->fd);
    }
	// int longest_line = get_longest_line();
    // i = -1;
    // while (map->line[++i])
    // {
	// 	write(1, map->line[i], strlen(map->line[i]));
	// 	write(1, "\n", 1);
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