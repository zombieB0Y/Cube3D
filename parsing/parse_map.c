/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:21:05 by zm                #+#    #+#             */
/*   Updated: 2025/08/24 02:41:57 by zoentifi         ###   ########.fr       */
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
		return (false);//                   110 001         100 001
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
    t_point *directions;
    t_point point;
    t_point curr;
    int i;
    int sx;
    int sy;
    char c;
    t_queue q;
	bool **visited;
    point.x = X;
    point.y = Y;
	// norm habek !!
    i = 0;
	directions = gc_malloc(sizeof(t_point) * 4);
	visited = gc_malloc(sizeof(bool*) * (height));
	if (!directions || !visited)
		return (0);
    directions[0] = (t_point){0, 1};
    directions[1] = (t_point){1, 0};
    directions[2] = (t_point){0, -1};
    directions[3] = (t_point){-1, 0};
    while (i < (height))
    {
        visited[i] = ft_calloc(width, sizeof(bool));
        if (!visited[i])
            return (0);
        i++;
    }
    if (init_queue(&q, (height * width)) == 0)
        return (0);
    add_in_queue(&q, point);
    visited[X][Y] = true;
    
    while (!is_empty(&q))
    {
        curr = out_of_queue(&q);
        if (cube()->parse->map->map[curr.x][curr.y] == ' ')
            cube()->parse->map->map[curr.x][curr.y] = 's';
        
        i = 0;
        while (i < 4)
        {
            sx = curr.x + directions[i].x;
            sy = curr.y + directions[i].y;
            if (sx >= 0 && sx < height && sy >= 0 && sy < width)
            {
                c = cube()->parse->map->map[sx][sy];
                if (!visited[sx][sy] && c != '1' && c != '0' && 
                    c != 'N' && c != 'E' && c != 'W' && c != 'S')
                {
                    visited[sx][sy] = true;
                    point.x = sx;
                    point.y = sy;
                    add_in_queue(&q, point);
                }
            }
            i++;
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
					printf("Error: Invalid map structure at (%d, %d)\n", i, j);
					ft_putstr_fd("Error: Invalid map structure\n", 2);
					gc_collect();
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}
