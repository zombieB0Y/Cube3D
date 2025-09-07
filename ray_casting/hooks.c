#include "../cube.h"


static int valid_key(int keycode)
{
	return ((keycode == LEFTKEY) || (keycode == RIGHTKEY) || (keycode == W_KEY) || (keycode == D_KEY) || (keycode == A_KEY) || (keycode == S_KEY) || (keycode == ESC));

}
static int will_he_moves(float old_posx, float old_posy, float direction_mov)
{
	if (is_wall(cube()->parse->map->map, (int)cube()->posx, (int)cube()->posy) || wall_distance(direction_mov) <= 0.3)
	{
		cube()->posx = old_posx;
		cube()->posy = old_posy;
		return (0);
	};
	return (1);
}

static int key_hook_helper(int keycode)
{
	float direction_mov;
	float old_posx;
	float old_posy;

	old_posx = cube()->posx;
	old_posy = cube()->posy;
	direction_mov = cube()->direction;
	if (keycode == LEFTKEY || keycode == RIGHTKEY)
	{
		if (keycode == LEFTKEY)
			cube()->direction -= 2;

		else if (keycode == RIGHTKEY)
			cube()->direction += 2;
		return (1);
	}
	else
	{
		mv(keycode, &direction_mov);
	}

	return (will_he_moves(old_posx, old_posy, direction_mov));
}

int key_hook(int keycode)
{
	if (!valid_key(keycode))
		return(0);
	if (keycode == ESC)
		destroy_window(cube);
	void *old_image;
	if (key_hook_helper(keycode))
	{
		old_image = cube()->cube_map->img->mlx_img;
		cube()->cube_map->img->mlx_img = mlx_new_image(cube()->cube_map->mlx, screenWidth, screenHeight);
		cube()->cube_map->img->addr = mlx_get_data_addr(cube()->cube_map->img->mlx_img,
													&cube()->cube_map->img->bpp, &cube()->cube_map->img->line_len,
													&cube()->cube_map->img->endian);
		if (old_image)
			mlx_destroy_image(cube()->cube_map->mlx, old_image);
		create_map(cube);
		mlx_put_image_to_window(cube()->cube_map->mlx, cube()->cube_map->mlx_win,
								cube()->cube_map->img->mlx_img, 0, 0);
	}
	else if (keycode == 65307)
	{
		exit(0);
	}
	return (1);
}
