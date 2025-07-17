/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:26:20 by zoentifi          #+#    #+#             */
/*   Updated: 2025/07/17 17:21:59 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
	while (1)
	{
		if (cube()->parse->textures[0].loaded &&
			cube()->parse->textures[1].loaded &&
			cube()->parse->textures[2].loaded &&
			cube()->parse->textures[3].loaded)
			break ;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "NO ", 3) == 0 &&
				!cube()->parse->textures[0].loaded)
		{
			cube()->parse->textures[0].path = ft_strdup(line + 3);
			cube()->parse->textures[0].type = TEXTURE_NORTH;
			cube()->parse->textures[0].loaded = true;			
		}
		else if (ft_strncmp(line, "SO ", 3) == 0 &&
				!cube()->parse->textures[1].loaded)
		{
			cube()->parse->textures[1].path = ft_strdup(line + 3);
			cube()->parse->textures[1].type = TEXTURE_SOUTH;
			cube()->parse->textures[1].loaded = true;
		}
		else if (ft_strncmp(line, "WE ", 3) == 0 &&
				!cube()->parse->textures[2].loaded)
		{
			cube()->parse->textures[2].path = ft_strdup(line + 3);
			cube()->parse->textures[2].type = TEXTURE_WEST;
			cube()->parse->textures[2].loaded = true;
		}
		else if (ft_strncmp(line, "EA ", 3) == 0 &&
				!cube()->parse->textures[3].loaded)
		{
			cube()->parse->textures[3].path = ft_strdup(line + 3);
			cube()->parse->textures[3].type = TEXTURE_EAST;
			cube()->parse->textures[3].loaded = true;
		}
		else if (!check_for_whitespace(line))
		{
			ft_putstr_fd("Error: Invalid texture line\n", 2);
			gc_collect();
			exit(EXIT_FAILURE);
		}
	}
}

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
	while ((line = get_next_line(fd)) != NULL)
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

void	print_textures(t_texture *textures)
{
	for (int i = 0; i < 4; i++)
	{
		if (textures[i].loaded)
		{
			ft_putstr_fd("Texture ", 1);
			ft_putstr_fd(textures[i].path, 1);
			ft_putstr_fd(" loaded successfully\n", 1);
		}
		else
		{
			ft_putstr_fd("Texture not loaded\n", 2);
		}
	}
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
	load_textures(file_name);
	if (!cube()->parse->textures[0].loaded ||
		!cube()->parse->textures[1].loaded ||
		!cube()->parse->textures[2].loaded ||
		!cube()->parse->textures[3].loaded)
	{
		ft_putstr_fd("Error: Not all textures loaded\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	// print_textures(cube()->parse->textures);
	check_textures();
	// load_map(file_name, map); // not right now, just a placeholder
}
