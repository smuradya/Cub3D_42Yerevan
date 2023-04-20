/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:04:16 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/19 19:50:28 by smuradya         ###   ########.fr       */
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

void	game_start(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x(x);
		ray(data, x);
		int mapX = (int)data->player.pos.x;
		int mapY = (int)data->player.pos.y;
		delta_dist(data);
		
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;
		if(data->ray.x < 0)
		{
			stepX = -1;
			data->side_dist.x = (data->player.pos.x - mapX) * data->delta_dist.x;
		}
		else
		{
			stepX = 1;
			data->side_dist.x = (mapX + 1.0 - data->player.pos.x) * data->delta_dist.x;
		}
		if (data->ray.y < 0)
		{
			stepY = -1;
			data->side_dist.y = (data->player.pos.y - mapY) * data->delta_dist.y;
		}
		else
		{
			stepY = 1;
			data->side_dist.y = (mapY + 1.0 - data->player.pos.y) * data->delta_dist.y;
		}
		while(hit == 0)
		{
			if(data->side_dist.x < data->side_dist.y)
			{
				data->side_dist.x += data->delta_dist.x;
				mapX += stepX;
				side = 0;
			}
			else
			{
				data->side_dist.y += data->delta_dist.y;
				mapY += stepY;
				side = 1;
			}
			if(data->mix_map[mapY][mapX] == '1')
				hit = 1;
		}
		if(side == 0)
			perpWallDist = (data->side_dist.x - data->delta_dist.x);
		else
			perpWallDist = (data->side_dist.y - data->delta_dist.y);
		int lineHeight = (int)(WIN_HIGHT / perpWallDist);
		data->draw_start = -lineHeight / 2 + WIN_HIGHT / 2;
		
		if(data->draw_start < 0)
			data->draw_start = 0;
		data->draw_end = lineHeight / 2 + WIN_HIGHT / 2;
		if(data->draw_end >= WIN_HIGHT)
			data->draw_end = WIN_HIGHT - 1;
		int	i, start, end;

		i = -1;
		start = data->draw_start - 1;
		end = data->draw_end - 1;
		while (++i < data->draw_start)
			mlx_pixel_put(data->mlx, data->window, x, i, 0xd99033);
		while (++start < data->draw_end)
			mlx_pixel_put(data->mlx, data->window, x, start, 0x9774e7);
		while (++end < WIN_HIGHT)
			mlx_pixel_put(data->mlx, data->window, x, end, 0xf99983d);
		x++;
    }
}