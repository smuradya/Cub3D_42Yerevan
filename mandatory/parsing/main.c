/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:37:17 by anhakob2          #+#    #+#             */
/*   Updated: 2023/04/26 18:38:34 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cu b3D.h"

// int arg_validation(int argc, char *argv)
// {
// 	int	len;
	
// 	if (argc != 2)
// 	{
// 		write (1, "Argc error\n", 11);
// 		return (1);	
// 	}
// 	len = ft_strlen(argv) - 1;
// 	if (argv[len] == 'b' && argv[len - 1] == 'u' &&
// 		argv[len - 2] == 'c' && argv[len - 3] == '.')
// 	{
// 		return(0);
// 	}
// 	else
// 		write (1, "file validation error\n", 21);
// 	return (1);
// }

// int main(int argc, char **argv)
// {
// 	t_map *map;

// 	if(arg_validation(argc, argv[1]) != 0)
// 		return (1);
// 	map = malloc (sizeof(t_map));
// 	parsing(argv[1], map);
// 	return (0);
// }