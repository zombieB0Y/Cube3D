#include "../cube.h"

void img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*((int *)pixel) = color;
}
int is_player(char player, int posx, int posy, t_Cube *cube)
{
	if (player == 'E')
		cube->direction = EAST;
	else if (player == 'W')
		cube->direction = WEST;
	else if (player == 'S')
		cube->direction = SOUTH;
	else
		cube->direction = NORTH;
	cube->posx = (float)(posx + 0.5);
	cube->posy = (float)(posy + 0.5);
	return (1);
}
void give_me_map(t_Cube *cube)
{
	int j;
	int i;
	char **map;

	i = 0;
	j = 0;
	map = cube->parse->map->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '0') && (map[i][j] != '1') && (map[i][j] != ' ') && (map[i][j] != 's'))
				is_player(map[i][j], j, i, cube);
			j++;
		}
		i++;
	}
}

int is_wall(char **map, int x, int y)
{
	return (map[y][x] == '1');
}