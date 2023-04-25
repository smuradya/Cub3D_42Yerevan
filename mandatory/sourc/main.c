#include "cub3D.h"

int main(int argc, char **argv)
{
    t_data  *data;
    if (argc != 2)
    {
        printf("havayi error\n");
        exit(1);
    }
    int fd = open(argv[1], O_RDONLY);
    char *line = get_next_line(fd);

    int count = 0;
    while (line)
    {
        ++count;
        line = get_next_line(fd);
    }
    close(fd);

    char **map = malloc(sizeof(char *) * (count + 1));
    map[count] = 0;
    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    int i = 0;
    while (line)
    {
        map[i++] = line;
        line = get_next_line(fd);
    }
    while(map[++i] == 0)
    {
        ;
    }
    // i = -1;
    // while (map[++i])
    // {
    //     write(1, map[i], strlen(map[i]));
    //     write(1, "\n", 1);
    // }
    
    data = malloc(sizeof(t_data));
    data->player.pos = new_vector(17, 7);
    data->player.dir = new_vector(-1, 0);
    data->plane = new_vector(0, 0.66);
    data->mix_map = map;
    data->draw.step_x = 0;
    data->draw.step_y = 0;
    data->draw.side = 0;
    data->player.wall_dis = 0.0;
    //data->mouse = init_mouse();
    data->mlx = mlx_init();
    data->mouse.horiz = 0.06;
    data->mouse.vertic = 0.06;
    data->window = mlx_new_window(data->mlx, 720, 720, "Cub 3D");
    game_start(data);
    mlx_hook(data->window, 2, 1L<<0, key_code, data);
    mlx_hook(data->window, 17, 0L, esc_code, data);
    mlx_hook(data->window, 6, 0L, mouse_move, data);
    mlx_loop(data->mlx);
    return (0);
}
