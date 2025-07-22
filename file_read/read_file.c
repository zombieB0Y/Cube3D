/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:26:20 by zoentifi          #+#    #+#             */
/*   Updated: 2025/07/22 16:10:36 by zoentifi         ###   ########.fr       */
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

void	read_textures_colors(char *file_name)
{
	int		fd;
	char	*line;
	char	**split_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
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
		line = get_next_line(fd);
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
		else if (size_2d(split_line) != 2)
		{
			ft_putstr_fd("Error: invalid texture line\n", 2);
			gc_collect();
			exit(EXIT_FAILURE);
		} // << to this line norm
		else if (!check_if_valid(split_line))
		{
			printf("Error: Invalid texture line: %s\n", split_line[0]);
			ft_putstr_fd("Error: Invalid texture line\n", 2);
			gc_collect();
			exit(EXIT_FAILURE);
		}
		load_textures_or_colors(split_line);
	}
	cube()->fd = fd;
}


void    read_file(char *file_name)
{
	char 	**map;

	map = NULL;
	(void)map;
	cube()->parse = gc_malloc(sizeof(t_parse));
	if (!cube()->parse)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	cube()->parse->textures = gc_malloc(sizeof(t_texture) * 4);
	ft_memset(cube()->parse->textures, 0, sizeof(t_texture) * 4);
	cube()->parse->floor_ceiling = gc_malloc(sizeof(t_floor_ceiling));
	if (!cube()->parse->floor_ceiling || !cube()->parse->textures)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
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
	// print_textures_colors();
	cube()->parse->map = gc_malloc(sizeof(t_map));
	if (!cube()->parse->map)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	read_map();
	// print_map();
	
}
