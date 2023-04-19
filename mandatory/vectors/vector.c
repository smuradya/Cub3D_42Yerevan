/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:02 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/17 17:30:03 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_vector	vector_inverse(t_vector vector)
{
	t_vector	new_vector;

	new_vector.x = -vector.y;
	new_vector.y = vector.x;
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