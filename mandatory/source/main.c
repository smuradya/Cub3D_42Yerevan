#include "cub3D.h"

int arg_validation(int argc, char *argv)
{
	int	len;
	
	if (argc != 2)
	{
		write (1, "Argc error\n", 11);
		return (1);	
	}
	len = ft_strlen(argv) - 1;
	if (argv[len] == 'b' && argv[len - 1] == 'u' &&
		argv[len - 2] == 'c' && argv[len - 3] == '.')
	{
		return(0);
	}
	else
		write (1, "file validation error\n", 21);
	return (1);
}

int main(int argc, char **argv)
{
	t_map *map;
	t_dir *dir;
	t_data  *data;

	data = malloc(sizeof(t_data));
	if(arg_validation(argc, argv[1]) != 0)
		return (1);
	if (!(dir = malloc (sizeof(t_dir))))
		return (1);
	map = malloc (sizeof(t_map));
	parsing(argv[1], map);
	check_validation(map, dir);
	// setup_player(data, dir->x, dir->y);
	cub_init(dir, data);
	return (0);
}

// int main(int argc, char **argv)
// {
//     t_data  *data;
//     if (argc != 2)
//     {
//         printf("havayi error\n");
//         exit(1);
//     }
//     int fd = open(argv[1], O_RDONLY);
//     char *line = get_next_line(fd);

//     int count = 0;
//     while (line)
//     {
//         ++count;
//         line = get_next_line(fd);
//     }
//     close(fd);

//     char **map = malloc(sizeof(char *) * (count + 1));
//     map[count] = 0;
//     fd = open(argv[1], O_RDONLY);
//     line = get_next_line(fd);
//     int i = 0;
//     while (line)
//     {
//         map[i++] = line;
//         line = get_next_line(fd);
//     }
//     while(map[++i] == 0)
//     {
//         ;
//     }
//     // i = -1;
//     // while (map[++i])
//     // {
//     //     write(1, map[i], strlen(map[i]));
//     //     write(1, "\n", 1);
//     // }
    
//     data = malloc(sizeof(t_data));
//     data->player.pos = new_vector(17, 7);
//     data->player.dir = new_vector(-1, 0);
//     data->plane = new_vector(0, 0.66);
//     data->map_data.map = map;
//     data->draw.step_x = 0;
//     data->draw.step_y = 0;
//     data->draw.side = 0;
//     data->player.wall_dis = 0.0;
//     data->mouse = init_mouse();
//     data->mlx = mlx_init();
//     //data->mouse.horiz = 0.06;
//     //data->mouse.vertic = 0.06;
//     data->window = mlx_new_window(data->mlx, 720, 720, "Cub 3D");
//     game_start(data);
//     mlx_hook(data->window, 2, 1L<<0, key_code, data);
//     mlx_hook(data->window, 17, 0L, esc_code, data);
//     mlx_hook(data->window, 6, 0L, mouse_move, data);
//     mlx_loop(data->mlx);
//     return (0);
// }
