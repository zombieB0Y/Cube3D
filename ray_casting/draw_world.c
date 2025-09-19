#include "../cube.h"

int	draw_world(void)
{
	cube()->cube_map = gc_malloc(sizeof(t_cube_map));
	cube()->cube_map->mlx = mlx_init();
	if (!cube()->cube_map->mlx)
		return (0);
	ft_mlx_new_window();
	cube()->cube_map->img = gc_malloc(sizeof(t_img));
	if (!cube()->cube_map->mlx_win || !cube()->cube_map->img)
		return (0);
	ft_mlx_new_image();
	ft_mlx_get_data_addr();
	give_me_map();
	init_textures();
	init_texture_addresses();
	create_map();
	ft_mlx_put_image_to_window();
	mlx_hook(cube()->cube_map->mlx_win, 2, 1L << 0, key_hook, NULL);
	mlx_hook(cube()->cube_map->mlx_win, 17, 0, destroy_window, NULL);
	mlx_loop(cube()->cube_map->mlx);
	return (1);
}
