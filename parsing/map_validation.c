/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 00:00:00 by zm                #+#    #+#             */
/*   Updated: 2025/09/20 05:25:50 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

bool	itiraite_foward(char **map, int i, int j)
{
	int width;

	width = ft_strlen(map[i]);
	if (i < 0 || i > cube()->parse->map->height || j < 0 || j > width)
		return (false);
	if (map[i][j + 1] == 's')
		return (false);
	return (true);
}

bool	itiraite_backward(char **map, int i, int j)
{
	int width;

	width = ft_strlen(map[i]);
	if (i < 0 || i > cube()->parse->map->height || j < 0 || j > width)
		return (false);
	if (map[i][j - 1] == 's')
		return (false);
	return (true);
}

bool	itiraite_upward(char **map, int i, int j)
{
	int width;

	width = ft_strlen(map[i]);
	if (i < 0 || i > cube()->parse->map->height || j < 0 || j > width)
		return (false);
	if (map[i - 1][j] == 's')
		return (false);
	return (true);
}

bool	itiraite_downward(char **map, int i, int j)
{
	int width;

	width = ft_strlen(map[i]);
	if (i < 0 || i > cube()->parse->map->height || j < 0 || j > width)
		return (false);
	if (map[i + 1][j] == 's')
		return (false);
	return (true);
}

bool	check_surrounding(char **map, int i, int j)
{
	if (itiraite_foward(map, i, j) && itiraite_backward(map, i, j) &&
		itiraite_upward(map, i, j) && itiraite_downward(map, i, j))
		return (true);
	else
		return (false);
}
