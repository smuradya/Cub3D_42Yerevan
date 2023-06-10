/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemant2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:53:20 by smuradya          #+#    #+#             */
/*   Updated: 2023/06/09 21:21:56 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vector	invers(t_data *data)
{
	t_vector	tmp_vector;

	tmp_vector.x = -data->player.dir.y;
	tmp_vector.y = data->player.dir.x;
	return (tmp_vector);
}

void	w_key(t_data *data)
{
	if (data->map_data.map[(int)(data->player.pos.x + data->player.dir.x * 0.3)]
		[(int)(data->player.pos.y)] != '1')
		data->player.pos.x += data->player.dir.x * 0.3;
	if (data->map_data.map[(int)(data->player.pos.x)]
		[(int)(data->player.pos.y + data->player.dir.y * 0.3)] != '1')
		data->player.pos.y += data->player.dir.y * 0.3;
}

void	s_key(t_data *data)
{
	if (data->map_data.map[(int)(data->player.pos.x - data->player.dir.x * 0.3)]
		[(int)(data->player.pos.y)] != '1')
		data->player.pos.x -= data->player.dir.x * 0.3;
	if (data->map_data.map[(int)(data->player.pos.x)]
		[(int)(data->player.pos.y - data->player.dir.y * 0.3)] != '1')
		data->player.pos.y -= data->player.dir.y * 0.3;
}

void	d_key(t_data *data)
{
	if (data->map_data.map[(int)(data->player.pos.x - invers(data).x * 0.3)]
		[(int)(data->player.pos.y)] != '1')
		data->player.pos.x -= invers(data).x * 0.3;
	if (data->map_data.map[(int)(data->player.pos.x)]
		[(int)(data->player.pos.y - invers(data).y * 0.3)] != '1')
		data->player.pos.y -= invers(data).y * 0.3;
}

void	a_key(t_data *data)
{
	if (data->map_data.map[(int)(data->player.pos.x + invers(data).x * 0.3)]
		[(int)(data->player.pos.y)] != '1')
		data->player.pos.x += invers(data).x * 0.3;
	if (data->map_data.map[(int)(data->player.pos.x)]
		[(int)(data->player.pos.y + invers(data).y * 0.3)] != '1')
		data->player.pos.y += invers(data).y * 0.3;
}
