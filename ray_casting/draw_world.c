#include "../cube.h"


long    convert_rgb(char c)
{
	long color;
	int r;
	int g;
	int b;

	if (c == 'c')
	{
		r = cube()->parse->floor_ceiling->ceiling_rgb->r;
		g = cube()->parse->floor_ceiling->ceiling_rgb->g;
		b = cube()->parse->floor_ceiling->ceiling_rgb->b;
	}
	else
	{
		r = cube()->parse->floor_ceiling->floor_rgb->r;
		g = cube()->parse->floor_ceiling->floor_rgb->g;
		b = cube()->parse->floor_ceiling->floor_rgb->b;
	}
	color = (r * 65536) + (g * 256) + b;
	return (color);
}

int get_texture_pixel(t_texture *texture, int x, int y)
{
	char *pixel;
	
	pixel = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
	return (*((int *)pixel));
}

int get_texture_index(int side, float raydirx, float raydiry)
{
	if (side == 1)
	{
		if (raydirx > 0)
			return (TEXTURE_EAST);
		else
			return (TEXTURE_WEST);
	}
	else
	{
		if (raydiry > 0)
			return (TEXTURE_SOUTH);
		else
			return (TEXTURE_NORTH);
	}
}

void draw_in_image(t_cube_map *cube1, int x, int start_line, int end_line, int side)
{
	// struct for norm
	int pixel;
	int texture_index;
	t_texture *texture;
	float wallx;
	int texx;
	int texy;
	float step;
	float texpos;
	int color;
	//-----------
	pixel = 0;
	texture_index = get_texture_index(side, cube()->raydirx, cube()->raydiry);
	texture = &cube()->parse->textures[texture_index];
	if (side == 1)
		wallx = cube()->posy + cube()->walldist * cube()->raydiry;
	else
		wallx = cube()->posx + cube()->walldist * cube()->raydirx;
	wallx -= floor(wallx);
	texx = (wallx * (double)texture->width);
	
	step = texture->height / cube()->lineheight;
	texpos = (start_line - screenHeight / 2 + cube()->lineheight / 2) * step;
	
	while (pixel < screenHeight - 1)
	{
		if (pixel >= start_line && pixel <= end_line)
		{
			if (texture->addr)
			{
				texy = abs((int)texpos) % texture->height;
				texpos += step;
				color = get_texture_pixel(texture, texx, texy);
			}
			else
			{
				if (side)
					color = 0xFF94F3;
				else
					color = 0xC742B6;
			}
			img_pix_put(cube1->img, x, pixel, color);
		}
		else if (pixel < start_line)
			img_pix_put(cube1->img, x, pixel, convert_rgb('c'));
		else if (pixel > end_line)
			img_pix_put(cube1->img, x, pixel, convert_rgb('f'));

		pixel++;
	}
}

void	init_texture_addresses(void)
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		if (cube()->parse->textures[i].img)
		{
			cube()->parse->textures[i].addr = mlx_get_data_addr(cube()->parse->textures[i].img,
				&cube()->parse->textures[i].bits_per_pixel, &cube()->parse->textures[i].line_length,
				&cube()->parse->textures[i].endian);
		}
		else
		{
			cube()->parse->textures[i].addr = NULL;
		}
		i++;
	}
}

void	init_textures(void)
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		// printf("%s\n", cube()->parse->textures[i].path);
		cube()->parse->textures[i].img = mlx_xpm_file_to_image(cube()->cube_map->mlx,
			cube()->parse->textures[i].path, &cube()->parse->textures[i].width, &cube()->parse->textures[i].height);
		if (!cube()->parse->textures[i].img)
		{
			printf("Failed to load texture %d\n", i);
			cube()->parse->textures[i].width = 64;
			cube()->parse->textures[i].height = 64;
			cube()->parse->textures[i].img = NULL;
		}
		i++;
	}
}

int draw_world()
{
	// t_Cube cube_instance;

	// cube_instance = *(cube());
	cube()->cube_map = gc_malloc(sizeof(t_cube_map));
	cube()->cube_map->mlx = mlx_init();
	if (!cube()->cube_map->mlx)
		return (0);
	cube()->cube_map->mlx_win = mlx_new_window(cube()->cube_map->mlx, screenWidth, screenHeight, "Cube_3D");
	cube()->cube_map->img = gc_malloc(sizeof(t_img));
	if (!cube()->cube_map->mlx_win || !cube()->cube_map->img)
		return (0);
	cube()->cube_map->img->mlx_img = mlx_new_image(cube()->cube_map->mlx, screenWidth, screenHeight);
	cube()->cube_map->img->addr = mlx_get_data_addr(cube()->cube_map->img->mlx_img, &cube()->cube_map->img->bpp, &cube()->cube_map->img->line_len, &cube()->cube_map->img->endian);
	
	give_me_map();
	init_textures();
	init_texture_addresses();
	// *(cube()) = cube_instance;
	create_map();

	mlx_put_image_to_window(cube()->cube_map->mlx, cube()->cube_map->mlx_win, cube()->cube_map->img->mlx_img, 0, 0);
	mlx_hook(cube()->cube_map->mlx_win, 2, 1L << 0, key_hook, NULL);
	mlx_hook(cube()->cube_map->mlx_win, 17, 0, destroy_window, NULL);
	mlx_loop(cube()->cube_map->mlx);
	return (1);
}
