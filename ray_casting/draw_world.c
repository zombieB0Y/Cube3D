#include "../cube.h"
char *hard_coded_map[] = {
    "1111111111111111",
    "1000000000000001",
    "1000000000000001",
    "1000000000000001",
    "100000000000W001",
    "1000010000000001",
    "1111111111111111",
    NULL};

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
    t_Cube cube_instance;

    cube_instance = *(cube());
    cube_instance.cube_map.mlx = mlx_init();
    if (!cube_instance.cube_map.mlx)
        return (0);
    cube_instance.cube_map.mlx_win = mlx_new_window(cube_instance.cube_map.mlx, screenWidth, screenHeight, "Cube_3D");
    if (!cube_instance.cube_map.mlx_win)
        return (free(cube_instance.cube_map.mlx), 0);
    cube_instance.cube_map.img.mlx_img = mlx_new_image(cube_instance.cube_map.mlx, screenWidth, screenHeight);
    cube_instance.cube_map.img.addr = mlx_get_data_addr(cube_instance.cube_map.img.mlx_img, &cube_instance.cube_map.img.bpp, &cube_instance.cube_map.img.line_len, &cube_instance.cube_map.img.endian);
    give_me_map(&cube_instance);
    create_map( &cube_instance);

    mlx_put_image_to_window(cube_instance.cube_map.mlx, cube_instance.cube_map.mlx_win, cube_instance.cube_map.img.mlx_img, 0, 0);
    mlx_hook(cube_instance.cube_map.mlx_win, 2, 1L << 0, key_hook, &cube_instance);
    mlx_hook(cube_instance.cube_map.mlx_win, 3, 1L << 1, key_hook, &cube_instance);
    mlx_loop(cube_instance.cube_map.mlx);
    return (1);
}
