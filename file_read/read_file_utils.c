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

bool	check_if_valid(char **split_line)
{
	if (!split_line || !split_line[0] || !split_line[1])
		return (false);
	if (ft_strcmp(split_line[0], "NO") != 0 &&
		ft_strcmp(split_line[0], "SO") != 0 &&
		ft_strcmp(split_line[0], "WE") != 0 &&
		ft_strcmp(split_line[0], "EA") != 0 &&
		ft_strcmp(split_line[0], "F") != 0 &&
		ft_strcmp(split_line[0], "C") != 0)
		return (false);
	if (ft_strlen(split_line[1]) == 0)
		return (false);
	return (true);
}

// can change this fucntion to increment for each texture and color
void	load_textures_or_colors(char **split_line)
{
	if (ft_strcmp(split_line[0], "NO") == 0)
	{
		if (cube()->parse->textures[0].loaded)
			ft_putstr_fd("Error: Texture already loaded\n", 2);
		else
		{
			cube()->parse->textures[0].path = ft_strdup(split_line[1]);
			cube()->parse->textures[0].type = TEXTURE_NORTH;
			cube()->parse->textures[0].loaded = true;
		}
	}
	else if (ft_strcmp(split_line[0], "SO") == 0)
	{
		if (cube()->parse->textures[1].loaded)
			ft_putstr_fd("Error: Texture already loaded\n", 2);
		else
		{
			cube()->parse->textures[1].path = ft_strdup(split_line[1]);
			cube()->parse->textures[1].type = TEXTURE_SOUTH;
			cube()->parse->textures[1].loaded = true;
		}
	}
	else if (ft_strcmp(split_line[0], "WE") == 0)
	{
		if (cube()->parse->textures[2].loaded)
			ft_putstr_fd("Error: Texture already loaded\n", 2);
		else
		{
			cube()->parse->textures[2].path = ft_strdup(split_line[1]);
			cube()->parse->textures[2].type = TEXTURE_WEST;
			cube()->parse->textures[2].loaded = true;
		}
	}
	else if (ft_strcmp(split_line[0], "EA") == 0)
	{
		if (cube()->parse->textures[3].loaded)
			ft_putstr_fd("Error: Texture already loaded\n", 2);
		else
		{
			cube()->parse->textures[3].path = ft_strdup(split_line[1]);
			cube()->parse->textures[3].type = TEXTURE_EAST;
			cube()->parse->textures[3].loaded = true;
		}
	}
	else if (ft_strcmp(split_line[0], "F") == 0)
	{
		if (cube()->parse->floor_ceiling->floor_color_loaded)
			ft_putstr_fd("Error: Floor color already set\n", 2);
		else
		{
			cube()->parse->floor_ceiling->floor_color = ft_strdup(split_line[1]);
			cube()->parse->floor_ceiling->floor_color_loaded = true;
		}
	}
	else if (ft_strcmp(split_line[0], "C") == 0)
	{
		if (cube()->parse->floor_ceiling->ceiling_color_loaded)
			ft_putstr_fd("Error: Ceiling color already set\n", 2);
		else
		{
			cube()->parse->floor_ceiling->ceiling_color = ft_strdup(split_line[1]);
			cube()->parse->floor_ceiling->ceiling_color_loaded = true;
		}
	}
}
