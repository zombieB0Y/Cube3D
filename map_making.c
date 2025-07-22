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
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1'}};
    int player_x = 2;
    int player_y = 4;
    double dirX = -1, dirY = 0;
    double planeX = 0, planeY = 0.66; // the 2d raycaster version of camera plane

    double time = 0;    // time of current frame
    double oldTime = 0; // time of previous frame
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, screenWidth, screenHeight, "Cube3D");
    mlx_loop(mlx);
    while (1)
    {
        int x = -1;
        while (++x < mapWidth)
        {
            double cameraX = (2 * x) / ((double) mapWidth - 1); // x-coordinate in camera space
            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;
        }
    }
}