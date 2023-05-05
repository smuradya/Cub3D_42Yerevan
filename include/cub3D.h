/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:54:20 by smuradya          #+#    #+#             */
/*   Updated: 2023/05/04 19:46:37 by anhakob2         ###   ########.fr       */
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
int			mouse_move(int x, int y, t_data *data);
int			esc_code(t_data *data);
t_mouse		init_mouse(void);

// parsing.c

int		parsing(char *argv, t_map *map);
void	check_validation(t_map	*map, t_dir *dir);
void	cub_init(t_dir *dir, t_data *data);
void	setup_player(t_data *data, int x, int y);

// utils.c

int	ft_strcmp(char *s1, char *s2);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
 
 //filll_values.c

 void fill_values(char **line, t_dir *dir, int i);
 void fill_color(char **line, t_dir *dir, int i);
 int ft_check(char *str);
 int check_color(char *str, int i);
 int check_file(char *line, int i);
 
 //map.c
 
 void	fill_map(char **line, char **map);
//  char	**fill_map(char **line, char **map);
 int	space_before(char *str);
 
#endif
