#include "../cube.h"

bool	parse_color(char **tokens)
{
	t_color	*color;

	color = gc_malloc(sizeof(t_color));
	if (!color)
	{

		ft_putstr_fd("Error: Failed to allocate memory for color\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	if (size_2d(tokens) == 3)
	{
		color->r = ft_atoi(tokens[0]);
		color->g = ft_atoi(tokens[1]);
		color->b = ft_atoi(tokens[2]);
	}
	else
	{
		ft_putstr_fd("Error: Invalid color format \n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	check_color_range(color);
	return (true);
}

void	check_color_range(t_color *color)
{
	if (color->r < 0 || color->r > 255 ||
		color->g < 0 || color->g > 255 ||
		color->b < 0 || color->b > 255)
	{
		ft_putstr_fd("Error: Color values must be between 0 and 255\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
}
