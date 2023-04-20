/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:53:20 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/20 20:21:50 by smuradya         ###   ########.fr       */
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
	data->player.pos.x += data->player.dir.x * 0.5;
	data->player.pos.y += data->player.dir.y * 0.5;
}

void	s_key(t_data *data)
{
	data->player.pos.x -= data->player.dir.x * 0.5;
	data->player.pos.y -= data->player.dir.y * 0.5;
}

void	d_key(t_data *data)
{
	data->player.pos.x -= invers(data).x * 0.5; 
	data->player.pos.y -= invers(data).y * 0.5;
}

void	a_key(t_data *data)
{
	data->player.pos.x += invers(data).x * 0.5;
	data->player.pos.y += invers(data).y * 0.5;
}

int	update_loop(int k, t_data *data)
{
	if (k == 13)
		w_key(data);
	else if (k == 1)
		s_key(data);
	else if (k == 0)
		a_key(data);
	else if (k == 2)
		d_key(data);
	else if (k == 123 || k == 124)
		movemant(k, data);
	game_start(data);
	return (1);
}

void	movemant(int k, t_data *data)
{
	(void) data;
	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame
	//double posX = 22.0, posY = 11.5; //x and y start position
  	double dirX = -1.0, dirY = 0.0; //initial direction vector
  	double planeX = 0.0, planeY = 0.66; //the 
    double frameTime = (time - oldTime) / 1000.0; //frametime is the time this frame has taken, in seconds
    //print(1.0 / frameTime); //FPS counter
    //redraw();

    //speed modifiers
    //double moveSpeed = frameTime * 3.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 2.0; //the constant value is in radians/second
    //move forward if no wall in front of you
    // if (w_key == )
    // {
    //   if(data->mix_map[int(posX + dirX * moveSpeed)][int(posY)] == 0) posX += dirX * moveSpeed;
    //   if(data->mix_map[int(posX)][int(posY + dirY * moveSpeed)] == 0) posY += dirY * moveSpeed;
    // }
    // //move backwards if no wall behind you
    // if(keyDown(SDLK_DOWN))
    // {
    //   if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
    //   if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    // }
    //rotate to the right
	
    if(k == 123)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if(k == 124)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
  }	