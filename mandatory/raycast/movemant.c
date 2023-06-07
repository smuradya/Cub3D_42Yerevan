/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:53:20 by smuradya          #+#    #+#             */
/*   Updated: 2023/05/27 16:00:45 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vector	invers(t_data *data)
{
	t_vector	tmp_vector;
	tmp_vector.x = -data->player.dir.y;
	tmp_vector.y = data->player.dir.x;
	return(tmp_vector);
}

void	w_key(t_data *data)
{
	if(data->map_data.map[(int)(data->player.pos.x + data->player.dir.x * 0.2)][(int)(data->player.pos.y)] != '1')
		data->player.pos.x += data->player.dir.x * 0.2;
	if(data->map_data.map[(int)(data->player.pos.x)][(int)(data->player.pos.y + data->player.dir.y * 0.2)] != '1')	
		data->player.pos.y += data->player.dir.y * 0.2;
	//printf("x: %f, y: %f, dir.x: %f, dir.y: %f\n", data->player.pos.x, data->player.pos.y, data->player.dir.x, data->player.dir.y);
}

void	s_key(t_data *data)
{
	if(data->map_data.map[(int)(data->player.pos.x - data->player.dir.x * 0.2)][(int)(data->player.pos.y)] != '1')
		data->player.pos.x -= data->player.dir.x * 0.2;
	if(data->map_data.map[(int)(data->player.pos.x)][(int)(data->player.pos.y - data->player.dir.y * 0.2)] != '1')	
		data->player.pos.y -= data->player.dir.y * 0.2;
}

void	d_key(t_data *data)
{
	if(data->map_data.map[(int)(data->player.pos.x + data->player.dir.x * 0.2)][(int)(data->player.pos.y)] != '1')
		data->player.pos.x += data->player.dir.x * 0.2;
	if(data->map_data.map[(int)(data->player.pos.x)][(int)(data->player.pos.y + data->player.dir.y * 0.2)] != '1')	
		data->player.pos.y += data->player.dir.y * 0.2;
	// printf("x: %f, y: %f, dir.x: %f, dir.y: %f\n", data->player.pos.x, data->player.pos.y, data->player.dir.x, data->player.dir.y);

}

void	a_key(t_data *data)
{
	if(data->map_data.map[(int)(data->player.pos.x - data->player.dir.x * 0.2)][(int)(data->player.pos.y)] != '1')
		data->player.pos.x -= data->player.dir.x * 0.2;
	if(data->map_data.map[(int)(data->player.pos.x)][(int)(data->player.pos.y - data->player.dir.y * 0.2)] != '1')	
		data->player.pos.y -= data->player.dir.y * 0.2;
	//printf("x: %f, y: %f, dir.x: %f, dir.y: %f\n", data->player.pos.x, data->player.pos.y, data->player.dir.x, data->player.dir.y);

}

int	esc_code(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
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

void	movemant(int k, t_data *data)
{	
    if (k == 123)
    {
		t_vector old_dir = copy_vector(data->player.dir);
		t_vector old_plane = copy_vector(data->plane);
		data->player.dir.x = old_dir.x * cos(SENSITIVITY * (-1)) - old_dir.y * sin(SENSITIVITY * (-1));
    	data->player.dir.y = old_dir.x * sin(SENSITIVITY * (-1)) + old_dir.y * cos(SENSITIVITY * (-1));
    	data->plane.x = old_plane.x * cos(SENSITIVITY * (-1)) - old_plane.y * sin(SENSITIVITY * (-1));
  	  data->plane.y = old_plane.x * sin(SENSITIVITY * (-1)) + old_plane.y * cos(SENSITIVITY * (-1));
    }
    if(k == 124)
	{
		t_vector old_dir = copy_vector(data->player.dir);
		t_vector old_plane = copy_vector(data->plane);
      data->player.dir.x = old_dir.x * cos(SENSITIVITY) - old_dir.y * sin(SENSITIVITY);
      data->player.dir.y = old_dir.x * sin(SENSITIVITY) + old_dir.y * cos(SENSITIVITY);
      data->plane.x = old_plane.x * cos(SENSITIVITY) - old_plane.y * sin(SENSITIVITY);
      data->plane.y = old_plane.x * sin(SENSITIVITY) + old_plane.y * cos(SENSITIVITY);
    }
  }	

int	mouse_move(int x, int y, t_data *data)
{	
	if (data->mouse.horiz != WIN_WIDTH / 2)
    {
		if (data->mouse.horiz < x)
    	{
			t_vector old_dir = copy_vector(data->player.dir);
			t_vector old_plane = copy_vector(data->plane);
			data->player.dir.x = old_dir.x * cos(ROT_MOUSE * (-1)) - old_dir.y * sin(ROT_MOUSE * (-1));
			data->player.dir.y = old_dir.x * sin(ROT_MOUSE * (-1)) + old_dir.y * cos(ROT_MOUSE * (-1));
			data->plane.x = old_plane.x * cos(ROT_MOUSE * (-1)) - old_plane.y * sin(ROT_MOUSE * (-1));
			data->plane.y = old_plane.x * sin(ROT_MOUSE * (-1)) + old_plane.y * cos(ROT_MOUSE * (-1));

   		}
    	if (data->mouse.horiz > x)
		{
			t_vector old_dir = copy_vector(data->player.dir);
			t_vector old_plane = copy_vector(data->plane);
    	  	data->player.dir.x = old_dir.x * cos(ROT_MOUSE) - old_dir.y * sin(ROT_MOUSE);
			data->player.dir.y = old_dir.x * sin(ROT_MOUSE) + old_dir.y * cos(ROT_MOUSE);
			data->plane.x = old_plane.x * cos(ROT_MOUSE) - old_plane.y * sin(ROT_MOUSE);
			data->plane.y = old_plane.x * sin(ROT_MOUSE) + old_plane.y * cos(ROT_MOUSE);
		}
  }	
  	data->mouse.horiz = x;
	data->mouse.vertic = y;
	game_start(data);
	return (1);
}
