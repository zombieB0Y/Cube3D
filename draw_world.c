#include "cube.h"
void draw_in_image(t_cube_map *cube, int x, int start_line, int end_line, int side)
{
    printf("start line = %d , end_line = %d \n", start_line, end_line);
    while (start_line <= end_line)
    {
        printf("seg here \n");
        if (side)
            img_pix_put(&(cube->img), x, start_line, 0x82a14b);
        else
            img_pix_put(&(cube->img), x, start_line, 0x32a89e);
        start_line++;
    }
    printf("not here \n");
}
int draw_world()
{
    t_cube_map cube;
    cube.mlx = mlx_init();
    if (!cube.mlx)
        return (0);
    cube.mlx_win = mlx_new_window(cube.mlx, screenWidth, screenHeight, "Cube_3D");
    if (!cube.mlx_win)
        return (free(cube.mlx), 0);
    cube.img.mlx_img = mlx_new_image(cube.mlx, screenWidth, screenHeight);
    cube.img.addr = mlx_get_data_addr(cube.img.mlx_img, &cube.img.bpp, &cube.img.line_len, &cube.img.endian);
    create_map(NULL, &cube);
    mlx_put_image_to_window(cube.mlx, cube.mlx_win, cube.img.mlx_img, 0, 0);
    mlx_loop(cube.mlx);
    return (1);
}