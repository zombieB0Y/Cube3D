#include "cube.h"

static int	key_hook_helper(t_Cube *cube, int keycode)
{
	if (keycode == UPKEY)
	{
        cube->posx +=(cube->raydirx * MOVESPEED);
        cube->posy +=(cube->raydiry * MOVESPEED);
	}
	else if (keycode == DOWNKEY)
	{
		cube->posx -=(cube->raydirx * MOVESPEED);
        cube->posy -=(cube->raydiry * MOVESPEED);
	}
	else if (keycode == RIGHTKEY)
	{
		cube->posx +=(cube->raydirx * MOVESPEED);
        cube->posy +=(cube->raydiry * MOVESPEED);
	}
	else if (keycode == LEFTKEY)
	{
		cube->posx +=(cube->raydirx * MOVESPEED);
        cube->posy +=(cube->raydiry * MOVESPEED);
	}
	return (1);
}

int	key_hook(int keycode, t_Cube *cube)
{
	void	*old_image;

	if (key_hook_helper(cube, keycode))
	{
		vars->cords.cx = (vars->cords.max_re + vars->cords.min_re) / 2;
		vars->cords.cy = (vars->cords.max_im + vars->cords.min_im) / 2;
		old_image = vars->fractal.img.mlx_img;
		vars->fractal.img.mlx_img = mlx_new_image(vars->fractal.mlx,
				vars->cords.image_width, vars->cords.image_height);
		vars->fractal.img.addr = mlx_get_data_addr(vars->fractal.img.mlx_img,
				&vars->fractal.img.bpp, &vars->fractal.img.line_len,
				&vars->fractal.img.endian);
		if (old_image)
			mlx_destroy_image(vars->fractal.mlx, old_image);
		vars->draw(vars);
		mlx_put_image_to_window(vars->fractal.mlx, vars->fractal.mlx_win,
			vars->fractal.img.mlx_img, 0, 0);
	}
	else if (keycode == 65307)
	{
		destroy_window(vars);
		exit(0);
	}
	return (1);
}