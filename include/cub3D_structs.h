/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:55:44 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/25 20:19:05 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTES_H
# define CUB3D_STRUCTES_H
# define WIN_WIDTH 980
# define WIN_HIGHT 980
# define SENSITIVITY 0.05
# define ROT_MOUSE 0.06

typedef struct	s_player t_player;
typedef struct	s_data t_data;
typedef struct	s_vector t_vector;
typedef struct	s_draw t_draw;
typedef struct	s_mouse t_mouse;


struct s_vector
{
	double	x;
	double	y;
};

struct s_player
{
	t_vector	pos;
	t_vector	dir;
	double		angle;
	double 		cdir; 
	double		wall_dis;
};

struct s_mouse
{
	double vertic;
	double horiz;
};

struct s_draw
{
	double	step_x;
	double	step_y;
	double	side;
};


struct	s_data
{
	void		*mlx;
	void		*window;
	t_player	player;
	t_vector	plane;
	int			map_width;
	int			map_hight;
	char		**mix_map;
	t_vector	ray;
	t_vector	dist;
	t_vector	delta_dist;
	int			draw_start;
	int			draw_end;
	t_mouse		mouse;
	t_draw		draw;
};

#endif
