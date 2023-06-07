/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:55:44 by smuradya          #+#    #+#             */
/*   Updated: 2023/05/27 16:05:09 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTES_H
# define CUB3D_STRUCTES_H
# define WIN_WIDTH 980
# define WIN_HEIGHT 980
# define SENSITIVITY 0.05
# define ROT_MOUSE 0.06
# define TEXT_WIDTH            64
# define TEXT_HIGHT            64

typedef struct	s_player 	t_player;
typedef struct	s_data 		t_data;
typedef struct	s_vector 	t_vector;
typedef struct	s_draw 		t_draw;
typedef struct	s_mouse 	t_mouse;
typedef struct	s_map		t_map;
typedef struct	s_dir		t_dir;
typedef	struct	s_img		t_img;
typedef struct	s_textures	t_textures;

struct s_map
{
	char	**line;
	int		index;
	int		fd;
};

struct s_dir
{
	char	**map;
	char	*east;
	char	*west;
	char	*north;
	char	*south;
	int		x;
	int		y;
	int		floor;
	int		ceiling;
};

struct	s_img
{
	void	*img;
	int		img_width;
	int		img_height;
	int		endian;
	int		size_line;
	char	*data_addr;
	int		bits_per_pixel;
	unsigned int	*texture;
};

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
	double	tex_pos;
	double	ratio;
	int		tex_x;
	int		line_height;
};

struct s_textures
{
	t_img	north;
	t_img	east;
	t_img	west;
	t_img	south;
};


struct	s_data
{
	void		*mlx;
	char		**sdl;
	void		*window;
	t_textures	*textures;
	t_player	player;
	t_vector	plane;
	t_dir		map_data;
	int			map_width;
	int			map_hight;
	t_vector	ray;
	t_vector	dist;
	t_vector	delta_dist;
	int			draw_start;
	int			draw_end;
	t_mouse		mouse;
	t_draw		draw;
	t_img		*frame;
};

#endif
