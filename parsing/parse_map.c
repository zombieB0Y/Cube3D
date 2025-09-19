/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:21:05 by zm                #+#    #+#             */
/*   Updated: 2025/09/19 21:18:40 by zm               ###   ########.fr       */
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

int init_queue(t_queue *q, int capacity)
{
	q->data = gc_malloc(capacity * sizeof(t_point));
	if (!q->data)
		return (0);
	q->front = 0;
	q->back = -1;
	q->capacity = capacity;
	return (1);
}

void add_in_queue(t_queue *q, t_point point)
{
	if (q->back == q->capacity - 1)
		return ;
	q->data[++q->back] = point;
}

t_point out_of_queue(t_queue *q)
{
	return (q->data[q->front++]);
}

int is_empty(t_queue *q)
{
	return (q->front > q->back);
}




int	change_space(int X, int Y, int height, int width)
{
	t_cs	cs;

	cs.point.x = X;
	cs.point.y = Y;
	// norm habek !!
	cs.i = 0;
	cs.directions = gc_malloc(sizeof(t_point) * 4);
	cs.visited = gc_malloc(sizeof(bool*) * (height));
	if (!cs.directions || !cs.visited)
		return (0);
	cs.directions[0] = (t_point){0, 1};
	cs.directions[1] = (t_point){1, 0};
	cs.directions[2] = (t_point){0, -1};
	cs.directions[3] = (t_point){-1, 0};
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
	
	while (!is_empty(&cs.q))
	{
		cs.curr = out_of_queue(&cs.q);
		if (cube()->parse->map->map[cs.curr.x][cs.curr.y] == ' ')
			cube()->parse->map->map[cs.curr.x][cs.curr.y] = 's';
		
		cs.i = 0;
		while (cs.i < 4)
		{
			cs.sx = cs.curr.x + cs.directions[cs.i].x;
			cs.sy = cs.curr.y + cs.directions[cs.i].y;
			if (cs.sx >= 0 && cs.sx < height && cs.sy >= 0 && cs.sy < width)
			{
				cs.c = cube()->parse->map->map[cs.sx][cs.sy];
				if (!cs.visited[cs.sx][cs.sy] && cs.c != '1' && cs.c != '0' && 
					cs.c != 'N' && cs.c != 'E' && cs.c != 'W' && cs.c != 'S')
				{
					cs.visited[cs.sx][cs.sy] = true;
					cs.point.x = cs.sx;
					cs.point.y = cs.sy;
					add_in_queue(&cs.q, cs.point);
				}
			}
			cs.i++;
		}
	}
	return (1);
}

void    map_parsing(void)
{
	int     i;
	int     j;
	char    **map;
	bool    valid;

	i = 1;
	j = 1;
	map = cube()->parse->map->map;
	valid = false;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 's')
			{
				j++;
				continue;
			}
			if (!ft_strchr("01NSEW ", map[i][j]))
			{
				ft_putstr_fd("Error: Invalid character in map\n", 2);
				gc_collect();
				exit(1);
			}
			if (map[i][j] == '0')
			{
				valid = check_surrounding(map, i, j);
				if (!valid)
				{
					ft_putstr_fd("Error: Invalid map structure\n", 2);
					gc_collect();
					exit(1);
				}
			}
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
			j++;
		}
		i++;
	}
	if (!cube()->parse->map->is_player_there)
	{
		ft_putstr_fd("Error: Need a Player\n", 2);
		gc_collect();
		exit(1);
	}
}
