# include "../cube.h"

void	parse_textures(void)
{
	check_textures();
}

void	check_textures(void)
{
	if (!check_for_valid_texture())
	{
		ft_putstr_fd("Error: Invalid texture\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
}

bool	check_for_valid_texture(void)
{
	if (!check_each_texture(0))
		return (false);
	if (!check_each_texture(1))
		return (false);
	if (!check_each_texture(2))
		return (false);
	if (!check_each_texture(3))
		return (false);
	return (true);
}
bool	check_each_texture(int id)
{
	int fd;

	fd = open(cube()->parse->textures[id].path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Texture %d not found: '%s'\n", id, cube()->parse->textures[id].path);
		return (false);
	}
	// void	*img;

	// img = mlx_xpm_file_to_image(cube()->mlx->mlx, cube()->parse->textures[id].path,
	// 		&cube()->parse->textures[id].width, &cube()->parse->textures[id].height);
	// if (!img)
	// {
	// 	printf("Error: Texture %d with width %d and height %d not found: %s\n", id, cube()->parse->textures[id].width, cube()->parse->textures[id].height, cube()->parse->textures[id].path);
	// 	return (false);
	// }
	// gc_register(img);
	return (true);
}
