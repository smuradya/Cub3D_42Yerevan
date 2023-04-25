// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mouse.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/04/25 20:17:44 by smuradya          #+#    #+#             */
// /*   Updated: 2023/04/25 20:27:22 by smuradya         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub3D.h"

// int	mouse_move(int x, int y, t_data *data)
// {	
// 	if (data-> != WIN_WIDTH / 2)
//     {
// 		if (data->mouse.hor < x)
//     	{
// 			t_vector old_dir = copy_vector(data->player.dir);
// 			t_vector old_plane = copy_vector(data->plane);
// 			data->player.dir.x = old_dir.x * cos(ROT_MOUSE * (-1)) - old_dir.y * sin(ROT_MOUSE * (-1));
// 			data->player.dir.y = old_dir.x * sin(ROT_MOUSE * (-1)) + old_dir.y * cos(ROT_MOUSE * (-1));
// 			data->plane.x = old_plane.x * cos(ROT_MOUSE * (-1)) - old_plane.y * sin(ROT_MOUSE * (-1));
// 			data->plane.y = old_plane.x * sin(ROT_MOUSE * (-1)) + old_plane.y * cos(ROT_MOUSE * (-1));

//    		}
//     	if (data->mouse.hor > x)
// 		{
// 			t_vector old_dir = copy_vector(data->player.dir);
// 			t_vector old_plane = copy_vector(data->plane);
//     	  	data->player.dir.x = old_dir.x * cos(ROT_MOUSE) - old_dir.y * sin(ROT_MOUSE);
// 			data->player->dir.y = old_dir.x * sin(ROT_MOUSE) + old_dir.y * cos(ROT_MOUSE);
// 			data->plane.x = old_plane.x * cos(ROT_MOUSE) - old_plane.y * sin(ROT_MOUSE);
// 			data->plane.y = old_plane.x * sin(ROT_MOUSE) + old_plane.y * cos(ROT_MOUSE);
//     	}
//   }	
//   	data->mouse.horiz = x;
// 	data->mouse.vertic = y;
// }
