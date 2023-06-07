// #include "cub3D.h"

// int	contains(char *source, char *find)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	while (source[i])
// 	{
// 		if (source[i] == find[0])
// 		{
// 			j = 0;
// 			k = i;
// 			while (source[k] == find[j] && j < (int)ft_strlen(find))
// 			{
// 				k++;
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	if (j == (int)ft_strlen(find))
// 		return (1);
// 	return (0);
// }

// void	put_textures(t_data *data, int i)
// {
// 	if (contains(data->sdl[i], "NO"))
// 		data->img_north = ft_strdup(data->sdl[i]);
// 	else if (contains(data->sdl[i], "SO"))
// 		data->img_south = ft_strdup(data->sdl[i]);
// 	else if (contains(data->sdl[i], "WE"))
// 		data->img_west = ft_strdup(data->sdl[i]);
// 	else if (contains(data->sdl[i], "EA"))
// 		data->img_east = ft_strdup(data->sdl[i]);
// }