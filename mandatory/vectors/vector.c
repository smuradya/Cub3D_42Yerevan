/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:02 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/25 18:34:55 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_vector	vector_inverse(t_data *data)
{
	t_vector	new_vector;

	new_vector.x = -data->player.dir.y;
	new_vector.y = data->player.dir.x;
	return (new_vector);
}

double	vector_lenght(t_vector vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y));
}

t_vector	vector_sum(t_vector first, t_vector second)
{
	t_vector	new_vector;

	new_vector.x = first.x + second.x;
	new_vector.y = first.y + second.y;
	return (new_vector);
}

t_vector	vector_diff(t_vector first, t_vector second)
{
	t_vector	new_vector;

	new_vector.x = first.x - second.x;
	new_vector.y = first.y - second.y;
	return (new_vector);
}

t_vector	vector_product(t_vector first, t_vector second)
{
	t_vector	new_vector;

	new_vector.x = first.x * second.x;
	new_vector.y = first.y * second.y;
	return (new_vector);
}

t_vector	new_vector(double x, double y)
{
	t_vector	new_vector;

	new_vector.x = x;
	new_vector.y = y;
	return (new_vector);
}

t_vector	copy_vector(t_vector source)
{
	t_vector	copy;
	copy.x = source.x;
	copy.y = source.y;
	return (copy);
}

t_mouse	init_mouse(void)
{
	t_mouse	tmp_mouse;

	tmp_mouse.horiz = WIN_WIDTH / 2;
	tmp_mouse.vertic = WIN_HIGHT / 2;
	return (tmp_mouse);
}
