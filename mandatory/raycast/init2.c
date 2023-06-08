/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:16:20 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/08 21:23:20 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	get_img_color(t_img img, int x, int y)
{
	char	*dst;

	if (!img.img)
		return (0);
	dst = img.data_addr + (y * img.size_line + x
			* (img.bits_per_pixel / 8));
	return ((unsigned int)dst);
}

unsigned int	*get_img_colors(t_img img)
{
	int					i;
	int					j;
	int					k;
	unsigned int		*ptr;

	ptr = malloc(sizeof(unsigned int) * 64 * 64);
	i = -1;
	while (++i < 64)
	{
		j = -1;
		k = 64;
		while (++j < 64 && --k > -1)
			ptr[64 * k + i] = get_img_color(img, j, i);
	}
	return (ptr);
}