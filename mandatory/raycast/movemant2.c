/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:53:20 by smuradya          #+#    #+#             */
/*   Updated: 2023/06/08 20:41:31 by smuradya         ###   ########.fr       */
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
	if (data->map_data.map[(int)(data->player.pos.x + data->player.dir.x * 0.2)]
		[(int)(data->player.pos.y)] != '1')
		data->player.pos.x += data->player.dir.x * 0.2;
	if (data->map_data.map[(int)(data->player.pos.x)]
		[(int)(data->player.pos.y + data->player.dir.y * 0.2)] != '1')
		data->player.pos.y += data->player.dir.y * 0.2;
}

void	s_key(t_data *data)
{
	if (data->map_data.map[(int)(data->player.pos.x - data->player.dir.x * 0.2)]
		[(int)(data->player.pos.y)] != '1')
		data->player.pos.x -= data->player.dir.x * 0.2;
	if (data->map_data.map[(int)(data->player.pos.x)]
		[(int)(data->player.pos.y - data->player.dir.y * 0.2)] != '1')	
		data->player.pos.y -= data->player.dir.y * 0.2;
}

void	d_key(t_data *data)
{
	if (data->map_data.map[(int)(data->player.pos.x - invers(data).x * 0.2)]
		[(int)(data->player.pos.y)] != '1')
		data->player.pos.x -= invers(data).x * 0.2;
	if (data->map_data.map[(int)(data->player.pos.x)]
		[(int)(data->player.pos.y - invers(data).y * 0.2)] != '1')
		data->player.pos.y -= invers(data).y * 0.2;
}

void	a_key(t_data *data)
{
	if (data->map_data.map[(int)(data->player.pos.x + invers(data).x * 0.2)]
		[(int)(data->player.pos.y)] != '1')
		data->player.pos.x += invers(data).x * 0.2;
	if (data->map_data.map[(int)(data->player.pos.x)]
		[(int)(data->player.pos.y + invers(data).y * 0.2)] != '1')
		data->player.pos.y += invers(data).y * 0.2;
}