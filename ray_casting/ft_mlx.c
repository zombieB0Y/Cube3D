#include "../cube.h"

void	ft_mlx_new_image(void)
{
	void	*mlx;
	void	*new_image;

	mlx = cube()->cube_map->mlx;
	new_image = mlx_new_image(mlx, screenWidth, screenHeight);
	cube()->cube_map->img->mlx_img = new_image;
}

void	ft_mlx_get_data_addr(void)
{
	void	*new_adress;
	void	*mlx_image;
	int		*bpp;
	int		*line_len;
	int		*endian;

	mlx_image = cube()->cube_map->img->mlx_img;
	bpp = &cube()->cube_map->img->bpp;
	line_len = &cube()->cube_map->img->line_len;
	endian = &cube()->cube_map->img->endian;
	new_adress = mlx_get_data_addr(mlx_image, bpp, line_len, endian);
	cube()->cube_map->img->addr = new_adress;
}

void	ft_mlx_put_image_to_window(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;

	mlx_img = cube()->cube_map->img->mlx_img;
	mlx_win = cube()->cube_map->mlx_win;
	mlx = cube()->cube_map->mlx;
	mlx_put_image_to_window(mlx, mlx_win, mlx_img, 0, 0);
}

void	ft_mlx_new_window(void)
{
	void	*mlx_win;
	void	*mlx;

	mlx = cube()->cube_map->mlx;
	mlx_win = mlx_new_window(mlx, screenWidth, screenHeight, WIN);
	cube()->cube_map->mlx_win = mlx_win;
}
