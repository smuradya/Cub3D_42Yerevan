/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:25:37 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/08 20:55:53 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_around_1(char *s1, char *s, char *s2)
{
	int	i;
	int	l;
	int	j;

	i = 0;
	while (s && s[i])
		i++;
	while (s && s[i] != '0' && i > 0)
		i--;
	l = ft_strlen(s1);
	if (i >= l)
		return (1);
	j = ft_strlen(s2);
	if (i >= j)
		return (1);
	return (0);
}

int	ft_around(char *s1, char *s, char *s2)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if ((s[i] == '0' || s[i] == 'N'
				|| s[i] == 'E' || s[i] == 'W'
				|| s[i] == 'S') && (s[i + 1] == ' '
				|| s1[i] == ' ' || s2[i] == ' '))
			return (1);
		i++;
	}
	ft_around_1(s1, s, s2);
	return (0);
}

int	ft_wall_around(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	if (str && str[i] && str[i] != '1')
		return (1);
	while (str && str[i])
		i++;
	i--;
	if (str && str[i] != '1')
		return (1);
	return (0);
}

int	ft_other_char(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != '1' && str[i] != '0'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W'
			&& str[i] != 'E' && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_pos(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			++count;
		i++;
	}
	return (count);
}
