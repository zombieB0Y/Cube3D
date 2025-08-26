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
	cube->posx =(float)( posx + 0.5);
	cube->posy =(float)( posy + 0.5);
	return (1);
}
