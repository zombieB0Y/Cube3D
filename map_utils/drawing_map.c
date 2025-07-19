# include "../cube.h"

void	draw_map(void)
{
	int		x;
	int		y;

	y = 0;
	while (y < cube()->parse->height)
	{
		x = 0;
		while (x < cube()->parse->width)
		{
			draw_tile(x, y, cube()->parse->map[y][x]);
			x++;
		}
		y++;
	}
}
void	draw_tile(int x, int y, char tile)
{
    int		tile_x;
    int		tile_y;

    tile_x = cube()->mlx->win_width / cube()->parse->width;
    tile_y = cube()->mlx->win_height / cube()->parse->height;
    if (tile == '1')
        draw_rectangle(x * tile_x, y * tile_y, tile_x, tile_y, 0xFFFFFF);
    else if (tile == '0')
        draw_rectangle(x * tile_x, y * tile_y, tile_x, tile_y, 0x000000);
}
void	draw_rectangle(int x, int y, int width, int height, int color)
{
    int		i;
    int		j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            mlx_pixel_put(cube()->mlx->mlx, cube()->mlx->win, x + j, y + i, color);
            j++;
        }
        i++;
    }
}
