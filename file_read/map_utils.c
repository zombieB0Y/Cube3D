/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 00:00:00 by zm                #+#    #+#             */
/*   Updated: 2025/09/22 22:49:49 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void init_new_map(void)
{
	int i;

	i = 0;
	cube()->parse->new_map = gc_malloc(sizeof(char *) * (cube()->parse->map->height + 3));
	if (!cube()->parse->new_map)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	while (i < cube()->parse->map->height + 2)
	{
		cube()->parse->new_map[i] = gc_malloc(sizeof(char) * (cube()->parse->map->width + 3));
		if (!cube()->parse->new_map[i])
		{
			gc_collect();
			exit(EXIT_FAILURE);
		}
		ft_memset(cube()->parse->new_map[i], ' ', cube()->parse->map->width + 2);
		cube()->parse->new_map[i][cube()->parse->map->width + 2] = '\0';
		i++;
	}
	cube()->parse->new_map[i] = NULL;
}

void init_line()
{

	if (!cube()->parse->tmp)
		cube()->parse->line = get_next_line(cube()->fd);
	else
	{
		cube()->parse->line = cube()->parse->tmp;
		cube()->parse->tmp = NULL;
	}
}

void expand_map(char **map, int old_height)
{
	size_t old_size;
	size_t new_size;
	void *new_map;

	old_size = sizeof(char *) * (old_height);
	new_size = sizeof(char *) * (old_height + 2);
	new_map = ft_realloc(map, old_size , new_size );
	cube()->parse->map->map = new_map;
}

void alloc_space(bool valid)
{
	if (valid)
	{
		ft_putstr_fd("Error: wawawa\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	if (!cube()->parse->map->map)
		cube()->parse->map->map = gc_malloc(sizeof(char *) * 1);
	else
		expand_map(cube()->parse->map->map, cube()->parse->map->height);
	if (!cube()->parse->map->map)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
}
