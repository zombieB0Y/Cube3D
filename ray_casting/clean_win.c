#include "../cube.h"

int	destroy_window(void)
{
	mlx_destroy_image(cube()->cube_map->mlx, cube()->cube_map->img->mlx_img);
	mlx_destroy_window(cube()->cube_map->mlx, cube()->cube_map->mlx_win);
	mlx_destroy_display(cube()->cube_map->mlx);
	// destroy_texture();
	free(cube()->cube_map->mlx);
	gc_collect();
	exit(0);
}

int	destroy_window_helper(int code)
{
	code++;
	return (destroy_window());
}
