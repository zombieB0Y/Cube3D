/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:02:28 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/23 21:52:16 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (ft_strcmp(split_line[0], "NO") != 0
		&& ft_strcmp(split_line[0], "SO") != 0
		&& ft_strcmp(split_line[0], "WE") != 0
		&& ft_strcmp(split_line[0], "EA") != 0
		&& ft_strcmp(split_line[0], "F") != 0
		&& ft_strcmp(split_line[0], "C") != 0)
		return (false);
	if (ft_strlen(split_line[1]) == 0)
		return (false);
	return (true);
}

void	load(t_texture_type texture, char **split_line)
{
	cube()->parse->textures[(int)texture].path = ft_strdup(split_line[1]);
	cube()->parse->textures[(int)texture].type = texture;
	cube()->parse->textures[(int)texture].loaded = true;
}

void	check_for_texture(char **split_line)
{
	int		i;
	char	**symbols;

	i = 0;
	symbols = load_symbols();
	while (i < 4)
	{
		if (ft_strcmp(split_line[0], symbols[i]) == 0)
		{
			if (cube()->parse->textures[i].loaded)
			{
				ft_putstr_fd("Error: Texture already loaded\n", 2);
				gc_collect();
				exit(EXIT_FAILURE);
			}
			else
				load(i, split_line);
			break ;
		}
		i++;
	}
}

void	load_textures_or_colors(char **split_line)
{
	ft_memset(split_line[1] + ft_strlen(split_line[1]) - 1, 0, 1);
	check_for_texture(split_line);
	if (ft_strcmp(split_line[0], "F") == 0)
	{
		if (cube()->parse->floor_ceiling->floor_color_loaded)
			error("Error: Floor color already set\n");
		else if (cube()->parse->floor_ceiling->floor_color)
			cube()->parse->floor_ceiling->floor_color_loaded = true;
	}
	else if (ft_strcmp(split_line[0], "C") == 0)
	{
		if (cube()->parse->floor_ceiling->ceiling_color_loaded)
			error("Error: Ceiling color already set\n");
		else if (cube()->parse->floor_ceiling->ceiling_color)
			cube()->parse->floor_ceiling->ceiling_color_loaded = true;
	}
}
