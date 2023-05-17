/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:04:16 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/29 17:23:17 by anhakob2         ###   ########.fr       */
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
		if (data->map_data.map[map_y][map_x] == '1')
			hit = 1;
	}
}

void	start_and_end(t_data *data)
{
	int	line_height;

	if (data->draw.side == 0)
		data->player.wall_dis = (data->dist.x - data->delta_dist.x);
	else
		data->player.wall_dis = (data->dist.y - data->delta_dist.y);
	line_height = (int)(WIN_HIGHT / data->player.wall_dis);
	data->draw_start = -line_height / 2 + WIN_HIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = line_height / 2 + WIN_HIGHT / 2;
	if (data->draw_end >= WIN_HIGHT)
		data->draw_end = WIN_HIGHT - 1;
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
		*((unsigned int *)data->frame->data_addr + (start * WIN_WIDTH + colomn)) = 0x00ff00;
	while (++end < WIN_HIGHT)
		*((unsigned int *)data->frame->data_addr + (end * WIN_WIDTH + colomn)) = data->map_data.floor;
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
		draw_line(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->window,
		data->frame[0].img, 0, 0);
}
