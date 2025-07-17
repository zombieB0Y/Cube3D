#include "../cube.h"

bool	check_for_whitespace(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (false);
		line++;
	}
	return (true);
}

void	check_textures(void)
{
	if (!cube()->parse->textures[0].loaded ||
		!cube()->parse->textures[1].loaded ||
		!cube()->parse->textures[2].loaded ||
		!cube()->parse->textures[3].loaded)
	{
		ft_putstr_fd("Error: Not all textures loaded\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
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
	void	*img;

	img = mlx_xpm_file_to_image(cube()->mlx, cube()->parse->textures[id].path,
			&cube()->parse->textures[id].width, &cube()->parse->textures[id].height);
	if (!img)
	{
		img = mlx_png_file_to_image(cube()->mlx, cube()->parse->textures[id].path,
			&cube()->parse->textures[id].width, &cube()->parse->textures[id].height);
		if (!img)
			return (false);
	}
	gc_register(img);
	return (true);
}