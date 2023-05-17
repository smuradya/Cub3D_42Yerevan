// #include "cub3D.h"

// static void draw_sky_and_floor(t_data *data)
// {
// 	unsigned int	*dis;
// 	unsigned int	i;

// 	dis = (unsigned int *) data->img.addr;
// 	i = WIN_WIDTH * WIN_HIGHT / 2 + 1;
// 	while (--i > 0)
// 		*dis++ = data->map_data.ceiling;
// 		i = WIN_WIDTH * WIN_HIGHT / 2 + 1;
// 	while (--i > 0)
// 	*dis++ = data->map_data.floor;
// }