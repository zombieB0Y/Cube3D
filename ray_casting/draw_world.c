#include "../cube.h"


long    convert_rgb(char c)
{
	long color;
	int r;
	int g;
	int b;

	if (c == 'c')
	{
		r = cube()->parse->floor_ceiling->ceiling_rgb->r;
		g = cube()->parse->floor_ceiling->ceiling_rgb->g;
		b = cube()->parse->floor_ceiling->ceiling_rgb->b;
	}
	else
	{
		r = cube()->parse->floor_ceiling->floor_rgb->r;
		g = cube()->parse->floor_ceiling->floor_rgb->g;
		b = cube()->parse->floor_ceiling->floor_rgb->b;
	}
	color = (r * 65536) + (g * 256) + b;
	return (color);
}

void draw_in_image(t_cube_map *cube1, int x, int start_line, int end_line, int side)
{
	int pixel;

	pixel = 0;
	while (pixel < screenHeight - 1)
	{

		if (pixel >= start_line && pixel <= end_line)
		{
			if (side)
				img_pix_put(&(cube1->img), x, pixel, 0xFF94F3);
			else
				img_pix_put(&(cube1->img), x, pixel, 0xC742B6);
		}
		else if (pixel < start_line)
			img_pix_put(&(cube1->img), x, pixel, convert_rgb('c'));
		else if (pixel > end_line)
			img_pix_put(&(cube1->img), x, pixel, convert_rgb('f'));

		pixel++;
	}
}

void	init_textures(void)
{
	cube()->parse->textures[0].img = mlx_xpm_file_to_image(cube()->cube_map.mlx,
		cube()->parse->textures[0].path, &cube()->parse->textures[0].width, &cube()->parse->textures[0].height);
    cube()->parse->textures[1].img = mlx_xpm_file_to_image(cube()->cube_map.mlx,
		cube()->parse->textures[1].path, &cube()->parse->textures[1].width, &cube()->parse->textures[1].height);
    cube()->parse->textures[2].img = mlx_xpm_file_to_image(cube()->cube_map.mlx,
		cube()->parse->textures[2].path, &cube()->parse->textures[2].width, &cube()->parse->textures[2].height);
    cube()->parse->textures[3].img = mlx_xpm_file_to_image(cube()->cube_map.mlx,
		cube()->parse->textures[3].path, &cube()->parse->textures[3].width, &cube()->parse->textures[3].height);
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
	init_textures();
	create_map(&cube_instance);

	mlx_put_image_to_window(cube_instance.cube_map.mlx, cube_instance.cube_map.mlx_win, cube_instance.cube_map.img.mlx_img, 0, 0);
	mlx_hook(cube_instance.cube_map.mlx_win, 2, 1L << 0, key_hook, &cube_instance);
	mlx_hook(cube_instance.cube_map.mlx_win, 17, 0, destroy_window, &cube_instance);
	mlx_loop(cube_instance.cube_map.mlx);
	return (1);
}
