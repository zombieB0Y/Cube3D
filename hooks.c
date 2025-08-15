#include "cube.h"

static int key_hook_helper(t_Cube *cube, int keycode)
{
	if (keycode == W_KEY)
	{

		cube->posx += (float)(cos((cube->direction * (float)(PI_VALUE / 180))) * MOVESPEED);
		cube->posy += (float)(sin((cube->direction * (float)(PI_VALUE / 180))) * MOVESPEED);
	}
	else if (keycode == S_KEY)
	{
		cube->posx -= cos((cube->direction * (PI_VALUE / 180))) * MOVESPEED;
		cube->posy -= sin((cube->direction * (PI_VALUE / 180))) * MOVESPEED;
	}
	else if (keycode == A_KEY)
	{
		cube->posx -= cos((cube->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
		cube->posy -= sin((cube->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
	}
	else if (keycode == D_KEY)
	{
		cube->posx += cos((cube->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
		cube->posy += sin((cube->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
	}
	else if (keycode == LEFTKEY)
		cube->direction -= 2;
	else if (keycode == RIGHTKEY)
		cube->direction += 2;
	if (cube->posy >= mapHeight || cube->posy < 1)
	{
		if (cube->posy >= mapHeight)
			cube->posy = mapHeight;
		else
			cube->posy = 1;
	}
	if (cube->posx >= mapWidth || cube->posx < 1)
	{
		if (cube->posx >= mapWidth)
			cube->posx = mapWidth;
		else 
			cube->posx = 1;
	}
	return (1);
}

int key_hook(int keycode, t_Cube *cube)
{
	void *old_image;
	if (key_hook_helper(cube, keycode))
	{
		old_image = cube->cube_map.img.mlx_img;
		cube->cube_map.img.mlx_img = mlx_new_image(cube->cube_map.mlx, screenWidth, screenHeight);
		cube->cube_map.img.addr = mlx_get_data_addr(cube->cube_map.img.mlx_img,
													&cube->cube_map.img.bpp, &cube->cube_map.img.line_len,
													&cube->cube_map.img.endian);
		if (old_image)
			mlx_destroy_image(cube->cube_map.mlx, old_image);
		create_map(NULL, cube);
		mlx_put_image_to_window(cube->cube_map.mlx, cube->cube_map.mlx_win,
								cube->cube_map.img.mlx_img, 0, 0);
	}
	else if (keycode == 65307)
	{
		exit(0);
	}
	return (1);
}