/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:04:16 by smuradya          #+#    #+#             */
/*   Updated: 2023/06/10 20:10:24 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(t_data *data, int colomn)
{
	int	i;
	int	start;
	int	end;

	i = -1;
	start = data->draw_start - 1;
	end = data->draw_end - 1;
	while (++i < data->draw_start)
		*((unsigned int *)data->frame->data_addr
				+ (i * WIN_WIDTH + colomn)) = data->map_data.ceiling;
	while (++start < data->draw_end)
		*(unsigned int *)(data->frame->data_addr
				+ (start * data->frame->size_line
					+ colomn * (data->frame->bits_per_pixel / 8)))
			= get_texture_color(data);
	while (++end < WIN_HEIGHT)
		*((unsigned int *)data->frame->data_addr + (end * WIN_WIDTH + colomn))
			= data->map_data.floor;
}

double	init_tex_pos(t_data *data, t_draw draw)
{
	return ((data->draw_start - WIN_HEIGHT / 2
			+ draw.line_height / 2) * draw.ratio);
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
