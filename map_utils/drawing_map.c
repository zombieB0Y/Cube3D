# include "../cube.h"

void	draw_map(void)
{
	int		x;
	int		y;

    cube()->parse->map->width = 15;
    cube()->parse->map->height = 10;
	y = 0;
	while (y < cube()->parse->map->height)
	{
		x = 0;
		while (x < cube()->parse->map->width)
		{
			draw_tile(x, y, cube()->parse->map->map[y][x]);
			x++;
		}
		y++;
	}
}
void	draw_tile(int x, int y, char tile)
{
    int		tile_size;

    tile_size = 64;
    if (tile == '1')
        draw_rectangle(x * tile_size, y * tile_size, tile_size, tile_size, 0xFFFFFF);
    else if (tile == '0')
        draw_rectangle(x * tile_size, y * tile_size, tile_size, tile_size, 0x000000);
}
void	draw_rectangle(int x, int y, int width, int height, int color)
{
    int		i;
    int		j;

    i = 1;
    while (i < height - 1)
    {
        j = 1;
        while (j < width - 1)
        {
            mlx_pixel_put(cube()->mlx->mlx, cube()->mlx->win, x + j, y + i, color);
            j++;
        }
        i++;
    }
}
