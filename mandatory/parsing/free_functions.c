/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:05:56 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/09 16:06:55 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_exit(char *str)
{
	printf ("%s\n", str);
	exit (1);
}

void	free_exit_map(t_map *map, char *str)
{
	printf ("%s\n", str);
	exit (1);
}
