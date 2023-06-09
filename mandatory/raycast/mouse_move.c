/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:59:53 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/09 15:07:42 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mouse_move_one(t_vector old_dir, t_vector old_plane, t_data *data)
{
	data->player.dir.x = old_dir.x * cos(ROT_MOUSE * (-1)) - old_dir.y
		* sin(ROT_MOUSE * (-1));
	data->player.dir.y = old_dir.x * sin(ROT_MOUSE * (-1)) + old_dir.y
		* cos(ROT_MOUSE * (-1));
	data->plane.x = old_plane.x * cos(ROT_MOUSE * (-1)) - old_plane.y
		* sin(ROT_MOUSE * (-1));
	data->plane.y = old_plane.x * sin(ROT_MOUSE * (-1)) + old_plane.y
		* cos(ROT_MOUSE * (-1));
}

void	mouse_move_two(t_vector old_dir, t_vector old_plane, t_data *data)
{
	data->player.dir.x = old_dir.x * cos(ROT_MOUSE) - old_dir.y
		* sin(ROT_MOUSE);
	data->player.dir.y = old_dir.x * sin(ROT_MOUSE) + old_dir.y
		* cos(ROT_MOUSE);
	data->plane.x = old_plane.x * cos(ROT_MOUSE) - old_plane.y
		* sin(ROT_MOUSE);
	data->plane.y = old_plane.x * sin(ROT_MOUSE) + old_plane.y
		* cos(ROT_MOUSE);
}

int	mouse_move(int x, int y, t_data *data)
{
	t_vector	old_dir;
	t_vector	old_plane;

	old_dir = copy_vector(data->player.dir);
	old_plane = copy_vector(data->plane);
	if (data->mouse.horiz != WIN_WIDTH / 2)
	{
		if (data->mouse.horiz < x)
			mouse_move_one(old_dir, old_plane, data);
		if (data->mouse.horiz > x)
			mouse_move_two(old_dir, old_plane, data);
	}
	data->mouse.horiz = x;
	data->mouse.vertic = y;
	game_start(data);
	return (1);
}
