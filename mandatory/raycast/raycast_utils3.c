/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:04:16 by smuradya          #+#    #+#             */
/*   Updated: 2023/06/09 15:50:28 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	return (color);
}
