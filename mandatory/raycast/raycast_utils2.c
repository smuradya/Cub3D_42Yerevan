/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:04:16 by smuradya          #+#    #+#             */
/*   Updated: 2023/06/08 20:52:27 by smuradya         ###   ########.fr       */
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