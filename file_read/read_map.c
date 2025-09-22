/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 00:00:00 by zm                #+#    #+#             */
/*   Updated: 2025/09/22 23:19:18 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	add_border(void)
{
	int		i;
	int		j;
	int		ni;
	int		nj;

	i = 0;
	init_new_map();
	j = 0;
	while (i < cube()->parse->map->height)
	{
		ni = i + 1;
		j = 0;
		while ((size_t)j < ft_strlen(cube()->parse->map->map[i]))
		{
			nj = j + 1;
			cube()->parse->new_map[ni][nj] = cube()->parse->map->map[i][j];
			j++;
		}
		i++;
	}
	cube()->parse->map->map = cube()->parse->new_map;
}

char	*get_tmp(void)
{
	while (1)
	{
		cube()->parse->tmp = get_next_line(cube()->fd);
		if (!cube()->parse->tmp)
			break ;
		if (!check_for_whitespace(cube()->parse->tmp))
			break ;
	}
	if (!cube()->parse->tmp)
	{
		ft_putstr_fd("Error: empty map file\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	return (cube()->parse->tmp);
}

void	check_for_valid_map(void)
{
	if (cube()->parse->map->height == 0 || cube()->parse->map->width == 0)
	{
		ft_putstr_fd("Error: empty map\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	add_border();
}

void	read_map(void)
{
	bool	valid;
	int		i;

	get_tmp();
	valid = false;
	while (1)
	{
		i = cube()->parse->map->height;
		init_line();
		if (!cube()->parse->line)
			break ;
		if (check_for_whitespace(cube()->parse->line))
		{
			valid = true;
			continue ;
		}
		alloc_space(valid);
		ft_memset(cube()->parse->line + ft_strlen(cube()->parse->line) - 1,
			'\0', 1);
		if (cube()->parse->map->width < (int)ft_strlen(cube()->parse->line))
			cube()->parse->map->width = ft_strlen(cube()->parse->line);
		cube()->parse->map->map[i] = cube()->parse->line;
		cube()->parse->map->height++;
	}
	check_for_valid_map();
}

void	print_map(void)
{
	int	i;

	i = 0;
	printf("Map:\n");
	while (i <  cube()->parse->map->height + 2)
	{
		printf("%s\n", cube()->parse->map->map[i]);
		i++;
	}
}
