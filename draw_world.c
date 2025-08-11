#include "cube.h"
void draw_in_image(t_cube_map * cube , int x , int start_line , int end_line)
{
    while (start_line < end_line)
    {
        img_pix_put( cube->img , x , start_line  ,0x82a14b);
        start_line++;
    }
}
void draw_world()
{
   t_cube_map cube;
    cube.mlx = mlx_init();
    if (!cube.mlx)
        return (0);
    cube.mlx_win = mlx_new_window(cube.mlx, screenWidth, screenHeight, "Cube_3D");
    if (!cube.mlx_win)
        return (free(cube.mlx), 0);
    cube.img.mlx_img = mlx_new_image(cube.mlx,
                                             vars.cords.image_width, vars.cords.image_height);
    cube.img.addr = mlx_get_data_addr(cube.img.mlx_img,
                                              &cube.img.bpp, &cube.img.line_len,
                                              &cube.img.endian);
    draw_in_image();
    mlx_put_image_to_window(cube.mlx, cube.mlx_win,
                            cube.img.mlx_img, 0, 0);
    mlx_loop(cube.mlx);
}