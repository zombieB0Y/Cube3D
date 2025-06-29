/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:26:20 by zoentifi          #+#    #+#             */
/*   Updated: 2025/06/29 18:02:52 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"


void	load_map(char *file_name, char **map)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: could not open file\n", 2);
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (!map)
			map = gc_malloc(sizeof(char *) * 1);
		else
			map = ft_realloc(map, sizeof(char *) * (cube()->parse->height + 1),
							sizeof(char *) * (cube()->parse->height + 2));
		if (!map)
		{
			gc_collect();
			exit(EXIT_FAILURE);
		}
		map[cube()->parse->height] = line;
		cube()->parse->height++;
	}
}

void	load_textures(char *file_name)
{
	int		fd;
	char	*line;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Could not open file\n", 2);
		exit(EXIT_FAILURE);
	}
}

void    read_file(char *file_name)
{
	char 	**map;

	map = NULL;
	cube()->parse = gc_malloc(sizeof(t_parse));
	if (!cube()->parse)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	cube()->parse->textures = gc_malloc(sizeof(t_texture));
	if (!cube()->parse->textures)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	cube()->parse->floor_ceiling = gc_malloc(sizeof(t_floor_ceiling));
	if (!cube()->parse->floor_ceiling)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	load_map(file_name, map);
	load_textures(file_name);	
}
