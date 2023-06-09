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
	tmp_mouse.vertic = WIN_HEIGHT / 2;
	return (tmp_mouse);
}
