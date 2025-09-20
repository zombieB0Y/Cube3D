/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:01:07 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/20 21:01:08 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_player(void)
{
	if (!cube()->parse->map->is_player_there)
	{
		ft_putstr_fd("Error: Need a Player\n", 2);
		gc_collect();
		exit(1);
	}
}

void	init_directions(t_point *directions)
{
	directions[0] = (t_point){0, 1};
	directions[1] = (t_point){1, 0};
	directions[2] = (t_point){0, -1};
	directions[3] = (t_point){-1, 0};
}

void	check_for_invalid_char(int i, int j)
{
	if (!ft_strchr("01NSEW ", cube()->parse->map->map[i][j]))
	{
		ft_putstr_fd("Error: Invalid character in map\n", 2);
		gc_collect();
		exit(1);
	}
}

void	validate_surrounding(int i, int j, bool valid)
{
	char **map;

	map = cube()->parse->map->map;
	valid = check_surrounding(map, i, j);
	if (!valid)
	{
		ft_putstr_fd("Error: Invalid map structure\n", 2);
		gc_collect();
		exit(1);
	}
}
