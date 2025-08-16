#include "cube.h"

int check_distance_true(t_Cube *cube, float direction_move)
{
	if (wall_distance(cube, direction_move) <= 0.9)
	{
		if (wall_distance(cube, direction_move + 20) <= 0.9)
		{
			if (wall_distance(cube, direction_move - 20) <= 0.9)
			{
				return (0);
			}
		}
	}
	return (1);
}

static int key_hook_helper(t_Cube *cube, int keycode)
{
	float walldistance;
	float direction_mov;
	float old_posx;
	float old_posy;
	int move;

	old_posx = cube->posx;
	old_posy = cube->posy;
	direction_mov = cube->direction;
	if (keycode == LEFTKEY || keycode == RIGHTKEY)
	{
		if (keycode == LEFTKEY)
		{
			// printf("walldistance = %f  || direction_move = %f \n", walldistance, direction_mov);
			cube->direction -= 2;
			return (1);
		}
		else if (keycode == RIGHTKEY)
		{
			// printf("walldistance = %f  || direction_move = %f \n", walldistance, direction_mov);
			cube->direction += 2;
			return (1);
		}
	}
	else
	{
		mv(cube , keycode , &direction_mov);
	}

	if (is_wall((int)cube->posx, (int)cube->posy) || wall_distance(cube,direction_mov) <= 0.3)
	{
		cube->posx = old_posx;
		cube->posy = old_posy;
		return (0);
	};
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