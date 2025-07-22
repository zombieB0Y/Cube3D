#include "cube.h"

void	print_textures_colors()
{
	for (int i = 0; i < 4; i++)
	{
		if (cube()->parse->textures[i].loaded)
		{
			ft_putstr_fd("Texture ", 1);
			ft_putstr_fd(cube()->parse->textures[i].path, 1);
			ft_putstr_fd(" loaded successfully\n", 1);
		}
		else
		{
			ft_putstr_fd("Texture not loaded\n", 2);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (i == 0 && cube()->parse->floor_ceiling->floor_color_loaded)
		{
			ft_putstr_fd("Floor color: ", 1);
			ft_putstr_fd(cube()->parse->floor_ceiling->floor_color, 1);
			ft_putstr_fd(" loaded successfully\n", 1);
		}
		else if (i == 1 && cube()->parse->floor_ceiling->ceiling_color_loaded)
		{
			ft_putstr_fd("Ceiling color: ", 1);
			ft_putstr_fd(cube()->parse->floor_ceiling->ceiling_color, 1);
			ft_putstr_fd(" loaded successfully\n", 1);
		}
		else
		{
			ft_putstr_fd("Color not loaded\n", 2);
		}
	}	
}