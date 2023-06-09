/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:16:20 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/09 14:56:08 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	img_init(void *mlx, char *addr)
{
	t_img	img;

	img.data_addr = NULL;
	img.img = mlx_xpm_file_to_image(mlx, addr,
			&img.img_width, &img.img_height);
	img.data_addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	img.texture = get_img_colors(img);
	return (img);
}

void	init_textures(t_data *data, t_dir *dir)
{
	data->textures = malloc(sizeof(t_textures));
	data->textures->east = img_init(data->mlx, dir->east);
	data->textures->west = img_init(data->mlx, dir->west);
	data->textures->south = img_init(data->mlx, dir->south);
	data->textures->north = img_init(data->mlx, dir->north);
}

void	setup_player(t_data *data, t_dir *dir)
{
	data->player.pos = new_vector(dir->x, dir->y);
	if (dir->player_direction == 'N')
		data->player.dir = new_vector(-1, 0);
	else if (dir->player_direction == 'E')
		data->player.dir = new_vector(0, 1);
	else if (dir->player_direction == 'W')
		data->player.dir = new_vector(0, -1);
	else if (dir->player_direction == 'S')
		data->player.dir = new_vector(1, 0);
	data->plane = vector_product(new_vector(0.66, 0.66),
			vector_inverse(data->player.dir));
}

void	cub_init(t_dir *dir, t_data *data)
{
	t_img	*frame;

	setup_player(data, dir);
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
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub 3D");
	data->frame = malloc(sizeof(t_img));
	frame = data->frame;
	frame->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	frame->data_addr = mlx_get_data_addr(frame->img,
			&frame->bits_per_pixel,
			&frame->size_line, &frame->endian);
	game_start(data);
	mlx_hook(data->window, 2, 1L << 0, key_code, data);
	mlx_hook(data->window, 17, 0L, esc_code, data);
	mlx_hook(data->window, 6, 0L, mouse_move, data);
	mlx_loop(data->mlx);
}
