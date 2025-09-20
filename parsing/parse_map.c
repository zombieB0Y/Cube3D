/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:21:05 by zm                #+#    #+#             */
/*   Updated: 2025/09/20 06:02:35 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	start_algo(t_cs *cs, int height, int width)
{
	while (!is_empty(&cs->q))
	{
		cs->curr = out_of_queue(&cs->q);
		cube()->parse->map->map[cs->curr.x][cs->curr.y] = 's';
		cs->i = 0;
		while (cs->i < 4)
		{
			cs->sx = cs->curr.x + cs->directions[cs->i].x;
			cs->sy = cs->curr.y + cs->directions[cs->i].y;
			if (cs->sx >= 0 && cs->sx < height && cs->sy >= 0 && cs->sy < width)
			{
				cs->c = cube()->parse->map->map[cs->sx][cs->sy];
				if (!cs->visited[cs->sx][cs->sy] && cs->c == ' ')
				{
					cs->visited[cs->sx][cs->sy] = true;
					cs->point.x = cs->sx;
					cs->point.y = cs->sy;
					add_in_queue(&cs->q, cs->point);
				}
			}
			cs->i++;
		}
	}
}

int	change_space(int X, int Y, int height, int width)
{
	t_cs	cs;

	cs.point.x = X;
	cs.point.y = Y;
	cs.i = 0;
	cs.directions = gc_malloc(sizeof(t_point) * 4);
	cs.visited = gc_malloc(sizeof(bool*) * (height));
	if (!cs.directions || !cs.visited)
		return (0);
	init_directions(cs.directions);
	while (cs.i < (height))
	{
		cs.visited[cs.i] = ft_calloc(width, sizeof(bool));
		if (!cs.visited[cs.i])
			return (0);
		cs.i++;
	}
	if (init_queue(&cs.q, (height * width)) == 0)
		return (0);
	add_in_queue(&cs.q, cs.point);
	cs.visited[X][Y] = true;
	start_algo(&cs, height, width);
	return (1);
}

void	checking_each_char(int i, int j, bool valid)
{
	char **map;

	map = cube()->parse->map->map;
	check_for_invalid_char(i, j);
	if (map[i][j] == '0')
		validate_surrounding(i, j, valid);
	else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
	{
		if (!cube()->parse->map->is_player_there)
			cube()->parse->map->is_player_there = true;
		else
		{
			ft_putstr_fd("Error: Only One Player\n", 2);
			gc_collect();
			exit(1);
		}
		valid = check_surrounding(map, i, j);
		if (!valid)
		{
			ft_putstr_fd("Error: Need a Valid Player Position\n", 2);
			gc_collect();
			exit(1);
		}
	}
}

void    map_parsing(void)
{
	int     i;
	int     j;
	bool    valid;

	i = 1;
	j = 1;
	valid = false;
	while (cube()->parse->map->map[i])
	{
		j = 1;
		while (cube()->parse->map->map[i][j])
		{
			if (cube()->parse->map->map[i][j] == 's')
			{
				j++;
				continue;
			}
			checking_each_char(i, j, valid);
			j++;
		}
		i++;
	}
	check_player();
}
