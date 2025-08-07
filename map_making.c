#include "cube.h"

void create_map(char **map)
{

    char hard_coded_map[mapHeight][mapWidth] =
        {
            {'1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', 'N', '0', '0', '0', '0', '1'},
            {'1', '0', '1', '1', '1', '1', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1'}};

    float player_x;
    float player_y;
    float raydirx;
    float raydiry;
    float distance_to_projection_plan;
    float ray_angle;

    player_x = (2 + 0.5) * 64;
    player_y = (4 + 0.5) * 64;
    int mapx;
    int mapy;
    int fov;
    int direction;
    fov = 60;
    direction = 180;
    raydirx = cos(direction);
    raydiry = sin(direction);
    distance_to_projection_plan = ((screenWidth / 2)) / tan((fov / 2));
    int x;
    int y;
    int stepx;
    int stepy;
    x = 0;
    y = 0;
    while (x < screenWidth)
    {
        ray_angle = (direction - (fov / 2)) + (direction * (x / (screenWidth - 1)));
        mapx = player_x / 64;
        mapy = player_x / 64;
        if (raydirx > 0)
            stepx = 1;
        else
            stepx = -1;
        if (raydiry > 0)
            stepy = 1;
        else
            stepy = -1;
    }
    // void *mlx = mlx_init();
    // void *win = mlx_new_window(mlx, screenWidth , screenHeight, "Tutorial Window");
    // mlx_loop(mlx);
}