/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:26:20 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/22 23:24:15 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void load_floor_ceiling_colors(char **split_line)
{
	int i;
	char *flor_color;
	char *celling_color;

	celling_color = cube()->parse->floor_ceiling->ceiling_color;
	flor_color = cube()->parse->floor_ceiling->floor_color;

	i = 1;
	while (split_line[i])
	{
		if (split_line[0][0] == 'F')
		{
			flor_color = ft_strjoin(flor_color, split_line[i]);
			cube()->parse->floor_ceiling->floor_color = flor_color;
		}
		else
		{
			celling_color = ft_strjoin(celling_color, split_line[i]);
			cube()->parse->floor_ceiling->ceiling_color =celling_color;
		}
		i++;
	}
}

bool is_it_loaded(void)
{
	if (cube()->parse->textures[0].loaded &&
		cube()->parse->textures[1].loaded &&
		cube()->parse->textures[2].loaded &&
		cube()->parse->textures[3].loaded &&
		cube()->parse->floor_ceiling->floor_color_loaded &&
		cube()->parse->floor_ceiling->ceiling_color_loaded)
		return (true);
	return (false);
}

void read_textures_colors(char *file_name)
{
	char *line;
	char **split_line;

	cube()->fd = open(file_name, O_RDONLY);
	if (cube()->fd < 0)
	{
		ft_putstr_fd("Error: Could not open file\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (is_it_loaded())
			break;
		line = get_next_line(cube()->fd);
		if (!line)
			break;
		if (check_for_whitespace(line))
			continue;
		split_line = ft_split(line, ' ');
		checking_split_line(split_line);
	}
}

void init_parse(void)
{
	cube()->parse = gc_malloc(sizeof(t_parse));
	if (!cube()->parse)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	ft_memset(cube()->parse, 0, sizeof(t_parse));
	cube()->parse->textures = gc_malloc(sizeof(t_texture) * 4);
	cube()->parse->floor_ceiling = gc_malloc(sizeof(t_floor_ceiling));
	if (!cube()->parse->floor_ceiling || !cube()->parse->textures)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	ft_memset(cube()->parse->textures, 0, sizeof(t_texture) * 4);
	ft_memset(cube()->parse->floor_ceiling, 0, sizeof(t_floor_ceiling));
}

void read_file(char *file_name)
{
	init_parse();
	read_textures_colors(file_name);
	if (!cube()->parse->textures[0].loaded ||
		!cube()->parse->textures[1].loaded ||
		!cube()->parse->textures[2].loaded ||
		!cube()->parse->textures[3].loaded ||
		!cube()->parse->floor_ceiling->floor_color_loaded ||
		!cube()->parse->floor_ceiling->ceiling_color_loaded)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	cube()->parse->map = gc_malloc(sizeof(t_map));
	if (!cube()->parse->map)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	ft_memset(cube()->parse->map, 0, sizeof(t_map));
	read_map();
}
