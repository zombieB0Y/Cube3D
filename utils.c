#include "cube.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*((int *) pixel) = color;
}




int	destroy_window(t_vars *vars)
{
	mlx_destroy_image(vars->fractal.mlx, vars->fractal.img.mlx_img);
	mlx_destroy_window(vars->fractal.mlx, vars->fractal.mlx_win);
	mlx_destroy_display(vars->fractal.mlx);
	free(vars->fractal.mlx);
	exit(0);
}

int	destroy_window_helper(int code, t_vars *vars)
{
	code++;
	return (destroy_window(vars));
}
