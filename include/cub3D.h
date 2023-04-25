/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:54:20 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/25 20:31:51 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include <string.h> 
# include "get_next_line.h"
# include "cub3D_structs.h"
# include "linkedlist.h"

//vectors

t_vector	vector_inverse(t_data *data);
double		vector_lenght(t_vector vector);
t_vector	vector_sum(t_vector first, t_vector second);
t_vector	vector_diff(t_vector first, t_vector second);
t_vector	vector_product(t_vector first, t_vector second);
t_vector	new_vector(double x, double y);
t_vector	copy_vector(t_vector source);

//raycast

double		camera_x(int x);
t_vector	ray_vector(t_data	*data, int x);
void		game_start(t_data *data);
int			key_code(int k, t_data *data);
void		movemant(int k, t_data *data);
int			esc_vcode(t_data *data);
int			mouse_move(int x, int y, t_data *data);
t_mouse		init_mouse(void);
#endif
