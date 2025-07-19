#include "../cube.h"

void	init_player(void)
{
	cube()->player = gc_malloc(sizeof(t_player));
	if (!cube()->player)
		return;
	
	cube()->player->size = 8;
	cube()->player->x = cube()->mlx->win_width / 2 - cube()->player->size / 2;
	cube()->player->y = cube()->mlx->win_height / 2 - cube()->player->size / 2;
}

void	clear_player_area(int x, int y, int size)
{
	int i, j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			mlx_pixel_put(cube()->mlx->mlx, cube()->mlx->win, 
				x + i, y + j, 0x000000);
			i++;
		}
		j++;
	}
}
void	draw_player_at_position(void)
{
	int i, j;

	j = 0;
	while (j < cube()->player->size)
	{
		i = 0;
		while (i < cube()->player->size)
		{
			mlx_pixel_put(cube()->mlx->mlx, cube()->mlx->win, 
				cube()->player->x + i, cube()->player->y + j, 0xFFFF00);
			i++;
		}
		j++;
	}
}

void	move_player(int dx, int dy)
{
	int new_x, new_y;
	clear_player_area(cube()->player->x, cube()->player->y, cube()->player->size);
	new_x = cube()->player->x + dx;
	new_y = cube()->player->y + dy;
	if (new_x >= 0 && new_x + cube()->player->size <= cube()->mlx->win_width + (cube()->mlx->win_width / cube()->parse->width))
		cube()->player->x = new_x;
	if (new_y >= 0 && new_y + cube()->player->size <= cube()->mlx->win_height + (cube()->mlx->win_height * 0.01))
		cube()->player->y = new_y;
	draw_player_at_position();
}
