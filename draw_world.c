#include "cube.h"
void draw_in_image(t_cube_map *cube, int x, int start_line, int end_line, int side)
{
    int pixel;

    pixel = 0;
    while (pixel < screenHeight - 1)
    {

        if (pixel >= start_line && pixel <= end_line)
        {
            if (side)
                img_pix_put(&(cube->img), x, pixel, 0xFF94F3);
            else
                img_pix_put(&(cube->img), x, pixel, 0xC742B6);
        }
        else if (pixel < start_line)
            img_pix_put(&(cube->img), x, pixel, 0xC0FAF9);
        else if (pixel > end_line)
            img_pix_put(&(cube->img), x, pixel, 0x694710);

        pixel++;
    }
}
int draw_world()
{
    t_Cube cube;
    cube.cube_map.mlx = mlx_init();
    if (!cube.cube_map.mlx)
        return (0);
    cube.cube_map.mlx_win = mlx_new_window(cube.cube_map.mlx, screenWidth, screenHeight, "Cube_3D");
    if (!cube.cube_map.mlx_win)
        return (free(cube.cube_map.mlx), 0);
    cube.cube_map.img.mlx_img = mlx_new_image(cube.cube_map.mlx, screenWidth, screenHeight);
    cube.cube_map.img.addr = mlx_get_data_addr(cube.cube_map.img.mlx_img, &cube.cube_map.img.bpp, &cube.cube_map.img.line_len, &cube.cube_map.img.endian);
    initial_values(&cube);
    create_map(NULL, &cube);

    mlx_put_image_to_window(cube.cube_map.mlx, cube.cube_map.mlx_win, cube.cube_map.img.mlx_img, 0, 0);
	mlx_key_hook(cube.cube_map.mlx_win, key_hook, &cube);
    mlx_loop(cube.cube_map.mlx);
    return (1);
}