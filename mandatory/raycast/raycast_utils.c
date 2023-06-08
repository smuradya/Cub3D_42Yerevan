/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:04:16 by smuradya          #+#    #+#             */
/*   Updated: 2023/05/20 17:57:16 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	camera_x(int x)
{
	return (2 * x / (double)WIN_WIDTH - 1);
}

void	ray(t_data *data, int x)
{
	data->ray.x = data->player.dir.x + data->plane.x * camera_x(x);
	data->ray.y = data->player.dir.y + data->plane.y * camera_x(x);
}

void	delta_dist(t_data *data)
{
	if (data->ray.x == 0)
		data->delta_dist.x = 1e30;
	else
		data->delta_dist.x = fabs(1 / data->ray.x);
	if (data->ray.y == 0)
		data->delta_dist.y = 1e30;
	else
		data->delta_dist.y = fabs(1 / data->ray.y);
}

void	checking_rays(t_data *data)
{
	int	map_y;
	int	map_x;

	map_y = (int)data->player.pos.y;
	map_x = (int)data->player.pos.x;
	if (data->ray.x < 0)
	{
		data->draw.step_x = -1;
		data->dist.x = (data->player.pos.x - map_x) * data->delta_dist.x;
	}
	else
	{
		data->draw.step_x = 1;
		data->dist.x = (map_x + 1.0 - data->player.pos.x) * data->delta_dist.x;
	}
	if (data->ray.y < 0)
	{
		data->draw.step_y = -1;
		data->dist.y = (data->player.pos.y - map_y) * data->delta_dist.y;
	}
	else
	{
		data->draw.step_y = 1;
		data->dist.y = (map_y + 1.0 - data->player.pos.y) * data->delta_dist.y;
	}
}

void	raycast_algorithm(t_data *data)
{
	int	map_y;
	int	map_x;
	int	hit;

	hit = 0;
	map_y = (int)data->player.pos.y;
	map_x = (int)data->player.pos.x;
	while (!hit)
	{
		if (data->dist.x < data->dist.y)
		{
			data->dist.x += data->delta_dist.x;
			map_x += data->draw.step_x;
			data->draw.side = 0;
		}
		else
		{
			data->dist.y += data->delta_dist.y;
			map_y += data->draw.step_y;
			data->draw.side = 1;
		}
		if (data->map_data.map[map_x][map_y] == '1')
			hit = 1;
	}
}

void	start_and_end(t_data *data)
{

	if (data->draw.side == 0)
		data->player.wall_dis = (data->dist.x - data->delta_dist.x);
	else
		data->player.wall_dis = (data->dist.y - data->delta_dist.y);
	data->draw.line_height = (int)(WIN_HEIGHT / data->player.wall_dis);
	data->draw_start = -data->draw.line_height / 3 + WIN_HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->draw.line_height / 3 + WIN_HEIGHT / 2;
	if (data->draw_end >= WIN_HEIGHT || data->draw_end < 0)
		data->draw_end = WIN_HEIGHT - 1;
}


unsigned int	get_texture_color(t_data *data)
{
	int		tex_y;
	int		color;
	t_img	img;

	color = 0;
	data->draw.tex_pos += data->draw.ratio;
	tex_y = (int)data->draw.tex_pos & (TEXT_HIGHT - 1);
	if (data->draw.side == 0 && data->ray.x > 0)
		img = data->textures->south;
	else if (data->draw.side == 0 && data->ray.x < 0)
		img = data->textures->north;
	else if (data->draw.side == 1 && data->ray.y < 0)
		img = data->textures->west;
	else if (data->draw.side == 1 && data->ray.y > 0)
		img = data->textures->east;

	color = *(unsigned int *)(img.data_addr + (tex_y * img.bits_per_pixel / 8)
			+ img.size_line * data->draw.tex_x);
    // if (data->draw.side == 0 && data->ray.x > 0)
    //     color = data->textures->south.texture[tex_y + 64 * data->draw.tex_x];
    // else if (data->draw.side == 0 && data->ray.x < 0)
    //     color = data->textures->north.texture[tex_y + 64 * data->draw.tex_x];
    // else if (data->draw.side == 1 && data->ray.y < 0)
    //     color = data->textures->west.texture[tex_y + 64 * data->draw.tex_x];
    // else if (data->draw.side == 1 && data->ray.y > 0)
    //     color = data->textures->east.texture[tex_y + 64 * data->draw.tex_x];
	return (color);
}

void	draw_line(t_data *data, int colomn)
{
	int	i;
	int	start;
	int	end;

	i = -1;
	start = data->draw_start - 1;
	end = data->draw_end - 1;
	while (++i < data->draw_start)
		*((unsigned int *)data->frame->data_addr + (i * WIN_WIDTH + colomn)) = data->map_data.ceiling;
	while (++start < data->draw_end)
		*(unsigned int *)(data->frame->data_addr + (start * data->frame->size_line
			+ colomn * (data->frame->bits_per_pixel / 8))) = get_texture_color(data);
		// *((unsigned int *)data->frame->data_addr + (start * WIN_WIDTH + colomn)) = get_texture_color(data);
	while (++end < WIN_HEIGHT)
		*((unsigned int *)data->frame->data_addr + (end * WIN_WIDTH + colomn)) = data->map_data.floor;
}

double	init_tex_pos(t_data *data, t_draw draw)
{
	return ((data->draw_start - WIN_HEIGHT / 2 + draw.line_height / 2) * draw.ratio);
}

double	wall_x(t_data *data, t_draw draw)
{
	double	wallx;

	if (draw.side == 0)
		wallx = data->player.pos.y + data->player.wall_dis * data->ray.y;
	else
		wallx = data->player.pos.x + data->player.wall_dis * data->ray.x;
	wallx -= floor((wallx));
	return (wallx);
}

int	init_tex_x(t_data *data, t_draw draw)
{
	int	tex_x;

	tex_x = (int)(wall_x(data, draw) * (double)TEXT_WIDTH);
	if (draw.side == 0 && data->ray.x > 0)
		tex_x = TEXT_WIDTH - tex_x - 1;
	if (draw.side == 1 && data->ray.y < 0)
		tex_x = TEXT_WIDTH - tex_x - 1;
	return (tex_x);
}



void	game_start(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x(x);
		ray(data, x);
		delta_dist(data);
		checking_rays(data);
		raycast_algorithm(data);
		start_and_end(data);
		data->draw.tex_x = init_tex_x(data, data->draw);
		data->draw.ratio = 1.0 * TEXT_HIGHT / data->draw.line_height;
		data->draw.tex_pos = init_tex_pos(data, data->draw);
		draw_line(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->window,
		data->frame[0].img, 0, 0);
}
