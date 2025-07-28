/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:21:05 by zm                #+#    #+#             */
/*   Updated: 2025/07/28 16:20:48 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

bool	itiraite_foward(char **map, int i, int j)
{
	int width;

	width = ft_strlen(map[i]);
	if (i < 0 || i > cube()->parse->map->height || j < 0 || j > width)
		return (false);
	while (j <= width)
	{
		if (map[i][j] == '1')
		{
			return (true);
		}
		j++;
	}
	return (false);
}

bool	itiraite_backward(char **map, int i, int j)
{
	int width;

	width = ft_strlen(map[i]);
	if (i < 0 || i > cube()->parse->map->height || j < 0 || j > width)
		return (false);
	while (j >= 0)
	{
		if (map[i][j] == '1')
		{
			return (true);
		}
		j--;
	}
	return (false);
}

bool	itiraite_upward(char **map, int i, int j)
{
	int width;

	width = ft_strlen(map[i]);
	if (i < 0 || i > cube()->parse->map->height || j < 0 || j > width)
		return (false);//                   110 001         100 001

	while (i >= 0)
	{
		if (map[i][j] == '1')
		{
			return (true);
		}	
		i--;
	}
	return (false);
}

bool	itiraite_downward(char **map, int i, int j)
{
	int width;

	width = ft_strlen(map[i]);
	if (i < 0 || i > cube()->parse->map->height || j < 0 || j > width)
		return (false);
	while (i < cube()->parse->map->height)
	{
		if (map[i][j] == '1')
		{
			return (true);
		}	
		i++;
	}
	return (false);
}

bool	check_surrounding(char **map, int i, int j)
{
	if (itiraite_foward(map, i, j) && itiraite_backward(map, i, j) &&
		itiraite_upward(map, i, j) && itiraite_downward(map, i, j))
		return (true);
	else
		return (false);
}

void	convert_spaces(void)
{
	char	**map;
	int		x;
	int		y;

	map = cube()->parse->map->map;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == ' ')
			{
				map[x][y] = '2';
				y++;
				continue ;
			}
			if (ft_strchr("10NWES", map[x][y]))
			{
				while (map[x][y] && map[x][y] != '1')
					y++;
				continue ;
			}
			else
			{
				
			}
		}
	}
}

void    map_parsing(void)
{
	int     i;
	int     j;
	char    **map;
	bool    valid;

	i = 0;
	j = 0;
	map = cube()->parse->map->map;
	valid = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_isspace(map[i][j]))
			{
				j++;
				continue;
			}
			if (!ft_strchr("01NSEW", map[i][j]))
			{
				ft_putstr_fd("Error: Invalid character in map\n", 2);
				mlx_destroy_window(cube()->mlx->mlx, cube()->mlx->win);
				gc_collect();
				exit(1);
			}
			if (map[i][j] == '0')
			{
				valid = check_surrounding(map, i, j);
				if (!valid)
				{
					// printf("Invalid map structure at position (%d, %d) >> %c \n", i, j, map[i][j]);
					// printf("map width >> %d \n", cube()->parse->map->width);
					// printf("next position (%d, %d) >> %c \n", i, j + 1, map[i][j + 1]);
					ft_putstr_fd("Error: Invalid map structure\n", 2);
					mlx_destroy_window(cube()->mlx->mlx, cube()->mlx->win);
					gc_collect();
					exit(1);
				}
			}
			// else if (map[i][j] == 'N' || map[i][j] == 'S' ||
			// 	map[i][j] == 'E' || map[i][j] == 'W')
			j++;
		}
		i++;
	}
}
