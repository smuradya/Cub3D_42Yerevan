/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:53:20 by smuradya          #+#    #+#             */
/*   Updated: 2023/06/11 21:40:11 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	esc_code(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	system("leaks cub3D");
	exit(0);
	return (0);
}

int	key_code(int k, t_data *data)
{
	if (k == 13)
		w_key(data);
	else if (k == 1)
		s_key(data);
	else if (k == 0)
		a_key(data);
	else if (k == 53)
		esc_code(data);
	else if (k == 2)
		d_key(data);
	else if (k == 123 || k == 124)
		movemant(k, data);
	game_start(data);
	return (1);
}

void	movemant_one(t_vector old_dir, t_vector old_plane, t_data *data)
{
	data->player.dir.x = old_dir.x * cos(SENSITIVITY * (-1)) - old_dir.y
		* sin(SENSITIVITY * (-1));
	data->player.dir.y = old_dir.x * sin(SENSITIVITY * (-1)) + old_dir.y
		* cos(SENSITIVITY * (-1));
	data->plane.x = old_plane.x * cos(SENSITIVITY * (-1)) - old_plane.y
		* sin(SENSITIVITY * (-1));
	data->plane.y = old_plane.x * sin(SENSITIVITY * (-1)) + old_plane.y
		* cos(SENSITIVITY * (-1));
}

void	movemant_two(t_vector old_dir, t_vector old_plane, t_data *data)
{
	data->player.dir.x = old_dir.x * cos(SENSITIVITY) - old_dir.y
		* sin(SENSITIVITY);
	data->player.dir.y = old_dir.x * sin(SENSITIVITY) + old_dir.y
		* cos(SENSITIVITY);
	data->plane.x = old_plane.x * cos(SENSITIVITY) - old_plane.y
		* sin(SENSITIVITY);
	data->plane.y = old_plane.x * sin(SENSITIVITY) + old_plane.y
		* cos(SENSITIVITY);
}

void	movemant(int k, t_data *data)
{	
	t_vector	old_dir;
	t_vector	old_plane;

	old_plane = copy_vector(data->plane);
	old_dir = copy_vector(data->player.dir);
	if (k == 124)
		movemant_one(old_dir, old_plane, data);
	if (k == 123)
		movemant_two(old_dir, old_plane, data);
}
