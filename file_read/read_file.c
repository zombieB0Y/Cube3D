/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:26:20 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/14 16:41:11 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	size_2d(char **arr)
{
	int i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	load_floor_ceiling_colors(char **split_line)
{
	int i;

	i = 1;
	while (split_line[i])
	{
		if (split_line[0][0] == 'F')
		{
			cube()->parse->floor_ceiling->floor_color = ft_strjoin(cube()->parse->floor_ceiling->floor_color, split_line[i]);
		}
		else
			cube()->parse->floor_ceiling->ceiling_color = ft_strjoin(cube()->parse->floor_ceiling->ceiling_color, split_line[i]);
		i++;
	}
}

void	read_textures_colors(char *file_name)
{
	char	*line;
	char	**split_line;

	cube()->fd = open(file_name, O_RDONLY);
	if (cube()->fd < 0)
	{
		ft_putstr_fd("Error: Could not open file\n", 2);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (cube()->parse->textures[0].loaded &&
			cube()->parse->textures[1].loaded &&
			cube()->parse->textures[2].loaded &&
			cube()->parse->textures[3].loaded &&
			cube()->parse->floor_ceiling->floor_color_loaded &&
			cube()->parse->floor_ceiling->ceiling_color_loaded)
			break ;
		line = get_next_line(cube()->fd);
		if (!line)
			break ;
		if (check_for_whitespace(line))
			continue ;
		split_line = ft_split(line, ' ');
		if (!split_line) // from this line to >>
		{
			gc_collect();
			exit(EXIT_FAILURE);
		}
		if (split_line[0][0] == 'F' || split_line[0][0] == 'C')
			load_floor_ceiling_colors(split_line);
		else if (size_2d(split_line) != 2)
		{
			ft_putstr_fd("Error: invalid texture line\n", 2);
			gc_collect();
			exit(EXIT_FAILURE);
		} // << to this line norm
		else if (!check_if_valid(split_line))
		{
			ft_putstr_fd("Error: Invalid texture line\n", 2);
			gc_collect();
			exit(EXIT_FAILURE);
		}
		load_textures_or_colors(split_line);
	}
}


void	init_parse(void)
{
	cube()->parse = gc_malloc(sizeof(t_parse));
	ft_memset(cube()->parse, 0, sizeof(t_parse));
	if (!cube()->parse)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
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

void    read_file(char *file_name)
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
